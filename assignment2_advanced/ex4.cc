#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str,sub; // str is string to search, sub is the substring to search for
    cin >> str >> sub;

    vector<size_t> positions; // holds all the positions that sub occurs within str

    size_t pos = str.find(sub, 0);
    while(pos != string::npos) {
        positions.push_back(pos);
        pos = str.find(sub,pos+1);
    }

    vector<size_t>::iterator ptr;
    if (positions.size() > 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        return 0;
    }
    for (ptr = positions.begin(); ptr < positions.end(); ptr++) {
        cout << *ptr + 1 << " ";
    }
    return 0;
}
