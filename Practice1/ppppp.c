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

	int size = 2; //����� �Ű������� ���� �� ���� ������~~ ������

	printf("%d  %d \n", a[0], a[1]);
	printf("%d  %d \n", b[0], b[1]);

	if (compare(a, b, 2) == 2) //�迭�� �Լ��� ȣ���� �� �Լ���
		printf("�� ���� ���� ����");
	else
		printf("�� ���� �ٸ�");

	return 0;
}