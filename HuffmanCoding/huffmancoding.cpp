#include<bits/stdc++.h>
using namespace std;

struct Tree
{
    int f; // frequency of the character in this node
    unsigned char c; //character
    Tree *left = NULL;
    Tree *right = NULL;
};

class CompareTree
{
    public:
        bool operator() (Tree *tree1, Tree *tree2) {
            return tree1 -> f > tree2 -> f;
        }
};

//Build Tree based on a table of character and frequency of that character
Tree *BuildTree(vector<pair<unsigned char, int>> f_table) 
{
    //This should be a heap but a priority queue provide getting min items at complexity of log(n) so it should be ok 
    priority_queue<Tree*, vector<Tree*>, CompareTree> queue;

    for (int i = 0; i < f_table.size(); i++)
    {
        Tree *node = new Tree();
        node->f = f_table[i].second;
        node->c = f_table[i].first;
        
        queue.push(node);
    }

    

    while (queue.size() > 1)
    {
        Tree *a, *b;
        a = queue.top();
        queue.pop();
        
        b = queue.top();
        queue.pop();
        
        //merge two node into one, this will increase average leaf depth
        Tree *c = new Tree();
        c->f = a->f + b->f;
        c->left = a;
        c->right = b;
        queue.push(c);
    }
    //return the root of the tree
    return queue.top();
}

//turn a character into its binary representation
string ToBinary(unsigned char a)
{
    string output  = "";
    while (a != 0)
    {
        string bit = a%2 == 0? "0" : "1";
        output += bit;
        a /= 2;
    }

    if (output.size() < 8)
    {
        int d = 8 - output.size();
        for (int i = 0; i < d; i++)
        {
            output += "0";
        }
    }

    reverse(output.begin(), output.end());
    return output;
    
}

//traverse the tree and get the binary representation of huffman codes for each character in Huffman tree
void TraverseHuffmanTree(Tree *root, string prev, string toAppend, map<unsigned char, string> &codemap)
{

    prev += toAppend;
    
    if (root->right == NULL && root->left == NULL) 
        codemap[root->c] = prev;
    
    if (root->right != NULL) 
        TraverseHuffmanTree(root->right, prev, "1", codemap);

    if (root->left != NULL) 
        TraverseHuffmanTree(root->left, prev, "0", codemap);
    
}

//read the entire fire into the buffer
unsigned char *ReadFileIntoBuffer(char *path, int &sz)
{
    FILE *fp = fopen(path, "rb");

//get the size of file
    sz = 0;
    fseek(fp, 0, SEEK_END);
    sz = ftell(fp);

//back to the beginning of the file
    fseek(fp, 0, SEEK_SET);
    unsigned char *buffer = (unsigned char *)malloc(sz);
    fread(buffer, 1, sz, fp);
    return buffer;
}    

//write the entire buffer to an output file
//if flag is not 0 we will append new text to file
void WriteFileFromBuffer(char *path, unsigned char *buffer, int sz, int flag)
{
    FILE *fp;

    if(flag==0)
        fp = fopen(path, "wb");
    else
        fp = fopen(path, "ab");
   
    fwrite(buffer, 1, sz, fp);

    fclose(fp);
}

//from the input table of huffman code, convert it to a vector
vector<pair<unsigned char, int> > ConvertToVector(map<unsigned char, int> codes)
{
    vector<pair<unsigned char, int> > codesV;

    for (map<unsigned char, int>::iterator i = codes.begin(); i != codes.end(); i++)
    {
        codesV.push_back(make_pair(i->first, i->second));
    }

    return codesV;
}

//from huffman codes table and a buffer read from input, get a output string(but in bit so it need more processing)
string GetHuffmanBitstring(unsigned char *buffer, map<unsigned char, string> codes, int sz, int& pad)
{
    string out = "";
    for (int i = 0; i < sz; i++)
    {
        out = out + codes[buffer[i]];
    }

//because each character is 8 bytes, so we need to pad some 0s to make sure that the number of bits is divisible for 8
    if (out.size() % 8 != 0)
    {
        int d = 8*((out.size() / 8) + 1) - out.size();
        pad = d;
        for( int i = 0; i < d; i++)
        {
            out += "0";
        }
    }

    return out;
}

//get the bitstring from the above function, turn it into actual unsigned character that can be written into files, return the buffers
unsigned char* GetBufferFromString(string bitstring, vector<unsigned char>&outputBuffer, int& sz)
{
    int j = 0;
    unsigned char bit = 0;

    for (int i = 0; i < sz; i++)
    {
         bit = (bit << 1) | (bitstring[i]-'0');
         
        j++;
        if (j == 8)
        {
            j = 0;
            outputBuffer.push_back(bit);
            bit = 0;
        
        }   
    }
    sz = outputBuffer.size();
    return outputBuffer.data();
}

//this is used for decoding, from a arbitrary character in encoded file, get a bitstring from these character
string GetStringFromBuffer(unsigned char* buffer, int sz)
{
    string bitstring = ""; 
    for (int i = 0; i < sz; i++)
    {
        bitstring += ToBinary(buffer[i]);
    }

    return bitstring;
}

