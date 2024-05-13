#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    priority_queue<long long int, vector<long long int> ,greater<long long int>> q;
    long long int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> m;
        q.push(m);
    }

    long long int res = 0;
    while (q.size() > 1) {
        m = q.top();
        q.pop();
        m += q.top();
        q.pop();
        res += m;
        q.push(m);
    }

    cout << res << endl;
    return 0;
}