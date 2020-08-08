#include <stdio.h>

void boardpan();

int main()

{
	char board[3][3];
	int x, y, k, i;

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			board[x][y] = ' ';

	for (k = 0; k < 9; k++) {
		printf("(x,y) ÁÂÇ¥: ");
		scanf(" %d  %d", &x, &y);
		board[x][y] = (k % 2 == 0) ? 'X' : 'O';

		boardpan(board);
	}

	return 0;
}

void boardpan(char board[3][3]) {
	int i;
	for (i = 0; i < 3; i++) {
		printf("---|---|---\n");
		printf("%c  | %c | %c \n", board[i][0], board[i][1], board[i][2]);
	}
	printf("---|---|---\n");
}