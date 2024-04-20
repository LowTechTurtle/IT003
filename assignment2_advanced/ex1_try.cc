#include<bits/stdc++.h>
using namespace std;

vector<int> people;
vector<int> combination;
int sum = 0;

void pretty_print(const vector<int>& v) {
  static int count = 0;
//  cout << "combination no " << (++count) << ": [ ";
//  for (int i = 0; i < v.size(); ++i) { cout << v[i] << " "; }
//  cout << "] " << endl;
    sum += v[v.size()-1] - v[0];
}

void go(int offset, int k) {
  if (k == 0) {
    pretty_print(combination);
    return;
  }
  for (int i = offset; i <= people.size() - k; ++i) {
    combination.push_back(people[i]);
    go(i+1, k-1);
    combination.pop_back();
  }
}

int main() 
{
    int n, k, temp;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        people.push_back(temp); 
    }
    sort(people.begin(), people.end());

    go(0, k);
    cout << sum << endl;

    return 0;
}
