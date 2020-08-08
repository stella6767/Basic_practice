#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu_print(); //메뉴 출력 함수
int change_input(int); //메뉴 선택 함수
int menu_select(void); // 거스름돈 입력 함수
int change_cal(int input, int num, int ok); //거스름돈 계산 함수
void final(); //최종 출력함수

int msn() {
	int input, change, total, num, i, ok; //ok 변수는 if문을 통해서 쓸데없는 내용 걸러내는 용도
	int coin[9] = { 50000,10000,5000,1000,500,100,50,10,1 };	//화페 단위를 배열로 선언
	int count[9]; //화페 개수 배열

	menu_print();
	num = menu_select();

	if (num < 5 && num>0) //1~4번 메뉴판 중 하나의 숫자를 고르면
		input = change_input(num); //input에 이 함수 리턴값 대입

	if (num == 1) //고른 번호의 메뉴값으로 변환
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
	else//메뉴판에 없다면 ok 변수로 변환
		num = ok;

	printf("=================================\n");

	change = change_cal(input, num, ok);
	total = change; // 총 잔액

	final();

	if (num != ok && input >= num) {  //메뉴판에 없지 않거나 입력금액보다 고른 메뉴 가격이 적다면
		for (i = 0; i < 9; i++) { //9개의 화페단위까지 반복해서
			count[i] = change / coin[i]; //화폐 개수는 큰 단위부터 나누어서 계산
			change = change % coin[i]; //나머지 값을 잔돈에 저장
			printf("%d원: %d개\n", coin[i], count[i]);
		}

		printf("총 %d원입니다.\n", total);
	}
}

void menu_print() { //단순 프린트
	printf("<<<정보관 학생식당 메뉴>>>\n");
	printf("1.라면(1500)\n");
	printf("2.라면밥(2000)\n");
	printf("3.돈까스(2500)\n");
	printf("4.부대찌개(3000)\n");
}

int menu_select(void) //정수형 num 값을 반환
{
	int num;
	printf("선택>> ");
	scanf("%d", &num);
	if (num > 4 || num < 1)// 만약 메뉴판과 다른 숫자를 넣으면 목록없음 출력
		printf("메뉴 목록에 없습니다.\n");

	return num;
}

int change_input(int num)// 위랑 비슷
{
	int input = 10000;

	printf("입금액: ");
	scanf("%d", &input);

	return input;
}

int change_cal(int input, int num, int ok)
{
	if (num != ok) //만약 메뉴판에 있다면
		return (input - num); //이 값이 change(거스름돈) 변수로
} //원래 더 하고 싶었으나 능력부족으로 포기

void final(int input, int num, int ok) //이하 동일, 능력부족으로 만들다 포기
{
	if (input < num) {
		printf("돈이 부족합니다.\n");
	}
	else if (num != ok) {
		printf("식권 1개가 출력됩니다.\n");
		printf("거스름돈은 \n");
	}
}