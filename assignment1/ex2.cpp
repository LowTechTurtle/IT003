#include<bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    if (a.first < b.first) {
        return true;
    } else if (a.first == b.first) {
        return (a.second > b.second);
    } else {
        return false;
    }
}

int main()
{
    int n;
    cin >> n;
    int x[n];
    int y[n];
    for (int i = 0; i < n; i++) {
	    cin >> x[i];
	    cin >> y[i];
    }
    vector< pair <int,int> > vect;

    for (int i=0; i<n; i++)
        vect.push_back( make_pair(x[i],y[i]) );

    sort(vect.begin(), vect.end(), sortbysec);
    for (int i=0; i<n; i++) {
        cout << vect[i].first << " "
             << vect[i].second << "\n";
    }
    return 0;
}
