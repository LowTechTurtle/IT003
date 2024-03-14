#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        long long int a[n];
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        sort(a, a+n);
        if (n == 2) {
            cout << a[1] - a[0] << endl;
        } else if (n == 3) {
            cout << a[2] - a[0] << endl;
        } else {
            cout << a[n-1] + a[n-2] - a[0] - a[1] << endl;
        }
    }
    return 0;
}