#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, rc = 0;
    int index = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;

    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            rc = 1;
            index = i;
        }
    }
    if (rc == 1) {
        cout << index << "\n" << index + 1 << "\n" << n - index - 1 << "\n" << n - index << endl;
    } else {
        cout << -1 << endl;
    }
}