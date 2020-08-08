#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int man(int argc, char* argv[]) {
	int n, i, j;

	printf("°ª ÀÔ·Â: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}

	for (i = 1; i <= n; i++) {
		for (j = n; j >= i; j--) {
			printf("*");
		}
		printf("\n");
	}
}