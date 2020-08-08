#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void is_prime(int n);

int main(int argc, char* argv[]) {
	int a;

	printf("정수 입력: ");
	scanf("%d", &a);

	is_prime(a);

	return 0;
}

void is_prime(int n) {
	int temp = n % 2;

	if (temp == 1)
		printf("%d 는 소수가 맞습니다.", n);

	else
		printf("소수만 출력");
}