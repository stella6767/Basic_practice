#include <stdio.h>

int compare(int a[], int b[], int size) {
	int i, result = 0;

	for (i = 0; i < 2; i++) {
		if (a[i] == b[i])
			result += 1;
		else
			result -= 1;
	}

	return result;
}

int fsin()

{
	int a[] = { 0,2 };
	int b[] = { 1,2 };

	int size = 2; //상수를 매개변수로 받을 수 없기 때문에~~ 질문거

	printf("%d  %d \n", a[0], a[1]);
	printf("%d  %d \n", b[0], b[1]);

	if (compare(a, b, 2) == 2) //배열을 함수로 호출할 때 함수명만
		printf("두 원소 같음 ㅇㅋ");
	else
		printf("두 원소 다름");

	return 0;
}