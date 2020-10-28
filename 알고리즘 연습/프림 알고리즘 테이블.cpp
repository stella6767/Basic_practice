#include <iostream>
using namespace std;

void printTable(int n, int e[], int d[], int v[]) {
	for (int i = 0; i < n; i++) cout << (char)(i + 'a') << "\t"; cout << endl;
	for (int i = 0; i < n; i++) cout << (char)(e[i] + 'a') << "\t"; cout << endl;
	for (int i = 0; i < n; i++) cout << d[i] << "\t"; cout << endl;
	for (int i = 0; i < n; i++) cout << v[i] << "\t"; cout << endl << endl;
}

int findMinIndex(int n, int d[], int v[]) {
	int i, j;
	for (i = 0; i < n; i++) if (v[i] == 0) break;
	for (j = i; j < n; j++) if (v[j] == 0 && d[j] < d[i]) i = j;
	return i;
}

int main() {
	int m;
	int g[5][5] = {
		{0, 6, 2, 1024, 1024},
		{6, 0, 5, 7, 1024},
		{2, 5, 0, 4, 3},
		{1024, 7, 4, 0 ,1},
		{1024, 1024, 3, 1, 0}
	};

	int e[5] = { 0, 0, 0, 0, 0 };
	int d[5] = { 0, 6, 2, 1024, 1024 };
	int v[5] = { 1, 0, 0, 0, 0 };
	int n = 5;
	printTable(n, e, d, v);

	for (int i = 1; i < n; i++) {
		m = findMinIndex(n, d, v);
		v[m] = 1;
		for (int j = 0; j < n; j++) {
			if (v[j] == 0 && g[m][j] < d[j]) {
				d[j] = g[m][j];
				e[j] = m;
			}
		}
		printTable(n, e, d, v);
	}

}
