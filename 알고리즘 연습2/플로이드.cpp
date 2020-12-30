#include <stdio.h>

int number = 5;
int INF = 10000000;

// �ڷ� �迭�� �ʱ�ȭ�մϴ�. 
int a[5][5] = {
	{0, 1, INF, 1,5},
	{9, 0, 3, 2,INF},
	{INF, INF, 0, 4,INF},
	{INF, INF, 2, 0, 3},
	{3, INF, INF, INF, 0}
};

void floydWarshall() {
	// ��� �׷����� �ʱ�ȭ�մϴ�. 
	int d[5][5];

	// ��� �׷����� �ʱ�ȭ�մϴ�. 
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			d[i][j] = a[i][j];
		}
	}

	// k = ���İ��� ���
	for (int k = 0; k < number; k++) {
		// i = ��� ���
		for (int i = 0; i < number; i++) {
			// j = ���� ��� 
			for (int j = 0; j < number; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	// ����� ����մϴ�. 
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