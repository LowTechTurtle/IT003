#include<bits/stdc++.h>
using namespace std;
 
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n+1);

	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		v[x]++;
	}

	int solo=0, duo=0;
	for(int i=1; i<=n; i++) {
		if(v[i]==1) 
            solo++;
		else if(v[i]>1) 
            duo++;
	}

	(solo+duo*2>=2*k && solo+duo<=2*k)?cout << "YES\n":cout << "NO\n";
}

int main()
{
	int t; 
    cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}