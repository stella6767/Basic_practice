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
	for (j = i; j < n; j++) { //아직 방문 안한 노드부터 끝 노드까지 
		if (v[j] == 0 && d[j] < d[i]) i = j; //가장 짧은 거리의 노드를 방문에 포함시킨다.
	}
	return i;
}

int main() {
	int m;
	int g[6][6] = {  //일방향 노드들로 구성
		{0, 1, 3, 5, 7, 9}, //노드 distance
		{1024, 0, 1, 3, 5, 7},
		{1024, 1024, 0, 1, 3, 5},
		{1024, 1024, 1024, 0 ,9, 3},
		{1024, 1024, 1024, 1024, 0, 9},
		{1024, 1024, 1024, 1024, 1024, 0}
	};

	int e[6] = { 0, 0, 0, 0, 0, 0 }; //earlier
	int d[6] = { 0, 1, 3, 5, 7, 9 }; //초기 0번 노드 distance
	int v[6] = { 1, 0, 0, 0, 0, 0 }; //방문시작점
	int n = 6;
	printTable(n, e, d, v);

	for (int i = 1; i < n; i++) {
		m = findMinIndex(n, d, v);
		v[m] = 1;
		for (int j = 0; j < n; j++) {
			if (v[j] == 0 && d[m] + g[m][j] < d[j]) { //아직 방문 안했고 최소값인 부분
				d[j] = d[m] + g[m][j]; //distance 갱신해주는 부분 a번지부터 + 원래 인접노드 까지의 거리
				e[j] = m; //earlier 갱신
			}
		}
		printTable(n, e, d, v);
	}

}
