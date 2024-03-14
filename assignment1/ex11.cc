#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, rc, count = 0;
    int index[] = {0};
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;

    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            rc = 1;
            index[count] = i;
            count += 1;
        }
    }
    cout << count << endl;
    if (rc) {
        for (int i = 0; i < count; i++) 
            cout << index[i] << " " << index[i] + 1 << "\n";
    } else {
        cout << rc << endl;
    }
    return 0;
}