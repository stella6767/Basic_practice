#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char s;

	printf("입력: ");
	scanf("%c", &s);

	if (isalpha(s) != 0) {
		printf("영문자입니다.\n");
	}

	if (isupper(s) != 0) {
		s = tolower(s);
		printf("%c", s);
	}

	if (islower(s) != 0) {
		s = toupper(s);
		printf("%c", s);
	}

	if (isdigit(s) != 0) {
		s = toascii(s);
		printf("%c", s);
	}

	if (ispunct(s) != 0) {
		printf("구두점");
	}

	return 0;
}