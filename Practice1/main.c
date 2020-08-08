#include <stdio.h>

#include <stdlib.h>

#include <time.h>

int main() {
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, i, tmp, flag;

	for (i = 0; i < 6; i++) {
		flag = 0;
		tmp = rand() % 10 + 1;

		if (tmp == num1)flag = 1;
		else if (tmp == num2)flag = 1;
		else if (tmp == num3)flag = 1;
		else if (tmp == num4)flag = 1;
		else if (tmp == num5)flag = 1;
		else if (tmp == num6)flag = 1;

		if (flag == 0) {
			switch (i) {
			case 0:
				num1 = tmp;
				break;

			case 1:
				num2 = tmp;			break;

			case 2:
				num3 = tmp;
				break;

			case 3:
				num4 = tmp;
				break;
			case 4:
				num5 = tmp;
				break;
			}	printf("¹øÈ£´Â: %d\n", tmp);
		}
		else {
			i--;
		}
	}
}