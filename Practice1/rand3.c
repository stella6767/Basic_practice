#include <stdio.h>

#include <stdlib.h>

#include <time.h>

int main()

{
	int a[6];

	int i, j;
	int cout = 0;
	int bFound;

	int b[6];

	srand((unsigned int)time(NULL));

	printf("�ζǹ�ȣ �Է�: ");
	scanf("%d %d %d %d %d %d", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5]);

	for (i = 0; i < 6; i++)
		a[i] = rand() % 35 + 1;

	// ������

	for (i = 0; i < 6; ++i)

		printf("%4d", a[i]);

	printf("\n\n");

	for (i = 0; i < 6; ++i) {
		printf("%4d", b[i]);
	}

	printf("\n");

	for (i = 0; i < 6; i++) {
		if (a[i] == b[i])
			cout++;
	}

	if (cout == 6)
		printf("�����մϴ�");
	else
		printf("����");

	return 0;
}