#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> v;
    string s;
    getline(cin, s);
    for (char x: s) {
        if ((int)x == '{') {
            v.push_back('{');
        } else if ((int)x == '}') {
            if (v.size() == 0) {
                cout << 0 << endl;
                return 0;
            }
            if (v[v.size()-1] == '{')
                v.pop_back(); 
        } else if ((int)x == '(') {
            v.push_back('(');
        } else if ((int)x == ')') {
            if (v.size() == 0) {
                cout << 0 << endl;
                return 0;
            }
            if (v.size() > 0 && v[v.size()-1] == '(')
                v.pop_back(); 
        } else if ((int)x == '[') {
            v.push_back('[');
        } else if ((int)x == ']') {
            if (v.size() == 0) {
                cout << 0 << endl;
                return 0;
            }
            if (v.size() > 0 && v[v.size()-1] == '[')
                v.pop_back(); 
        }
    }

    if (v.size() == 0) {
        cout << 1 << endl;
	    return 0;
    }  

    cout << 0 << endl;
    return 0;
}
