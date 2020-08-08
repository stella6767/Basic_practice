#include <stdio.h>
#include <stdlib.h>

void display_pan(char board[][3]); // 게임판 출력 함수
int player_move(int player, char board[][3]); //돌을 놓을 수 있는지 확인하는 함수
int winner_check(char board[][3], int n); // 승자 여부 확인 함수

int mssssn()
{
	char board[3][3]; //문자형 2차원 배열 선언
	int end = 0; //종료 변수 선언
	int x, y; //값 초기화 하기 위한 반복문 변수
	int choice = 0; //진행 횟수 변수

	for (x = 0; x < 3; x++) // 선언한 2차원 배열 공간안의 값을 초기화
		for (y = 0; y < 3; y++)
			board[x][y] = ' ';

	do {    //일단 시작
		display_pan(board); //판 호출
		end = winner_check(board, choice); //종료 변수에 이 함수 리턴값 대입
		if (end == 1) //종료변수가 1이라면 반복문 do while문 빠져나감
			break;
		end = player_move(0, board);  //사용자입력을 받는 보드를 호출(1번플레이어는 0)
		choice++; //위의 함수가 정상적으로 수행되었으면 진행값 1 증가
		if (end == 1)
			break;     //이하동문
		display_pan(board);
		end = winner_check(board, choice);
		if (end == 1) //먼저 한 줄 완성한 사람이 승자
			break;
		end = player_move(1, board);  //사용자입력을 받는 보드를 호출한다.(2번 플레이어) *2번플레이어는 1*
		choice++; //역시 마찬가지로 위의 2번 플레이어도 정상수행하면 횟수 증가
		if (end == 1)
			break;
	} while (end == 0); //end 값이 0이면 무한 반복

	return 0;
}

void display_pan(char board[][3]) { //게임판 출력함수
	int i;

	for (i = 0; i < 3; i++) {
		printf("---|---|---\n");
		printf("%c  | %c | %c \n", board[i][0], board[i][1], board[i][2]); //이 공간에 배열 값 표시하도록 함
	}
	printf("---|---|---\n");
}

int player_move(int player, char board[3][3]) { //플레이어 설정 변수와 배열
	int x, y;
	int go = 0;//종료변수

	while (go != 1) { //종료변수가 1이 아니면
		printf("(x,y) 좌표 (종료 -1, -1):"); //사용자에게 문자열를 출력하게 함
		scanf("%d %d", &x, &y);

		if (x == -1 && y == -1)
			return 1;  //만약 x와 y가 -1일 경우 1을 리턴(종료변수에 대입시킬)
		if (board[x][y] == ' ')
			break;   //"board[x][y]"가 스페이스칸일경우 반복문을 빠져나감
		else
			printf("잘못된 위치입니다.");  //잘못된위치일경우 출력되는 문자열
	}

	if (player == 0) board[x][y] = 'X';  //플레이어 1일경우 'X'
	else board[x][y] = 'O';     //플레이어 2일경우 'O'를 출력
	return 0;
}

int winner_check(char board[][3], int n) {   //배열과 진행횟수값.
	int a, b;

	for (a = 0; a < 3; a++) { //행이 전부 다 X or O 이면 반환한다
		if (board[a][1] == 'O' && board[a][2] == 'O' && board[a][0] == 'O')
		{
			printf("PLAYER2가 승리하셨습니다.");	return 1;
		}

		else if (board[a][1] == 'X' && board[a][2] == 'X' && board[a][0] == 'X')
		{
			printf("PLAYER1이 승리하셨습니다.");	return 1;
		}
	}

	for (b = 0; b < 3; b++) { //열이 전부 다 X or O 이면 반환한다.
		if (board[1][b] == 'O' && board[2][b] == 'O' && board[0][b] == 'O')
		{
			printf("PLAYER2가 승리하셨습니다."); return 1;
		}

		else if (board[1][b] == 'X' && board[2][b] == 'X' && board[0][b] == 'X')
		{
			printf("PLAYER1이 승리하셨습니다."); return 1;
		}
	}

	//여기는 대각선 맞추면 반환
	if ((board[1][1] == 'O' && board[0][0] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
	{
		printf("PLAYER2가 승리하셨습니다."); return 1;
	}
	if ((board[1][1] == 'X' && board[0][0] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
	{
		printf("PLAYER1이 승리하셨습니다."); return 1;
	}

	if (n == 9) { //만약 진행횟수가 9번이면 무승부
		printf("무승부"); return 1;
	}
}