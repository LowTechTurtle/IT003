#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s, t;
    cin >> s >> t;
    map<string, string> m;
    string x, y;
    for (int i = 0; i < s; i++) {
        cin >> x;
        cin >> y;
        m[x] = y;
    }

    for (int i = 0; i < t; i++) {
        cin >> x;
        if (m.find(x) != m.end()) {
            cout << m[x] << "\n";
	} else {
            cout << "Chua Dang Ky!\n";
	}
    }

    return 0;
}
