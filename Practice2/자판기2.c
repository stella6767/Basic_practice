#include <stdio.h>
// 메뉴를 선택하는 함수
int menu_select(int remainder);
// 메뉴를 실행하는 함수
void menu_run(int input, int* remainder);
// 거스름돈을 반환하는 함수
void remainder_coin(int* remainder);
// 마실 음료를 선택하는 함수
void drink_select(int* remainder);
// 커피와 설탕을 선택하는 함수
int cream_sugar();

int main()
{
	// 자판기 내의 잔액 변수입니다.
	int remainder = 0;
	// 사용자가 입력한 입력값입니다.
	int input = 0;
	// 사용자가 3번(거스름돈 반환)을 선택하지 않으면 무한 반복합니다.
	while (input != 3)
	{
		// 1, 2, 3번 중에서 선택된 메뉴를 input 변수에 대입합니다.
		input = menu_select(remainder);
		// 선택된 input 변수와 거스름돈의 주소를 가지고 메뉴를 실행합니다.
		menu_run(input, &remainder);
	}
	return 0;
}

// 메뉴 실행 함수입니다.
void menu_run(int input, int* remainder)
{
	// 임시 저장 변수
	int temp;
	// 메뉴로 선택된 값에 따로 switch-case문을 실행합니다.
	switch (input)
	{
		// 1. 돈을 입력하는 부분입니다.
	case 1:
		printf("얼마를 투입합니까? ");
		scanf("%d", &temp);
		// 입력된 돈을 거스름돈에 더합니다.
		*remainder = *remainder + temp;
		break;
		// 음료를 뽑는 부분입니다.
	case 2:
		// 음료를 선택하는 함수로 거스름돈을 인자로 가지고 실행합니다.
		drink_select(remainder);
		break;
		// 거스름돈을 반환하는 부분입니다.
		// 거스름돈 반환 후 종료합니다.
	case 3:
		printf("거스름돈을 반환합니다.\n");
		// 거스름돈의 반환을 위해 만든 함수입니다.
		// 이 함수에서는 500원, 100원, 50원, 10원 단위로 반환합니다.
		remainder_coin(remainder);
		printf("프로그램을 종료합니다.\n");
		break;
	}
}

// 음료를 선택하는 함수입니다.
void drink_select(int* remainder)
{
	// 기존 음료가 가지는 가격과 이름입니다.
	int drink_value[6] = { 200, 150, 220, 1000, 500, 100 };
	char drink_name[6][10] = { {"맥심커피"}, {"녹차"}, {"우유"}, {"원두커피"}, {"우롱차"}, {"일반커피"} };
	// 임시로 음료가 가지는 가격과 이름이 저장될 공간입니다.
	// 이것을 만든 이유는 가격에 따라 해당되는 음료만 디스플레이 되도록 하게 하라고
	// 문제에 나왔으므로 만들었습니다.
	// 위의 가격을 순차적으로 정렬한 후에 하면 더 쉬울 수도 있지만 임의의 경우 발생시
	// 프로그램이 제대로 동작하지 않으므로 만들었습니다.
	int temp_value[6];
	char temp_name[6][10];
	// count 변수는 디스플레이 될 음료의 갯수를 저장합니다.
	int i, count = 0, input;
	printf("마실 음료를 선택해 주세요.\n");
	// 반복문을 통해 잔액보다 작거나 같음 음료를 찾아내어 임시 저장소에 저장합니다.
	for (i = 0; i < 6; i++)
	{
		// 거스름돈보다 작거나 같은 음료를 찾아내는 부분
		// 디스플레이 될 메뉴들...
		if (*remainder >= drink_value[i])
		{
			// 디스플레이 될 음료의 가격과 이름을 임시 저장소에 저장합니다.
			temp_value[count] = drink_value[i];
			strcpy(temp_name[count], drink_name[i]);
			// 디스플레이 될 음료의 가격과 이름을 순번을 매겨 출력합니다.
			// 여기서 count + 1의 경우는 번호를 1부터 시작하기 위함입니다.
			printf("%d. %s(%d원)\n", count + 1, temp_name[count], temp_value[count]);
			// 또 다른 디스플레이 될 메뉴가 있으면 임시저장소에 저장해야 되므로
			// count 값을 증가합니다.
			count++;
		}
	}
	// 만약 디스플레이 될 메뉴 있다면
	if (count > 0)
	{
		// 어떠한 메뉴를 선택할 것인지를 입력받습니다.
		printf("? ");
		scanf("%d", &input);
		// 그 입력받은 메뉴에 해당하는 음료의 이름이 맥심커피나 일반커피일 경우
		// 크림이나 설탕 선택 함수로 넘어가게 됩니다.
		// 여기서 배열의 인자 부분에 input - 1 의 경우는 배열이 0부터 시작하는 것에 반해
		// 메뉴의 선택은 1번부터 시작되므로 1을 빼 주어야 정상적인 연산이 됩니다.
		if (strcmp(temp_name[input - 1], "맥심커피") == 0 || strcmp(temp_name[input - 1], "일반커피") == 0)
		{
			// 크림이나 설탕 함수에서 잘못된 입력이 있을 경우 1이 반환되므로
			// 정상적인 입력이 되어 0이 반환되었을 때 출력과 거스름돈의 연산을 합니다.
			// 잘못된 입력이 있을 경우 "잘못된 입력입니다."란 메세지와 함께 처음부터 다시 시작합니다.
			if (cream_sugar() == 0)
			{
				printf("%s(%d원)을(를) 뽑았습니다.\n", temp_name[input - 1], temp_value[input - 1]);
				*remainder = *remainder - temp_value[input - 1];
			}
		}
		// 만약 선택한 음료가 커피 종류가 아니고 디스플레이 된 음료를 정상적으로 선택했을 때
		// 선택함 음료를 출력하고 거스름돈의 연산을 합니다.
		else if (input - 1 < count && input - 1 >= 0)
		{
			printf("%s(%d원)을(를) 뽑았습니다.\n", temp_name[input - 1], temp_value[input - 1]);
			*remainder = *remainder - temp_value[input - 1];
		}
		// 디스플레이 된 메뉴를 선택하지 않고 잘못된 입력을 했을 경우
		else
			printf("잘못된 입력입니다.\n");
	}
	// 만약 디스플레이 될 메뉴가 없다면 아래와 같은 메세지를 출력합니다.
	else
	{
		printf("잔액이 부족합니다.\n");
	}
}

