#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k, p, q;
	cin >> n >> k >> p >> q;
	int u, v, rc = 0;

	if ((p-1)*2 + q - 1 >= k) {
		u = p - k/2;
		v = q - (k%2);
		if (v == 0) {
			u -= 1;
			v = 2;
		}
		rc = 1;
	} else {
		u = p + k/2;
		v = (q+ k%2);
		if (v == 3) {
			v = 1;
			u += 1;
		}
		if (u*2 - (v-1) < n || u*2 - (v-1) == n + 1)
			rc = 1;
	}

	if (rc)
		cout << u << " " << v << endl;
	else 
		cout << -1 << endl;

	return 0;
}
