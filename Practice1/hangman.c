#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void print_word();
void get();
int check(int correct[10], int len);

int mdddd(int argc, char* argv[]) {
	int i, len, num, result;
	char word[3][10] = { "apple","banana","eyes" };
	int correct[10] = { 0 };
	char problem[10];

	srand(time(NULL));

	num = rand() % 3;
	strcpy(problem, word[num]);
	len = strlen(problem);

	printf("%s \n", word[num]);

	for (i = 0; i < 5; i++) {
		print_word(problem, correct, len);
		get(problem, correct, len);
		result = check(correct, len);

		if (result == 1) {
			printf("살림");
			return 0;
		}
	}
	if (result == 0)
		printf("죽임");

	return 0;
}

void print_word(char problem[10], int correct[10], int len) {
	int i;

	for (i = 0; i < len; i++) {
		if (correct[i] == 0)
			printf("_");
		else
			printf("%c", problem[i]);
	}
	printf("\n");
}

void get(char problem[10], int correct[10], int len) {
	int i;
	char a;

	printf("입력 글자: ");
	scanf("%c", &a);
	fflush(stdin);

	for (i = 0; i < len; i++) {
		if (problem[i] == a)
			correct[i] = 1;
	}
}

int check(int correct[10], int len) {
	int i;

	for (i = 0; i < len; i++) {
		if (correct[i] != 1)
			return 0;
	}

	return 1;
}