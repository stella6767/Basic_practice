#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int sda(int argc, char* argv[]) {
	int input, change, num, total, i;
	int coin[9] = { 50000,10000,5000,1000,500,100,50,10,1 };
	int count[9];

	printf("<<<������ �л��Ĵ� �޴�>>>\n");
	printf("1.���(1500)\n");
	printf("2.����(2000)\n");
	printf("3.���(2500)\n");
	printf("4.�δ��(3000)\n");
	printf("����>>");
	scanf("%d", &num);
	if (num > 4 || num < 1)
		printf("�޴� ��Ͽ� �����ϴ�.\n");

	if (num < 5 && num>0) {
		printf("�Աݾ�: ");
		scanf("%d", &input);

		if (num == 1)
		{
			num = 1500;
		}
		else if (num == 2)
		{
			num = 2000;
		}
		else if (num == 3)
		{
			num = 2500;
		}
		else if (num == 4)
		{
			num = 3000;
		}
		printf("=================================\n");

		if (input < num) {
			printf("���� �����մϴ�.\n");
		}
		else {
			printf("�ı� 1���� ��µ˴ϴ�.\n");
			change = input - num;
			total = input - num;
			printf("�Ž������� \n");

			for (i = 0; i < 9; i++) {
				count[i] = change / coin[i];
				change = change % coin[i];
				printf("%d��: %d��\n", coin[i], count[i]);
			}

			printf("�� %d���Դϴ�.\n", total);
		}
	}
}