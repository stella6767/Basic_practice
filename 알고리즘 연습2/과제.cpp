#include <iostream>
using namespace std;

bool S[50][50] = { {0} }; // DP에 사용
int SS[50][50] = { {0} }; // MM에 사용

bool shuffle_DC(int A[], int B[], int C[], int i, int j) {
	if (i < 0 || j < 0) {
		return false;
	}
	if (i == 0 && j == 0) {
		return true;
	}

	if (((C[i + j] == A[i]) && shuffle_DC(A, B, C, i - 1, j)) || ((C[i + j] == B[j]) && shuffle_DC(A, B, C, i, j - 1)))
		return true; //
	else
		return false;
}

bool shuffle_DP(int A[], int B[], int C[], int i, int j) {
	int k, s;

	for (k = 0; k <= i; k++) {
		for (s = 0; s <= j; s++) {
			if (k == 0 && s == 0) S[k][s] = 1;
			if ((C[k + s] == A[k]) && (S[k - 1][s])) {
				S[k][s] = 1;
			}

			if ((C[k + s] == B[s]) && (S[k][s - 1]))
				S[k][s] = 1;
		}
	}

	return S[i][j];
}

int shuffle_MM(int A[], int B[], int C[], int i, int j) {
	if (i > 0) {
		if ((C[i + j] == A[i]) && shuffle_MM(A, B, C, i - 1, j)) {
			SS[i][j] = 1;
		}
	}
	if (j > 0) {
		if ((C[i + j] == B[j]) && shuffle_MM(A, B, C, i, j - 1)) {
			SS[i][j] = 1;
		}
	}
	return SS[i][j];
}

void init(int n, int m) {
	SS[0][0] = 1; //기저사례

	return;
}

int main() {
	int A[50] = { 0 };
	int B[50] = { 0 };
	int C[100] = { 0 };
	int n, m, i, j, k;

	cin >> n;
	for (i = 1; i <= n; i++) cin >> A[i];
	cin >> m;
	for (j = 1; j <= m; j++) cin >> B[j];
	for (k = 1; k <= n + m; k++) cin >> C[k];
	init(n, m); //전역변수 초기화를 위해 사용가능

	if (shuffle_DC(A, B, C, n, m)) cout << "TRUE ";
	else cout << "FALSE ";
	if (shuffle_DP(A, B, C, n, m)) cout << "TRUE ";
	else cout << "FALSE ";
	if (shuffle_MM(A, B, C, n, m)) cout << "TRUE ";
	else cout << "FALSE ";

	cout << endl;

	for (int k = 0; k < n + 1; k++) {
		for (int s = 0; s < m + 1; s++) {
			cout << S[k][s];
		}
		cout << endl;
	}

	cout << endl;

	for (int k = 0; k < n + 1; k++) {
		for (int s = 0; s < m + 1; s++) {
			cout << SS[k][s];
		}
		cout << endl;
	}

	return 0;
}