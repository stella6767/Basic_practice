#include <stdio.h>
#include <stdlib.h>

void init_board(char board[][3]);
int get_player_move(int player, char board[][3]);
void disp_board(char board[][3]);
int check_board(char board[3][3]);

int main(void) {
	char board[3][3];      //2차원 배열 변수 선언
	int quit = 0;        //종료 변수 선언

	init_board(board);      //init_board함수를 호출하는데 "board"변수 인자를 전달한다.
	do { //do(s)
		disp_board(board);     //보드를 출력하는 함수를 호출한다.
		quit = check_board(board);
		quit = get_player_move(0, board);  //사용자입력을 받는 보드를 호출한다.(1번 플레이어) *1번플레이어는 0*
		if (quit == 1) break;     //만약 "quit"함수가 1일경우 do_while문을 빠져나간다.
		disp_board(board);
		quit = get_player_move(1, board);  //사용자입력을 받는 보드를 호출한다.(2번 플레이어) *2번플레이어는 1*
		if (quit == 1) break;     //만약 "quit"함수가 1일경우 do_while문을 빠져나간다.
	} while (quit == 0);
	//do(e)
	return 0;
}

void init_board(char board[][3]) {   //빈 board의 함수
	int x, y;        //x,y for문을 돌리는 변수 선언
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			board[x][y] = ' ';    //2차원 배열을 스페이스 1칸으로 초기화시킨다.
}

int get_player_move(int player, char board[3][3]) { //사용자에게 입력을 기다리는 함수
	int x, y, done = 0;      //변수 x,y,done의 초기화

	while (done != 1) { //while(s)
		printf("(x,y) 좌표 (종료 -1, -1):"); //사용자에게 문자열를 출력한다.
		fflush(stdout);
		scanf("%d %d", &x, &y);
		if (x == -1 && y == -1) return 1;  //만약 x와 y가 -1일 경우 1을 리턴한다.(종료조건)
		if (board[x][y] == ' ') break;   //"board[x][y]"가 올바른위치 즉,스페이스칸일경우 반복문을 빠져나간다.
		else printf("잘못된 위치입니다.");  //잘못된위치일경우 출력되는 문자열
	} //while(e)
	if (player == 0) board[x][y] = 'X';  //플레이어 1일경우 'X'
	else board[x][y] = 'O';     //플레이어 2일경우 'O'를 출력한다.
	return 0;
}

void disp_board(char board[3][3]) {   //보드의 현재상태를 화면에 출력하는 함수
	int i;
	for (i = 0; i < 3; i++) { //for(s)
		printf("---|---|---\n");

		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
	} //for(e)
	printf("---|---|---\n");
}

int check_board(char board[3][3]) {   //승자를 출력하는 함수
	int a, b;

	for (a = 0; a < 3; a++)
		if (board[a][1] == 'O' && board[a][2] == 'O' && board[a][0] == 'O')
		{
			printf("PLAYER2가 승리하셨습니다.");
			return 0;
		}
		else if (board[a][1] == 'X' && board[a][2] == 'X' && board[a][0] == 'X')
		{
			printf("PLAYER1이 승리하셨습니다.");
			return 0;
		}

	for (b = 0; b < 3; b++)
		if (board[1][b] == 'O' && board[2][b] == 'O' && board[0][b] == 'O')
		{
			printf("PLAYER2가 승리하셨습니다."); return 0;
		}
		else if (board[1][b] == 'X' && board[2][b] == 'X' && board[0][b] == 'X')
		{
			printf("PLAYER1이 승리하셨습니다."); return 0;
		}
	if ((board[1][1] == 'O' && board[0][0] == 'O' && board[2][2] == 'O') ||
		(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
	{
		printf("PLAYER2가 승리하셨습니다."); return 0;
	}
	if ((board[1][1] == 'X' && board[0][0] == 'X' && board[2][2] == 'X') ||
		(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
	{
		printf("PLAYER1이 승리하셨습니다."); return 0;
	}
}