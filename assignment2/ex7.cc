#include<bits/stdc++.h>
using namespace std;

void quickSort(long long int arr[], long long int start, long long int end);
long long int partition(long long int arr[], long long int start, long long int end);

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
    quickSort(a, 0, n-1);
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
    //quickSort(ans, 0, k-1);
    for (int i = 0; i < k; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
	if (start >= end)
		return;

	int p = partition(arr, start, end);
	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
}

