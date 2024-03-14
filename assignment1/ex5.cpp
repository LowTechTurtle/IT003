#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int k;
    cin >> k;
    k = k % 26;
    string s;
    cin.ignore(); 
    getline(cin, s);
    string ans = "";
    char y;
    for (auto x: s) {
        y = x + k;
        if (y > 90) {
            y -= 26;
        }
        if (x == 32) {
            ans.push_back(x);
        } else {
            ans.push_back(y);
        }
    }
    cout << ans << endl;
    return 0;
}