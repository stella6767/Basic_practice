#include <stdio.h>
#define SIZE 5
#include <time.h>
#include <stdlib.h>
int random(void);
int main(void) {
	srand((unsigned)time(NULL));
	int A[SIZE][SIZE];

	int a; int b;
	for (a = 0; a < SIZE; a++)
	{
		for (b = 0; b < SIZE; b++)
		{
			printf("%d ", A[a][b] = random());
		}
		printf("n");
	}

	return 0;
}
int random(void)
{
	int k;
	k = rand() % 9 + 1;
	return k;
}