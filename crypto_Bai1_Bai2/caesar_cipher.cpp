#include<bits/stdc++.h>
using namespace std;

string CaesarCipher_encypt(string txt, int shift) {
    string res = "";

    for (int i = 0; i < txt.length(); i++) {
        if (int(txt[i]) == 32) {
            res += " ";
            continue;
        }
        if (isupper(txt[i])) {
            res += char(int(txt[i] + shift - 65) % 26 + 65);
        }
        else {
            res += char(int(txt[i] + shift - 97) % 26 + 97);
        }
    }
 
    return res;
}

int main()
{
    cout << "Do you want to encrypt text or decrypt text?" << endl;
    cout << "1.Encrypt\n2.Decrypt\n3.Decrypt(output only the most promising result)\n>";
    string prompt;
    getline(cin, prompt);
    if (prompt == "1" || prompt == "Encrypt" || prompt == "encrypt") {
        string txt;
        int shift;
        getline(cin, txt);
        cin >> shift;

        cout << CaesarCipher_encypt(txt, shift) << endl;
    } else if (prompt == "2" || prompt == "Decrypt" || prompt == "decrypt") {
        string txt;
        getline(cin, txt);

        cout << "All possible base text is:\n";
        for (int i = 1; i < 26; i++) {
            cout << CaesarCipher_encypt(txt, i) << endl;
        }
    } else if (prompt == "3") {
        int max = -1;
        int max_i;
        vector<string> words;
        string line, res;
//        ifstream file("/usr/share/dict/words");
        ifstream file("words");

        while (!file.eof()) {
        getline(file, line);
        words.push_back(line);
        }

        string txt;
        getline(cin, txt);

        for (int i = 1; i < 26; i++) {
            int count = 0;
            res = CaesarCipher_encypt(txt, i);

            string word = "";
            for (auto x : res) {
                if (x == ' ') {
                    if (find(words.begin(), words.end(), word) != words.end()) {
                        count += 1;
                    }
                    word = "";
                }
                else {
                    word = word + x;
                }
            }
            if (count > max) {
                max = count;
                max_i = i;
            }
        }
        cout << CaesarCipher_encypt(txt, max_i) << endl;
    }
}
