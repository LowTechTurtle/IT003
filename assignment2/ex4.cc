#include<bits/stdc++.h>
using namespace std;

void quickSort(long long int arr[], long long int start, long long int end);
long long int partition(long long int arr[], long long int start, long long int end);

int main()
{
#define int long long
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	quickSort(A, 0, n-1);
	int min = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] > min) {
			cout << min << endl;
			return 0;
		}
		min++;
	}
    cout << min;
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

