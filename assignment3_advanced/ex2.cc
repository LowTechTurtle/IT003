#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[], int n, int T) {
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (a[m] < T) {
            lo = m+1;
        } else if (a[m] > T) {
            hi = m - 1;
        } else {
            return m;
        }
    }
    return INT_MAX;
}
 
void quickerSort(int arr[], int lo, int hi) {
    if (hi - lo < 1) {
        return;
    }
    int pivot = rand()%(hi-lo + 1) + lo;
    swap(arr[lo], arr[pivot]);
    int i = lo + 1;
    int j = lo + 1;
    while (j <= hi) {
        if (arr[j] < arr[lo]) {
            swap(arr[j], arr[i]);
            i++;
        }
        j++;
    }
    swap(arr[lo], arr[i-1]);
    quickerSort(arr, lo, i-2);
    quickerSort(arr, i, hi);
}

int main()
{
    int n, q, t, x;
    cin >> n;
    cin >> q;
    string temp;
    int a[n];
    int b[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    quickerSort(b, 0, n - 1);

    for (int i = 0; i < q; i++) {
        cin >> temp;
        cin >> t;
        cin >> x;
        if (binary_search(b, n, x) == INT_MAX) {
            cout << -1 << "\n";
            continue;
        }
        if (t == 1) {
            for (int j = 0; j < n; j++) {
                if (a[j] == x) {
                    cout << j + 1 << "\n";
                    break;
                }
            }
        } else if (t == 2) 
            for (int j = n - 1; j >= 0; j--) {
                if (a[j] == x) {
                    cout << j + 1 << "\n";
                    break;
                }
            }
    }
    return 0;
}