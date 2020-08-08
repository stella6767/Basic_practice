#include <stdio.h>
#define SIZE 10

int main(void)
{
	char ans;
	int seat[SIZE] = { 0 };
	int ans1, i;

	while (1) {
		printf("좌석을 예약하시겠슴?(y or n): ");
		scanf("%c", &ans);

		if (ans == 'y') {
			printf("----------------------\n");
			printf("1 2 3 4 5 6 7 8 9 10\n");
			printf("----------------------\n");

			for (i = 0; i < SIZE; i++)
				printf("%d ", seat[i]);

			printf("\n");

			printf("몇 번 째 좌석을 예약하시겠습니까?: ");
			scanf("%d", &ans1);

			if (seat[ans1 - 1] == 0) {
				seat[ans1 - 1] = 1;
				printf("예약되었습니다. \n");
			}

			else
				printf("이미 예약된 좌석입니다. 다른 좌석을 선택해주세요.\n");
		}

		else if (ans == 'n')
			return 0;
	}

	return 0;
}