#include <stdio.h>

int is_prime(int n); // 함수 원형

int main(void)

{
	int n, i; // 변수 설정

	printf("정수를 입력하세요: "); // 범위 설정

	scanf("%d", &i);

	printf("2부터 %d사이의 소수를 출력합니다.\n", i);

	n = is_prime(i); // 함수 호출

	return 0;
}

int is_prime(int n) // 함수 정의

{
	int a, i; // 변수 설정

	for (a = 2; a <= n; a++) // 1은 소수가 아니기에 2부터 시작하여 사용자가 입력한 n까지 범위 사이의 소수를 계산

	{
		for (i = 2; i < a; i++) // i가 a와 같을경우 for문 작동을 하지 않게 설정함

		{
			if (a % i == 0) // a를 i로 나눈 나머지가 0일경우(a가 아닌 a의 약수가 존재할 경우)  반복 정지 (무의미한 반복계산 최소화)

				break;
		}

		if (a == i) // 반복을 거듭하여 a가 i와 같아졌을때 a의 값을 출력(i의 값을 출력해도 상관없음)

			printf("%d ", a);
	}

	printf("\n");

	return a;
}