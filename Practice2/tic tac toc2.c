#include <stdio.h>
#include <stdlib.h>

void display_pan(char board[][3]); // ������ ��� �Լ�
int player_move(int player, char board[][3]); //���� ���� �� �ִ��� Ȯ���ϴ� �Լ�
int winner_check(char board[][3], int n); // ���� ���� Ȯ�� �Լ�

int mssssn()
{
	char board[3][3]; //������ 2���� �迭 ����
	int end = 0; //���� ���� ����
	int x, y; //�� �ʱ�ȭ �ϱ� ���� �ݺ��� ����
	int choice = 0; //���� Ƚ�� ����

	for (x = 0; x < 3; x++) // ������ 2���� �迭 �������� ���� �ʱ�ȭ
		for (y = 0; y < 3; y++)
			board[x][y] = ' ';

	do {    //�ϴ� ����
		display_pan(board); //�� ȣ��
		end = winner_check(board, choice); //���� ������ �� �Լ� ���ϰ� ����
		if (end == 1) //���ắ���� 1�̶�� �ݺ��� do while�� ��������
			break;
		end = player_move(0, board);  //������Է��� �޴� ���带 ȣ��(1���÷��̾�� 0)
		choice++; //���� �Լ��� ���������� ����Ǿ����� ���ప 1 ����
		if (end == 1)
			break;     //���ϵ���
		display_pan(board);
		end = winner_check(board, choice);
		if (end == 1) //���� �� �� �ϼ��� ����� ����
			break;
		end = player_move(1, board);  //������Է��� �޴� ���带 ȣ���Ѵ�.(2�� �÷��̾�) *2���÷��̾�� 1*
		choice++; //���� ���������� ���� 2�� �÷��̾ ��������ϸ� Ƚ�� ����
		if (end == 1)
			break;
	} while (end == 0); //end ���� 0�̸� ���� �ݺ�

	return 0;
}

void display_pan(char board[][3]) { //������ ����Լ�
	int i;

	for (i = 0; i < 3; i++) {
		printf("---|---|---\n");
		printf("%c  | %c | %c \n", board[i][0], board[i][1], board[i][2]); //�� ������ �迭 �� ǥ���ϵ��� ��
	}
	printf("---|---|---\n");
}

int player_move(int player, char board[3][3]) { //�÷��̾� ���� ������ �迭
	int x, y;
	int go = 0;//���ắ��

	while (go != 1) { //���ắ���� 1�� �ƴϸ�
		printf("(x,y) ��ǥ (���� -1, -1):"); //����ڿ��� ���ڿ��� ����ϰ� ��
		scanf("%d %d", &x, &y);

		if (x == -1 && y == -1)
			return 1;  //���� x�� y�� -1�� ��� 1�� ����(���ắ���� ���Խ�ų)
		if (board[x][y] == ' ')
			break;   //"board[x][y]"�� �����̽�ĭ�ϰ�� �ݺ����� ��������
		else
			printf("�߸��� ��ġ�Դϴ�.");  //�߸�����ġ�ϰ�� ��µǴ� ���ڿ�
	}

	if (player == 0) board[x][y] = 'X';  //�÷��̾� 1�ϰ�� 'X'
	else board[x][y] = 'O';     //�÷��̾� 2�ϰ�� 'O'�� ���
	return 0;
}

int winner_check(char board[][3], int n) {   //�迭�� ����Ƚ����.
	int a, b;

	for (a = 0; a < 3; a++) { //���� ���� �� X or O �̸� ��ȯ�Ѵ�
		if (board[a][1] == 'O' && board[a][2] == 'O' && board[a][0] == 'O')
		{
			printf("PLAYER2�� �¸��ϼ̽��ϴ�.");	return 1;
		}

		else if (board[a][1] == 'X' && board[a][2] == 'X' && board[a][0] == 'X')
		{
			printf("PLAYER1�� �¸��ϼ̽��ϴ�.");	return 1;
		}
	}

	for (b = 0; b < 3; b++) { //���� ���� �� X or O �̸� ��ȯ�Ѵ�.
		if (board[1][b] == 'O' && board[2][b] == 'O' && board[0][b] == 'O')
		{
			printf("PLAYER2�� �¸��ϼ̽��ϴ�."); return 1;
		}

		else if (board[1][b] == 'X' && board[2][b] == 'X' && board[0][b] == 'X')
		{
			printf("PLAYER1�� �¸��ϼ̽��ϴ�."); return 1;
		}
	}

	//����� �밢�� ���߸� ��ȯ
	if ((board[1][1] == 'O' && board[0][0] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
	{
		printf("PLAYER2�� �¸��ϼ̽��ϴ�."); return 1;
	}
	if ((board[1][1] == 'X' && board[0][0] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
	{
		printf("PLAYER1�� �¸��ϼ̽��ϴ�."); return 1;
	}

	if (n == 9) { //���� ����Ƚ���� 9���̸� ���º�
		printf("���º�"); return 1;
	}
}