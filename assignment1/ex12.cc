#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], b[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = 0;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        b[a[i]] = 1;
        while (b[j] == 1) {
            j++;
        }
        cout << j << " ";
    }
    return 0;
}