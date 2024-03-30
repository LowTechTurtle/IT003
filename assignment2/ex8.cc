#include<bits/stdc++.h>
using namespace std;

int partition(string arr[], int start, int end)
{

	string pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
        if (arr[i].compare(pivot) <= 0)
			count++;
	}
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i].compare(pivot) <= 0) {
			i++;
		}

		while (arr[j].compare(pivot) > 0) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(string arr[], int start, int end)
{
	if (start >= end)
		return;

	int p = partition(arr, start, end);
	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
}

int main()
{
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    quickSort(s, 0, n-1);
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (s[i].compare(s[i-1]) != 0) {
            count++;
        }
    }
    cout << count << endl;
    
}