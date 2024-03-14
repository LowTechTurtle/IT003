#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int n, m;
    cin >> n;
    cin >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = INT_MAX;
    int x;
    for (int i = 0; i < n-2; i++) {
        for (int j = 0; j < m-2; j++) {
            x = a[i][j] + a[i+1][j] + a[i+2][j]
            + a[i][j+1] + a[i+1][j+1] + a[i+2][j+1]
            + a[i][j+2] + a[i+1][j+2] + a[i+2][j+2];

            if (x < ans) {
                ans = x;
            }
        }
    }

    cout << ans << endl;

    return 0;
}