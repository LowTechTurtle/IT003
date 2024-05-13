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

int main() 
{
    int n;
    cin >> n;
    unsigned char x;
    vector<pair<unsigned char, int>> v;
    map<unsigned char, string> m;
    vector<unsigned char> vc;
    int arr[256] = {0};

    for (int i = 0; i < n; i++) {
        cin >> x;
        vc.push_back(x);
        arr[x] += 1;
    }

    for (int i = 0; i < 256; i++) {
        if (arr[i] > 0) {
            pair<unsigned char, int> p(i, arr[i]);
            v.push_back(p);
        }
    }

//    for (auto it = v.begin(); it < v.end(); it++) {
//        cout << it -> first << " " << it -> second << endl;
//    }

    Tree* T = BuildTree(v);
    TraverseHuffmanTree(T, "", "", m);
    int res = 0;
    for (auto c: vc) {
        res += m[c].length();
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it -> first << " map to " << it -> second << endl;
    }
    if (res == 0) {
        cout << n;
        return 0;
    }
    cout << res << endl;
    return 0;
}