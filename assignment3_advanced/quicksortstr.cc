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
 
void quickersort(string arr[], int lo, int hi) {
    if (hi - lo < 1) {
        return;
    }
    int pivot = rand()%(hi-lo + 1) + lo;
    swap(arr[lo], arr[pivot]);
    int i = lo + 1;
    int j = lo + 1;
    while (j <= hi) {
//        if (arr[j] < arr[lo]) {
        if (comparestring(arr[j], arr[lo]) < 0) {
            swap(arr[j], arr[i]);
            i++;
        }
        j++;
    }
    swap(arr[lo], arr[i-1]);
    quickersort(arr, lo, i-2);
    quickersort(arr, i, hi);
}

int main()
{
    string a[10] = {"123", "546", "687768", "123123123", "353457", "235", "23", "1", "5", "101010"};
    quickersort(a, 0, 9);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}