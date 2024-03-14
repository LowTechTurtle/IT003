#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, max;
    cin >> n;
    cin >> max;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = -1;

    int lo, hi, mid;
    sort(a, a+n);
    for (int i = n-1; i > 0; i--) {
        lo = 0;
        hi = n - 2;
        while (lo <= hi) {
            mid = (lo + hi) / 2;

            if ((a[mid] + a[i] <= max)) {
                if (mid < i) {
                    if (a[mid] + a[i] > ans)
                        ans = a[mid] + a[i];
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            } else {
                hi = mid - 1;
            }
        }
    }
    cout << ans;
    return 0;
}