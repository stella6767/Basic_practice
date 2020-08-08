#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int prime_num(int n) {
	int i, j, num = 0;
	int total = 0;

	for (i = 2; i <= n; i++) {
		for (j = 2; j < i; j++) {
			if (i % j == 0)
				num++;
		}
		if (num == 0) {
			printf("%d \t", i);
			total++;
		}
		num = 0;
	}
	printf("소수 개수는: %d", total);
}

int mai(int argc, char* argv[]) {
	int n;

	printf("값 입력: ");
	scanf("%d", &n);

	printf("", prime_num(n));
}