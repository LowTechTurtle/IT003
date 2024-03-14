#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string a[n];
    string x;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;

    int lo = 0;
    int hi = n - 1;
    int count = 0;
    int mid, rc = 0;
    while (lo <= hi) {
        mid = (lo+hi)/2;
        count += 1;
        if (a[mid] < x) {
            lo = mid + 1;
        } else if (a[mid] > x) {
            hi = mid - 1;
        } else {
            rc = 1;
            break;
        }
    }
    if (rc == 1) {
        cout << mid << endl;
        cout << count << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}