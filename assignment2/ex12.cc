// C++ program for implementation of 
// selection sort 
#include <bits/stdc++.h> 
using namespace std; 


void printArray(long long int arr[], long long int size) 
{ 
	long long int i; 
	for (i = 0; i < size; i++) { 
		cout << arr[i] << " "; 
	} 
	cout << endl; 
} 

void selectionSort(long long int arr[], long long int n) 
{ 
	long long int i, j, min_idx; 
	for (i = 0; i < n - 1; i++) { 

		min_idx = i; 
		for (j = i + 1; j < n; j++) { 
			if (arr[j] < arr[min_idx]) 
				min_idx = j; 
		} 
		if (min_idx != i) {
			swap(arr[min_idx], arr[i]); 
			printArray(arr, n);
		}

	} 
} 
int main() {
    long long int n;
    cin >> n;
    long long int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    selectionSort(arr, n);
    return 0;
}
