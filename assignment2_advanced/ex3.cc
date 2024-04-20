#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s, t;
    cin >> s >> t;
    map<string, vector<string>> m;
    string x, y;
    for (int i = 0; i < s; i++) {
        cin >> x;
        cin >> y;
        m[x].push_back(y);
    }

    vector<string>::iterator ptr;
    for (int i = 0; i < t; i++) {
        cin >> x;
        if (m.find(x) != m.end()) {
            for (ptr = m[x].begin(); ptr < m[x].end(); ptr++) {
                cout << *ptr << " ";
            }
            cout << "\n";
	} else {
            cout << "Chua Dang Ky!\n";
	}
    }

    return 0;
}
