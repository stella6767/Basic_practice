#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu_print(); //�޴� ��� �Լ�
int change_input(int); //�޴� ���� �Լ�
int menu_select(void); // �Ž����� �Է� �Լ�
int change_cal(int input, int num, int ok); //�Ž����� ��� �Լ�
void final(); //���� ����Լ�
void final2(int num, int ok, int input, int i, int change, int total);

int main() {
	int input, change, total, num, i, ok; //ok ������ if���� ���ؼ� �������� ���� �ɷ����� �뵵
	int coin[9] = { 50000,10000,5000,1000,500,100,50,10,1 };	//ȭ�� ������ �迭�� ����
	int count[9]; //ȭ�� ���� �迭

	menu_print();
	num = menu_select();

	if (num < 5 && num>0) //1~4�� �޴��� �� �ϳ��� ���ڸ� ����
		input = change_input(num); //input�� �� �Լ� ���ϰ� ����

	if (num == 1) //�� ��ȣ�� �޴������� ��ȯ
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
	else//�޴��ǿ� ���ٸ� ok ������ ��ȯ
		num = ok;

	printf("=================================\n");

	change = change_cal(input, num, ok);
	total = change; // �� �ܾ�

	final();
	final2(num, ok, input, i, change, total);
}

void menu_print() { //�ܼ� ����Ʈ
	printf("<<<������ �л��Ĵ� �޴�>>>\n");
	printf("1.���(1500)\n");
	printf("2.����(2000)\n");
	printf("3.���(2500)\n");
	printf("4.�δ��(3000)\n");
}

int menu_select(void) //������ num ���� ��ȯ
{
	int num;
	printf("����>> ");
	scanf("%d", &num);
	if (num > 4 || num < 1)// ���� �޴��ǰ� �ٸ� ���ڸ� ������ ��Ͼ��� ���
		printf("�޴� ��Ͽ� �����ϴ�.\n");

	return num;
}

int change_input(int num)// ���� ���
{
	int input = 10000;

	printf("�Աݾ�: ");
	scanf("%d", &input);

	return input;
}

int change_cal(int input, int num, int ok)
{
	if (num != ok) //���� �޴��ǿ� �ִٸ�
		return (input - num); //�� ���� change(�Ž�����) ������
} //���� �� �ϰ� �;����� �ɷº������� ����

void final(int input, int num, int ok) //���� ����, �ɷº������� ����� ����
{
	if (input < num) {
		printf("���� �����մϴ�.\n");
	}
	else if (num != ok) {
		printf("�ı� 1���� ��µ˴ϴ�.\n");
		printf("�Ž������� \n");
	}
}

void final2(int num, int ok, int input, int i, int change, int total) {
	int coin[9] = { 50000,10000,5000,1000,500,100,50,10,1 };
	int count[9];

	if (num != ok && input >= num) {
		for (i = 0; i < 9; i++) {
			count[i] = change / coin[i];
			change = change % coin[i];
			printf("%d��: %d��\n", coin[i], count[i]);
		}

		printf("�� %d���Դϴ�.\n", total);
	}
}