#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char* argv[]) {
	FILE* fp1, * fp2;
	char file1[100], file2[100];
	char buffer[100];

	pritnf("���� ���� �̸�: ");
	scanf("%s", file1);

	pritnf("���� ���� �̸�: ");
	scanf("%s", file2);

	if ((fp1 = fopen(file1, "r")) == NULL)
	{
		fprintf(stderr, "���� ���� %s�� �� �� �����ϴ�.\n", file1);
		exit(1);
	}

	if ((fp2 = fopen(file2, "w")) == NULL)
	{
		fprintf(stderr, "���� ���� %s�� �� �� �����ϴ�.\n", file2);
		exit(1);
	}

	while (fgets(buffer, 100, fp1) != NULL)
		fputs(buffer, fp2);

	fclose(fp1);
	fclose(fp2);

	return 0;
}