//from the bit string above, get the decoded string into buffer
unsigned char* GetDecodedBuffer(string bitstring, vector<unsigned char>&buffer, map<unsigned char, string> codes, int &sz, int pad)
{
    string bit = "";
    map<string, unsigned char> reversecodes;
    
    for(map<unsigned char, string>::iterator i = codes.begin(); i!=codes.end(); i++)
    {
        reversecodes[i->second] = i->first;
    }

    for (int i = 0; i < bitstring.size() - pad; i++)
    {
        bit += string(1, bitstring[i]);
        if (reversecodes.find(bit) != reversecodes.end())
        {
           buffer.push_back(reversecodes[bit]);
           bit = "";
        }
    }

    sz = buffer.size();
    return buffer.data();
}

//we need to save information about tree to the encoded file so that we can decode it
void WriteHeader(char* path, map<unsigned char, string> codes, int pad){
    
    int size = codes.size();
    WriteFileFromBuffer(path, (unsigned char*)&pad, sizeof(int), 0);
    WriteFileFromBuffer(path, (unsigned char*)&size, sizeof(int), 1);

    unsigned char nullBit = '\0';

    for (map<unsigned char, string>::iterator i = codes.begin(); i != codes.end(); i++)
    {
        WriteFileFromBuffer(path, (unsigned char*)&i->first, 1, 1);
        int len = i->second.size();
        WriteFileFromBuffer(path, (unsigned char*)&len, sizeof(int), 1);
        WriteFileFromBuffer(path, (unsigned char*)i->second.c_str(), i->second.size(), 1);
    }
}

//when decode a file, first need to read the header to get infomation about padded bits and length of codes, bits in codes
unsigned char* ReadHeader(unsigned char* buffer, map<unsigned char, string> &codes, int& pad, int &sz)
{
   pad = *((int*)buffer);
   buffer = buffer+4;
   sz-=4;
   int size = *((int*)buffer);
   buffer = buffer+4;
   sz-=4;
   for (int i = 0; i < size; i++)
   {    
       unsigned char key = buffer[0];
       buffer++;
       sz--;
       int len = *((int*)buffer);
       buffer += 4;
       sz -= 4;
       char* value = (char*)malloc(len+1);

       for (int j = 0; j < len; j++)
       {
           value[j] = buffer[j];
       }
       buffer += len;
       sz -= len;
       value[len] = '\0';
       codes[key] = value;
   }

   return buffer;
}

//Compress the file
void CompressFile(char *path, char *output_path, map<unsigned char, string> &codes)
{
    int sz = 0;
    int pad = 0;
    map<unsigned char, int> f_table;

//first read the original file into buffer
    unsigned char *buffer = ReadFileIntoBuffer(path, sz);

    for (int i = 0; i < sz; i++)
    {
            f_table[buffer[i]]++;
    }

//build huffman tree
    Tree *root = BuildTree(ConvertToVector(f_table));
//get the character to bitstring map
    TraverseHuffmanTree(root, "", "", codes);
//get bitstring
    string outputString = GetHuffmanBitstring(buffer, codes, sz, pad);
    sz  = outputString.size();
//get buffer to write from the above bitstring
    vector<unsigned char> outputBufferV;
    GetBufferFromString(outputString, outputBufferV, sz);
    unsigned char* outputBuffer = outputBufferV.data();
//write header and write buffer to output file
    WriteHeader(output_path, codes, pad);
    WriteFileFromBuffer(output_path, outputBuffer, sz, 1);
}

//decompress a file
void DecompressFile(char* inputPath, char* outputPath)
{
    int sz = 0;
    map<unsigned char, string> codes;
    int pad = 0;

//get buffer from input file
    unsigned char* fileBuffer = ReadFileIntoBuffer(inputPath, sz);
//read header to get infomation about huffman codes and padded bits
    fileBuffer = ReadHeader(fileBuffer, codes, pad, sz);
//get bitstring from the buffer
    string fileBitString = GetStringFromBuffer(fileBuffer, sz);
    vector<unsigned char> outputBufferV;
    unsigned char* outputBuffer;
//get decoded buffer and write it to destination file
    GetDecodedBuffer(fileBitString,outputBufferV, codes, sz, pad);
    outputBuffer = outputBufferV.data();
    WriteFileFromBuffer(outputPath, outputBuffer,sz, 0);
}


int main(int argc, char* argv[])
{   
    if (argc == 4 && (strcmp(argv[1], "--compress") == 0 || strcmp(argv[1], "-c") == 0)) {
        map<unsigned char, string> codes;
        CompressFile(argv[2], argv[3], codes);
    } else if (argc == 4 && (strcmp(argv[1], "--decompress") == 0 || strcmp(argv[1], "-d") == 0)) {
        DecompressFile(argv[2], argv[3]);
    } else {
        cout << "Usage: ./executable --compress input_path output_path" << endl;
        cout << "Usage: ./executable --decompress input_path output_path" << endl;
    }
    return 0;
}
