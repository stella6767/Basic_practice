#include <stdio.h>

#include <stdlib.h>

#include <time.h>

int main()

{
	int a[10];

	int i, j;

	int bFound;

	srand((unsigned int)time(NULL));

	for (i = 0; i < 10; ++i)

	{
		while (1)

		{
			// �������ϳ�����

			a[i] = rand() % 10 + 1;

			// �̹��ִ°�����Ȯ���ϱ������÷��׼���

			bFound = 0;

			// ���������ִ���Ȯ���Ѵ�

			for (j = 0; j < i; ++j)

			{
				// ��������������

				if (a[j] == a[i])

				{
					// ���������̹�����

					bFound = 1;

					break;
				}
			}

			// �������̾�����while��Ż��

			if (!bFound)

				break;
		}
	}

	// ������

	for (i = 0; i < 10; ++i)

		printf("%4d", a[i]);

	printf("\n\n");

	return 0;
}