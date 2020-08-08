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
			// 난수를하나생성

			a[i] = rand() % 10 + 1;

			// 이미있는값인지확인하기위해플래그설정

			bFound = 0;

			// 같은값이있는지확인한다

			for (j = 0; j < i; ++j)

			{
				// 같은값이있으면

				if (a[j] == a[i])

				{
					// 같은값이이미있음

					bFound = 1;

					break;
				}
			}

			// 같은값이없으면while문탈출

			if (!bFound)

				break;
		}
	}

	// 결과출력

	for (i = 0; i < 10; ++i)

		printf("%4d", a[i]);

	printf("\n\n");

	return 0;
}