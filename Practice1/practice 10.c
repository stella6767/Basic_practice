#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int adfafan()

{
	srand((unsigned)time(NULL));

	int i, j, least, temp, array[10];

	for (i = 0; i < 9; i++) //�迭�� �ʱⰪ�� ���� ���� ��� �� �ִ� ���� 0�̶�� �� �̿�

		array[i] = rand() % 100;

	for (i = 0; i < 9; i++)

	{
		least = i;

		for (j = i + 1; j < 10; j++)

			if (array[j] < array[least])

				least = j;

		temp = array[i]; //�迭 i��° ���� temp ������ �������

		array[i] = array[least];//�迭 i��° ������ �ּҰ��� ������� �����

		array[least] = temp; //���� �ּڰ��� �ִ� �迭 ������ ���� i���� �ִ� ���� �������
	}

	for (i = 0; i < 10; i++)

		printf("%d ", array[i]);

	printf("\n");

	printf("�ּҰ��� %d�̰� �ִ밪�� %d�Դϴ�.", array[0], array[9]);
}