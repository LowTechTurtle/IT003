#include <bits/stdc++.h>
using namespace std;

int comparestring(string s1, string s2) {
	if (s1.size() < s2.size()) {
		return -1;
	} else if (s1.size() > s2.size()) {
		return 1;
	} else {
		return s1.compare(s2);
	}
}

int partition2(int arr1[], string arr2[], int start, int end)
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

void quickSort2(int arr1[], string arr2[], int start, int end)
{
	if (start >= end)
		return;

	int p = partition2(arr1, arr2, start, end);
	quickSort2(arr1, arr2, start, p - 1);
	quickSort2(arr1, arr2, p + 1, end);

}


int partition(string arr[], int start, int end)
{
    string pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (comparestring(arr[i], pivot) <= 0)
            count++;
    }
 
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (comparestring(arr[i], pivot) <= 0) {
            i++;
        }
 
        while (comparestring(arr[j], pivot) > 0) {
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

void quickerSort2(int arr1[], string arr2[], int lo, int hi) {
    if (hi - lo < 1) {
        return;
    }
    int pivot = rand()%(hi-lo + 1) + lo;
    swap(arr1[lo], arr1[pivot]);
    swap(arr2[lo], arr2[pivot]);
    int i = lo + 1;
    int j = lo + 1;
    while (j <= hi) {
        if (arr1[j] > arr1[lo]) {
            swap(arr1[j], arr1[i]);
            swap(arr2[j], arr2[i]);
            i++;
        } else if ((arr1[j] == arr1[lo]) && (comparestring(arr2[j], arr2[lo]) < 0)){
            swap(arr1[j], arr1[i]);
            swap(arr2[j], arr2[i]);
            i++;
        }
        j++;
    }
    swap(arr1[lo], arr1[i-1]);
    swap(arr2[lo], arr2[i-1]);
    quickerSort2(arr1, arr2, lo, i-2);
    quickerSort2(arr1, arr2, i, hi);
}

int main()
{
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
	quickSort(arr, 0, n - 1);

    string a[n];
    int b[n];
    int c = 0;
    a[0] = arr[0];
    b[0] = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i-1]) {
            c++;
            a[c] = arr[i];
            b[c] = 1;
        } else {
            b[c]++;
        }
    }

    quickerSort2(b, a, 0, c);
    /*
    int swp = 1;
	while (swp == 1) {
		swp = 0;
		for (int i = 0; i < c; i++) {
			if (b[i] < b[i+1]) {
				swap(b[i], b[i+1]);
				swap(a[i], a[i+1]);
				swp = 1;
			} else if (b[i] == b[i+1]) {
                if (comparestring(a[i], a[i+1]) > 0) { 
					swap(b[i], b[i+1]);
					swap(a[i], a[i+1]);
					swp = 1;
                }
			}
		}
	}
*/
    for (int i = 0; i <= c; i++) {
        cout << a[i] << " " << b[i] << "\n";
    }
    return 0;
}