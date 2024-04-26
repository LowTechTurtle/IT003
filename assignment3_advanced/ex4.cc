#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, temp;
    cin >> n;
    cin >> m;

    if (n <= 10000) {
        vector<int> v;

        for (int i = n; i > 0; i--) {
            v.push_back(i);
        }
        for (int i = 0; i < m; i++) {
            cin >> temp;
            auto it = find(v.begin(), v.end(), temp);
            v.erase(it);
            v.push_back(temp);
            cout << v[0] << " ";
        }
        return 0;
    }

    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        cin >> temp;
        a[temp-1] = -1;
        for (int j = n - 1; j >= 0; j--) {
            if (a[j] != -1) {
                cout <<  a[j] << " ";
                break;
            }
        }
    }
    return 0;
}