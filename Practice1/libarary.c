#include <stdio.h>
#include <stdlib.h>

struct book {   //책 정보 구조체 선언
	char title[30];
	int page;
	int price;
	int pub;
	char auth[30];
};

//여러가지 함수에서 사용하기 위해 전역변수로 선언
struct book bolist[10]; // 책은 10권까지 제한
int no = 0; //현재 입력된 책 값
char setitle[30]; //검색 책 정보 변수

void book_insert() { //책 정보 입력 함수
	printf("현재까지 입력된 책은 %d입니다.\n", no);

	if (no < 11) { //입력된 책 값이 10개가 초과하지 않도록
		printf("추가할 책의 제목 : ");
		scanf("%s", &bolist[no].title);
		printf("추가할 책의 페이지수 : ");
		scanf("%d", &bolist[no].page);
		printf("추가할 책의 가격 : ");
		scanf("%d", &bolist[no].price);
		printf("추가할 책의 출판년도: ");
		scanf("%d", &bolist[no].pub);
		printf("추가할 책의 저자 : ");
		scanf("%s", &bolist[no].auth);
		printf("추가 완료! \n");

		no++; //책 주가 완료하면 현재 입력된 책 숫자 1씩 증가
	}

	else//10권이 꽉차 있으면 메시지만 호출
		printf("입력 책 데이터 한도가 꽉 찼습니다. ");
}

void book_delete() {
	int i, k, flag = 0, bookindex = 0;

	printf("삭제 할 책 제목을 입력하시오: ");
	scanf("%s", &setitle);

	for (i = 0; i < no; i++) { //현재 등록된 책까지 검색 수행
		if (strcmp(bolist[i].title, setitle) == 0) {//입력 값과 등록된 정보가 일치하면
			printf("%d 위치의 책을 삭제합니다.\n", i + 1);
			bookindex = i;

			for (k = bookindex; k < no - 1; k++) { //현재 등록된 책에서 1 뺀 것까지
				bolist[k] = bolist[k + 1];//삭제한 책 정보를 밑의 책 정보로 덮음(하나씩 올림)
			}

			strcpy(bolist[no - 1].title, ""); //마지막 번째 책 정보 초기화 (한 바퀴 도는 것 방지)
			bolist[no - 1].page = 0;
			bolist[no - 1].price = 0;
			bolist[no - 1].pub = 0;
			strcpy(bolist[no - 1].auth, "");
			no--; //현재 등록책값에서 -1

			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		printf("책 정보를 찾을 수 없습니다.\n");
	}
}

void book_select() {
	int i, flag = 0;

	printf("검색할 첵 제목을 입력하시오: ");
	scanf("%s", &setitle);

	for (i = 0; i < no; i++) {
		if (strcmp(bolist[i].title, setitle) == 0) {
			printf("번호 : %d // 책 이름 : %s // 저 자 : %s // 가격 : %d //출판년도 %d\n", i + 1,
				bolist[i].title, bolist[i].auth, bolist[i].price, bolist[i].pub);

			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		printf("입력하신 책 정보가 없습니다.");
	}
}

void book_print() {
	int i;

	printf("\n");
	//printf("[%2c] | [%3c] | [%7c] | [%5c] | [%4c] | [%4c] \n",a,b,c,d,e,f);
	//printf("번호 | 책제목 | 페이지수(쪽) | 가격(원) | 출판년도 | 작가이름 \n");
	printf("----------------------------------------------------\n");
	for (i = 0; i < no; i++) {
		printf("번호: [%2d] | 책제목: [%s] | 페이지수: [%6d] | 가격(원): [%6d] | 출판년도: [%4d] | 작가이름: [%s]\n", i + 1, bolist[i].title, bolist[i].page, bolist[i].price, bolist[i].pub, bolist[i].auth);
		printf("----------------------------------------------------\n");
	}
}

int main(int argc, char* argv[]) {
	int menu;

	while (1) {
		printf("\n");
		printf("도서 관리 프로그램 \n");
		printf("메뉴를 선택하세요 \n");

		printf("1. 책을 새로 추가하기 \n");
		printf("2. 책을 삭제하기 \n");
		printf("3. 책을 검색하기 \n");
		printf("4. 책을 출력하기 \n");
		printf("5. 프로그램 종료 \n");

		printf("메뉴를 고르시오: ");
		scanf("%d", &menu);

		if (menu == 5)
			break;

		switch (menu) {
		case 1:
			book_insert();
			break;

		case 2:
			book_delete();
			break;

		case 3:
			book_select();
			break;

		case 4:
			book_print();
			break;

		default:
			printf("다시 선택하시오.\n");
		}
	}

	return 0;
}