#include<bits/stdc++.h>
using namespace std;

long long int com(long long int n, long long int r) {
    long double sum = 1;

    for (int i = 1; i <= r; i++) {
        sum = sum * (n - r + i) / i;
    }
    return sum;
}

int main() 
{
#define int long long
    int n, temp;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    int res = 0;
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i-1]) {
            count += 1;
            i++;
            while (i < n && v[i] == v[i-1]) {
                i++;
                count++;
            }
//            cout << count << " count be4" << endl;
//            cout << (lower_bound(v.begin(), v.end(), 2*v[i-1]) - v.begin()) << endl;
            res += com(count, 2) * ((lower_bound(v.begin(), v.end(), 2*v[i-1]) - v.begin()) - count);
//            cout << res << endl;
            if (count >= 3) {
                res += com(count, 3);
//                cout << res << endl;
            }
            count = 1;
        }
    }

    cout << res << endl;
    return 0;
}