#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;


vector<int> get_ans(const vector<int>& A,int K){
	map<int,int> Hash;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		if (Hash.find(a[i]) == Hash.end()) {
			Hash[a[i]] = 1;
		} else {
			Hash[a[i]] += 1;
		}
	}

	for (auto it = Hash.begin(); it != Hash.end(); it++) {
		if (K > 0) {
			Hash[it->first] -= 1;
			cout << it -> first << " ";
			K -= 1;
		}
		else
			return v;
	}

	for (auto it = Hash.begin(); it != Hash.end(); it++) {
		for (int i = 0; i < it -> second; i++) {
			if (K > 0) {
				cout << it -> first << " ";
				K -= 1;
			}
			else
				return v;
		}
	}
	return v;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n >> k;
	
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> ans = get_ans(a,k);
	
	for (const int& x: ans) cout << x << ' ';
	return 0;
}
