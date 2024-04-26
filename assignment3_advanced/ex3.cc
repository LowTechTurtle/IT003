#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q, rc;
    cin >> n;
    cin >> m;
    cin >> q;
    string A[n], sub;
    string S[m];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            S[j] += A[i][j];
        }
    }

    for (int t = 0; t < q; t++) {
        cin >> sub;
        rc = 0;
        for (int i = 0; i < n; i++) {
            if (A[i].find(sub) != string::npos) {
                rc = 1;
                cout << 1;
                break;
            }
        }
        if (rc == 0) {
            for (int i = 0; i < m; i++) {
                if (S[i].find(sub) != string::npos) {
                    cout << 1;
                    rc = 1;
                    break;
                }
            }
        }
        if (rc == 0)
            cout << 0;
    }

    return 0;
}