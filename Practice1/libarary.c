#include <stdio.h>
#include <stdlib.h>

struct book {   //å ���� ����ü ����
	char title[30];
	int page;
	int price;
	int pub;
	char auth[30];
};

//�������� �Լ����� ����ϱ� ���� ���������� ����
struct book bolist[10]; // å�� 10�Ǳ��� ����
int no = 0; //���� �Էµ� å ��
char setitle[30]; //�˻� å ���� ����

void book_insert() { //å ���� �Է� �Լ�
	printf("������� �Էµ� å�� %d�Դϴ�.\n", no);

	if (no < 11) { //�Էµ� å ���� 10���� �ʰ����� �ʵ���
		printf("�߰��� å�� ���� : ");
		scanf("%s", &bolist[no].title);
		printf("�߰��� å�� �������� : ");
		scanf("%d", &bolist[no].page);
		printf("�߰��� å�� ���� : ");
		scanf("%d", &bolist[no].price);
		printf("�߰��� å�� ���ǳ⵵: ");
		scanf("%d", &bolist[no].pub);
		printf("�߰��� å�� ���� : ");
		scanf("%s", &bolist[no].auth);
		printf("�߰� �Ϸ�! \n");

		no++; //å �ְ� �Ϸ��ϸ� ���� �Էµ� å ���� 1�� ����
	}

	else//10���� ���� ������ �޽����� ȣ��
		printf("�Է� å ������ �ѵ��� �� á���ϴ�. ");
}

void book_delete() {
	int i, k, flag = 0, bookindex = 0;

	printf("���� �� å ������ �Է��Ͻÿ�: ");
	scanf("%s", &setitle);

	for (i = 0; i < no; i++) { //���� ��ϵ� å���� �˻� ����
		if (strcmp(bolist[i].title, setitle) == 0) {//�Է� ���� ��ϵ� ������ ��ġ�ϸ�
			printf("%d ��ġ�� å�� �����մϴ�.\n", i + 1);
			bookindex = i;

			for (k = bookindex; k < no - 1; k++) { //���� ��ϵ� å���� 1 �� �ͱ���
				bolist[k] = bolist[k + 1];//������ å ������ ���� å ������ ����(�ϳ��� �ø�)
			}

			strcpy(bolist[no - 1].title, ""); //������ ��° å ���� �ʱ�ȭ (�� ���� ���� �� ����)
			bolist[no - 1].page = 0;
			bolist[no - 1].price = 0;
			bolist[no - 1].pub = 0;
			strcpy(bolist[no - 1].auth, "");
			no--; //���� ���å������ -1

			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		printf("å ������ ã�� �� �����ϴ�.\n");
	}
}

void book_select() {
	int i, flag = 0;

	printf("�˻��� ý ������ �Է��Ͻÿ�: ");
	scanf("%s", &setitle);

	for (i = 0; i < no; i++) {
		if (strcmp(bolist[i].title, setitle) == 0) {
			printf("��ȣ : %d // å �̸� : %s // �� �� : %s // ���� : %d //���ǳ⵵ %d\n", i + 1,
				bolist[i].title, bolist[i].auth, bolist[i].price, bolist[i].pub);

			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		printf("�Է��Ͻ� å ������ �����ϴ�.");
	}
}

void book_print() {
	int i;

	printf("\n");
	//printf("[%2c] | [%3c] | [%7c] | [%5c] | [%4c] | [%4c] \n",a,b,c,d,e,f);
	//printf("��ȣ | å���� | ��������(��) | ����(��) | ���ǳ⵵ | �۰��̸� \n");
	printf("----------------------------------------------------\n");
	for (i = 0; i < no; i++) {
		printf("��ȣ: [%2d] | å����: [%s] | ��������: [%6d] | ����(��): [%6d] | ���ǳ⵵: [%4d] | �۰��̸�: [%s]\n", i + 1, bolist[i].title, bolist[i].page, bolist[i].price, bolist[i].pub, bolist[i].auth);
		printf("----------------------------------------------------\n");
	}
}

int main(int argc, char* argv[]) {
	int menu;

	while (1) {
		printf("\n");
		printf("���� ���� ���α׷� \n");
		printf("�޴��� �����ϼ��� \n");

		printf("1. å�� ���� �߰��ϱ� \n");
		printf("2. å�� �����ϱ� \n");
		printf("3. å�� �˻��ϱ� \n");
		printf("4. å�� ����ϱ� \n");
		printf("5. ���α׷� ���� \n");

		printf("�޴��� ���ÿ�: ");
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
			printf("�ٽ� �����Ͻÿ�.\n");
		}
	}

	return 0;
}