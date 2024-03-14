#include<bits/stdc++.h>
using namespace std;

int main() 
{
#define int long long int
    int n, k;
    cin >> n;
    cin >> k;
    int a[n];
    int b[n];
    int ans[k];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int count = 1;
    int j = 0;
    int temp = a[0];
    ans[0] = a[0];
    for (int i = 1; i < n; i++) {
        //cout << i << " " << a[i]<< endl;
        if (a[i] != temp && count <= k ) {
            ans[count] = a[i];
            count++;
            temp = a[i];
        } else if (a[i] == temp) {
            //cout << a[i] << endl;
            b[j] = a[i];
            j++;
        }
    }

    int it = 0;
    for (int i = 0; i < j; i++) {
        //cout << b[i] << " ";
    }
    //cout << endl;
    for (int i = count; i < k; i++){
        ans[count] = b[it];
        count++;
        it++;
    }
    sort(ans, ans+k);
    for (int i = 0; i < k; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}