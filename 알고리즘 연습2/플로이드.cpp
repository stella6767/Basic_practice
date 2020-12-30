#include <stdio.h>

int number = 5;
int INF = 10000000;

// 자료 배열을 초기화합니다. 
int a[5][5] = {
	{0, 1, INF, 1,5},
	{9, 0, 3, 2,INF},
	{INF, INF, 0, 4,INF},
	{INF, INF, 2, 0, 3},
	{3, INF, INF, INF, 0}
};

void floydWarshall() {
	// 결과 그래프를 초기화합니다. 
	int d[5][5];

	// 결과 그래프를 초기화합니다. 
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			d[i][j] = a[i][j];
		}
	}

	// k = 거쳐가는 노드
	for (int k = 0; k < number; k++) {
		// i = 출발 노드
		for (int i = 0; i < number; i++) {
			// j = 도착 노드 
			for (int j = 0; j < number; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	// 결과를 출력합니다. 
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			printf("%3d ", d[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	floydWarshall();
}