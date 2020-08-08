#include <stdio.h>
#include <stdlib.h>

void init_board(char board[][3]);
int get_player_move(int player, char board[][3]);
void disp_board(char board[][3]);
int check_board(char board[3][3]);

int main(void) {
	char board[3][3];      //2���� �迭 ���� ����
	int quit = 0;        //���� ���� ����

	init_board(board);      //init_board�Լ��� ȣ���ϴµ� "board"���� ���ڸ� �����Ѵ�.
	do { //do(s)
		disp_board(board);     //���带 ����ϴ� �Լ��� ȣ���Ѵ�.
		quit = check_board(board);
		quit = get_player_move(0, board);  //������Է��� �޴� ���带 ȣ���Ѵ�.(1�� �÷��̾�) *1���÷��̾�� 0*
		if (quit == 1) break;     //���� "quit"�Լ��� 1�ϰ�� do_while���� ����������.
		disp_board(board);
		quit = get_player_move(1, board);  //������Է��� �޴� ���带 ȣ���Ѵ�.(2�� �÷��̾�) *2���÷��̾�� 1*
		if (quit == 1) break;     //���� "quit"�Լ��� 1�ϰ�� do_while���� ����������.
	} while (quit == 0);
	//do(e)
	return 0;
}

void init_board(char board[][3]) {   //�� board�� �Լ�
	int x, y;        //x,y for���� ������ ���� ����
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			board[x][y] = ' ';    //2���� �迭�� �����̽� 1ĭ���� �ʱ�ȭ��Ų��.
}

int get_player_move(int player, char board[3][3]) { //����ڿ��� �Է��� ��ٸ��� �Լ�
	int x, y, done = 0;      //���� x,y,done�� �ʱ�ȭ

	while (done != 1) { //while(s)
		printf("(x,y) ��ǥ (���� -1, -1):"); //����ڿ��� ���ڿ��� ����Ѵ�.
		fflush(stdout);
		scanf("%d %d", &x, &y);
		if (x == -1 && y == -1) return 1;  //���� x�� y�� -1�� ��� 1�� �����Ѵ�.(��������)
		if (board[x][y] == ' ') break;   //"board[x][y]"�� �ùٸ���ġ ��,�����̽�ĭ�ϰ�� �ݺ����� ����������.
		else printf("�߸��� ��ġ�Դϴ�.");  //�߸�����ġ�ϰ�� ��µǴ� ���ڿ�
	} //while(e)
	if (player == 0) board[x][y] = 'X';  //�÷��̾� 1�ϰ�� 'X'
	else board[x][y] = 'O';     //�÷��̾� 2�ϰ�� 'O'�� ����Ѵ�.
	return 0;
}

void disp_board(char board[3][3]) {   //������ ������¸� ȭ�鿡 ����ϴ� �Լ�
	int i;
	for (i = 0; i < 3; i++) { //for(s)
		printf("---|---|---\n");

		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
	} //for(e)
	printf("---|---|---\n");
}

int check_board(char board[3][3]) {   //���ڸ� ����ϴ� �Լ�
	int a, b;

	for (a = 0; a < 3; a++)
		if (board[a][1] == 'O' && board[a][2] == 'O' && board[a][0] == 'O')
		{
			printf("PLAYER2�� �¸��ϼ̽��ϴ�.");
			return 0;
		}
		else if (board[a][1] == 'X' && board[a][2] == 'X' && board[a][0] == 'X')
		{
			printf("PLAYER1�� �¸��ϼ̽��ϴ�.");
			return 0;
		}

	for (b = 0; b < 3; b++)
		if (board[1][b] == 'O' && board[2][b] == 'O' && board[0][b] == 'O')
		{
			printf("PLAYER2�� �¸��ϼ̽��ϴ�."); return 0;
		}
		else if (board[1][b] == 'X' && board[2][b] == 'X' && board[0][b] == 'X')
		{
			printf("PLAYER1�� �¸��ϼ̽��ϴ�."); return 0;
		}
	if ((board[1][1] == 'O' && board[0][0] == 'O' && board[2][2] == 'O') ||
		(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
	{
		printf("PLAYER2�� �¸��ϼ̽��ϴ�."); return 0;
	}
	if ((board[1][1] == 'X' && board[0][0] == 'X' && board[2][2] == 'X') ||
		(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
	{
		printf("PLAYER1�� �¸��ϼ̽��ϴ�."); return 0;
	}
}