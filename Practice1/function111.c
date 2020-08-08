#include <stdio.h>

int main()
{
	int year;

	printf("년도를 입력하세요 : ");
	scanf("%d", &year);

	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		printf("%d 년은 윤년 입니다.\n", year);
	else
	{
		printf("%d 년은 윤년이 아닙니다.\n", year);
	}
}