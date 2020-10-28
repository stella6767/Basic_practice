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
	for (i = 0; i < n; i++) {
		if (v[i] == 0) break;
	}
	for (j = i; j < n; j++) { //���� �湮 ���� ������ �� ������ 
		if (v[j] == 0 && d[j] < d[i]) i = j; //���� ª�� �Ÿ��� ��带 �湮�� ���Խ�Ų��.
	}
	return i;
}

int main() {
	int m;
	int g[6][6] = {  //�Ϲ��� ����� ����
		{0, 1, 3, 5, 7, 9}, //��� distance
		{1024, 0, 1, 3, 5, 7},
		{1024, 1024, 0, 1, 3, 5},
		{1024, 1024, 1024, 0 ,9, 3},
		{1024, 1024, 1024, 1024, 0, 9},
		{1024, 1024, 1024, 1024, 1024, 0}
	};

	int e[6] = { 0, 0, 0, 0, 0, 0 }; //earlier
	int d[6] = { 0, 1, 3, 5, 7, 9 }; //�ʱ� 0�� ��� distance
	int v[6] = { 1, 0, 0, 0, 0, 0 }; //�湮������
	int n = 6;
	printTable(n, e, d, v);

	for (int i = 1; i < n; i++) {
		m = findMinIndex(n, d, v);
		v[m] = 1;
		for (int j = 0; j < n; j++) {
			if (v[j] == 0 && d[m] + g[m][j] < d[j]) { //���� �湮 ���߰� �ּҰ��� �κ�
				d[j] = d[m] + g[m][j]; //distance �������ִ� �κ� a�������� + ���� ������� ������ �Ÿ�
				e[j] = m; //earlier ����
			}
		}
		printTable(n, e, d, v);
	}

}
