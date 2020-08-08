#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int sda(int argc, char* argv[]) {
	int input, change, num, total, i;
	int coin[9] = { 50000,10000,5000,1000,500,100,50,10,1 };
	int count[9];

	printf("<<<정보관 학생식당 메뉴>>>\n");
	printf("1.라면(1500)\n");
	printf("2.라면밥(2000)\n");
	printf("3.돈까스(2500)\n");
	printf("4.부대찌개(3000)\n");
	printf("선택>>");
	scanf("%d", &num);
	if (num > 4 || num < 1)
		printf("메뉴 목록에 없습니다.\n");

	if (num < 5 && num>0) {
		printf("입금액: ");
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
			printf("돈이 부족합니다.\n");
		}
		else {
			printf("식권 1개가 출력됩니다.\n");
			change = input - num;
			total = input - num;
			printf("거스름돈은 \n");

			for (i = 0; i < 9; i++) {
				count[i] = change / coin[i];
				change = change % coin[i];
				printf("%d원: %d개\n", coin[i], count[i]);
			}

			printf("총 %d원입니다.\n", total);
		}
	}
}