#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int adfafan()

{
	srand((unsigned)time(NULL));

	int i, j, least, temp, array[10];

	for (i = 0; i < 9; i++) //배열에 초기값을 주지 않은 경우 들어가 있는 값이 0이라는 걸 이용

		array[i] = rand() % 100;

	for (i = 0; i < 9; i++)

	{
		least = i;

		for (j = i + 1; j < 10; j++)

			if (array[j] < array[least])

				least = j;

		temp = array[i]; //배열 i번째 값을 temp 변수에 집어넣음

		array[i] = array[least];//배열 i번째 순서에 최소값을 순서대로 집어넣

		array[least] = temp; //원래 최솟값이 있던 배열 공간에 원래 i번쨰 있던 값을 집어넣음
	}

	for (i = 0; i < 10; i++)

		printf("%d ", array[i]);

	printf("\n");

	printf("최소값은 %d이고 최대값은 %d입니다.", array[0], array[9]);
}