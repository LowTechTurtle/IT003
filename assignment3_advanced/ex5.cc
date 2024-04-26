#include<bits/stdc++.h>
using namespace std;

void sortmap(map<int, int>& M)
{
    multimap<int, int> MM;
    for (auto& it : M) {
        MM.insert({ it.second, it.first });
    }
    for (auto& it : MM) {
        cout << it.second << ' ';
    }
}

int main()
{
    int n, m, temp;
    cin >> n;
    cin >> m;
    int a[n];

    int j = INT_MAX - 1;
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        a[i] = i+1;
    }

    for (int i = 0; i < m; i++) {
        cin >> temp;
        a[temp-1] = -1;
        mp[temp] = j;
        j--;
    }

    sortmap(mp);

    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            cout << a[i] << " ";
        }
    }

    return 0;
}