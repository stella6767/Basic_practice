#include <stdio.h>
#define SIZE 10

int main(void)
{
	char ans;
	int seat[SIZE] = { 0 };
	int ans1, i;

	while (1) {
		printf("�¼��� �����Ͻðڽ�?(y or n): ");
		scanf("%c", &ans);

		if (ans == 'y') {
			printf("----------------------\n");
			printf("1 2 3 4 5 6 7 8 9 10\n");
			printf("----------------------\n");

			for (i = 0; i < SIZE; i++)
				printf("%d ", seat[i]);

			printf("\n");

			printf("�� �� ° �¼��� �����Ͻðڽ��ϱ�?: ");
			scanf("%d", &ans1);

			if (seat[ans1 - 1] == 0) {
				seat[ans1 - 1] = 1;
				printf("����Ǿ����ϴ�. \n");
			}

			else
				printf("�̹� ����� �¼��Դϴ�. �ٸ� �¼��� �������ּ���.\n");
		}

		else if (ans == 'n')
			return 0;
	}

	return 0;
}