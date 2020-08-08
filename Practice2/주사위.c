#include <stdio.h>

#include <stdlib.h>

#include <time.h>

int ain(void) {
	int num1, num2, num3, num4, num5, num6, i, tmp, flag;

	for (i = 0; i < 6; i++) {
		flag = 0;
		tmp = rand() % 45 + 1;

		if (tmp == num1)flag = 1;
		else if (tmp == num2)flag = 1;
		else if (tmp == num3)flag = 1;
		else if (tmp == num4)flag = 1;
		else if (tmp == num5)flag = 1;
		else if (tmp == num6)flag = 1;

		if (flag == 0) {
			switch (i) {
			case 0:
				tmp = num1;
				break;

			case 1:
				tmp = num2;
				break;

			case 2:
				tmp = num3;
				break;

			case 3:
				tmp = num4;
				break;
			case 4:
				tmp = num5;
				break;
			case 5:
				tmp = num6;
				break;
			}
			printf("¹øÈ£´Â: %d", &tmp)

		else {
			i--;
		}
		}
	}

	return 0;
}