#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char s;

	printf("�Է�: ");
	scanf("%c", &s);

	if (isalpha(s) != 0) {
		printf("�������Դϴ�.\n");
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
		printf("������");
	}

	return 0;
}