// 크림과 설탕 선택 함수입니다.
// 정상적인 수행시 0의 값을 반환하고
// 비정상적인 수행시 1의 값을 반환합니다.
int cream_sugar()
{
	int input;
	// 크림 or 설탕을 선택합니다.
	printf("크림과 설탕을 선택하세요.\n");
	printf("1. 크림\n");
	printf("2. 설탕\n");
	printf("? ");
	scanf("%d", &input);
	// 크림 or 설탕으로 선택된 값을 통해 switch-case문을 실행합니다.
	switch (input)
	{
		// 크림을 선택했을 경우
	case 1:
		printf("크림의 양을 선택하세요.\n");
		printf("1. 대\n");
		printf("2. 증\n");
		printf("3. 소\n");
		printf("? ");
		scanf("%d", &input);
		// 크림의 선택에서 대, 중, 소를 선택하는 부분
		switch (input)
		{
		case 1:
			printf("크림(대) ");
			break;
		case 2:
			printf("크림(중) ");
			break;
		case 3:
			printf("크림(소) ");
			break;
		default:
			// 잘못된 입력시 1을 반환합니다.
			printf("잘못된 입력입니다.\n");
			return 1;
			break;
		}
		break;
		// 설탕을 선택했을 경우
	case 2:
		printf("설탕의 양을 선택하세요.\n");
		printf("1. 대\n");
		printf("2. 증\n");
		printf("3. 소\n");
		printf("? ");
		scanf("%d", &input);
		// 설탕의 선택에서 대, 중, 소를 선택하는 부분
		switch (input)
		{
		case 1:
			printf("설탕(대) ");
			break;
		case 2:
			printf("설탕(중) ");
			break;
		case 3:
			printf("설탕(소) ");
			break;
		default:
			// 잘못된 입력일 경우 메세지와 함께 1을 반환합니다.
			printf("잘못된 입력입니다.\n");
			return 1;
			break;
		}
		break;
		// 설탕과 크림의 선택이 아닌 다른 잘못된 선택을 했을 경우
		// 1을 반환합니다.
	default:
		printf("잘못된 입력입니다.\n");
		return 1;
		break;
	}
	// 정상적인 종료시 0을 반환합니다.
	return 0;
}

// 마지막 프로그램 종료시 실행되는 함수인 거스름돈 반환 함수입니다.
void remainder_coin(int* remainder)
{
	// 임시 저장소에 거스름돈을 대입합니다.
	int temp = *remainder;
	// 거스름돈의 종류를 가지고 잇는 배열입니다.
	// 이 배열은 정렬되어 있어야합니다.
	int coin[4] = { 500, 100, 50, 10 };
	int i;
	// 배열의 크기만큼 반복합니다.
	for (i = 0; i < 4; i++)
	{
		// 반복문을 통해 임시저장소에 저장된 값을 coin[i]로 나누어주면
		// 해당 거스름돈을 몇 개를 반환해야 되는지 출력됩니다.
		printf("%4d 동전 : %3d개\n", coin[i], temp / coin[i]);
		// 그리고 임시저장소 내의 거스름돈을 현재 반복문에서의 coin[i]로 나머지 연산자를 사용합니다.
		// 이렇게 해 주면 coin[i]로 반환한 거스름돈을 제외한 나머지 금액이 남습니다.
		temp = temp % coin[i];
	}
	// 이렇게 반복문을 종료하고 나면 temp의 값은 10원단위까지 반환을 다 하게됩니다.
}

// 메뉴를 선택하는 부분입니다.
int menu_select(int remainder)
{
	int input = 0;
	printf("현재 자판기 내의 잔액은 %d입니다.\n", remainder);
	printf("================================\n");
	printf("1. 동전을 넣는다.\n");
	printf("2. 자판기를 이용한다.\n");
	printf("3. 거스름돈을 반환한다.(종료)\n");
	printf("================================\n");
	printf("? ");
	scanf("%d", &input);
	// 선택된 메뉴를 반환합니다.
	return input;
}