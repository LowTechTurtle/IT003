#include<bits/stdc++.h>
using namespace std;

int main() 
{
    string s;
    cin >> s;
    int x[10] = {0};
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        x[(int)s[i] - 48] += 1;
        count += (int)s[i] - 48;
    }

    int rc = 0;
    if (count % 3 == 1) {
        for (int i = 0; i < 10; i++) {
            if (i % 3 == 1 && x[i] > 0) {
                x[i]--;
                rc = 1;
                break;
            }
        }
        if (rc == 0) {
            for (int i = 0; i < 10; i++) {
                if (i % 3 == 2 && x[i] > 0) {
                    x[i]--;
                    break;
                }
            }
            for (int i = 0; i < 10; i++) {
                if (i % 3 == 2 && x[i] > 0) {
                    x[i]--;
                    break;
                }
            }
        }
    } else if (count % 3 == 2) {
        rc = 0;
        for (int i = 0; i < 10; i++) {
            if (i % 3 == 2 && x[i] > 0) {
                x[i]--;
                rc = 1;
                break;
            }
        }
        if (rc == 0) {
            for (int i = 0; i < 10; i++) {
                if (i % 3 == 1 && x[i] > 0) {
                    x[i]--;
                    break;
                }
            }
            for (int i = 0; i < 10; i++) {
                if (i % 3 == 1 && x[i] > 0) {
                    x[i]--;
                    break;
                }
            }
        }
    }

    for (int i = 9; i >= 0 ; i--) {
        for (int j = 0; j < x[i]; j++) {
            cout << i;
        }
    }
    cout << endl;
    return 0    ;

}