#include<chrono>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define M 1000000
int main() {
	double A[M];
	string x = "input";
	string z = ".txt";
	string y, input;
	for (int i = 1; i <= 10; i++) {
		y = to_string(i);
		input = x + y + z;
		const char *in = input.c_str();
		freopen(in, "r", stdin);
		for (int i = 0; i < M; i++) {
			cin >> A[i];
		}
		auto start = high_resolution_clock::now();
		sort(A, A + M);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "Sorting time for input from file " << input << "is " << duration.count() << " (microsecond)" << endl;
	}
	return 0;
}
