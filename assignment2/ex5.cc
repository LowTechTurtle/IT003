#include<bits/stdc++.h>
using namespace std;

void quickSort(long long int arr1[], long long int arr2[], long long int start, long long int end);
long long int partition(long long int arr1[], long long int arr2[], long long int start, long long int end);

int main()
{
#define int long long
	int n;
	cin >> n;
	int A[n];
	int B[n];
	
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
	}
	quickSort(A, B, 0, n-1);

	int swp = 1;
	while (swp == 1) {
		swp = 0;
		for (int i = 0; i < n - 1; i++) {
			if (A[i] > A[i+1]) {
				swap(A[i], A[i+1]);
				swap(B[i], B[i+1]);
				swp = 1;
			} else if (A[i] == A[i+1]) {
				if (B[i] < B[i+1]) {
					swap(A[i], A[i+1]);
					swap(B[i], B[i+1]);
					swp = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << A[i] << " " << B[i] << "\n";
	}
	return 0;
}

int partition(int arr1[], int arr2[], int start, int end)
{

	int pivot = arr1[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr1[i] <= pivot)
			count++;
	}
	int pivotIndex = start + count;
	swap(arr1[pivotIndex], arr1[start]);
	swap(arr2[pivotIndex], arr2[start]);
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr1[i] <= pivot) {
			i++;
		}

		while (arr1[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr1[i], arr1[j]);
			swap(arr2[i], arr2[j]);
			i++;
			j--;
		}
	}

	return pivotIndex;
}

void quickSort(int arr1[], int arr2[] , int start, int end)
{
	if (start >= end)
		return;

	int p = partition(arr1, arr2, start, end);
	quickSort(arr1, arr2, start, p - 1);
	quickSort(arr1, arr2, p + 1, end);
}