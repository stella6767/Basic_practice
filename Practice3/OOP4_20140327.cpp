#include <iostream>
#include <string>
#include <cstring> //strstr �Լ��� �����

using namespace std;

int main()
{
	/*int num=0,emp=0,chr=0,i; //���� ���� �ʱ�ȭ
	char str[20]; //20�� �̳� ���� �迭����

	cout<<"���ڿ��� �Է�(20�� �̳�): ";
	gets(str); //���ڿ� �Է��Լ�

	for(i=0;str[i]!='\0';i++){ //'\0'�� ���ڿ� ������ �������� ����
		if(('A'<=str[i]&&str[i]<='Z')||('a'<=str[i]&&str[i]<='z'))//���ĺ� Ȯ��
			chr++;
		else if('0'<=str[i]&&str[i]<='9')//����
			num++;
		else if(str[i]==' ')//����
			emp++;
	}
	cout<<"���ĺ� ��:"<<chr<<endl;
	cout<<" ���� ��:"<<num<<endl;
	cout<<" ���� ��:"<<emp<<endl;

	int num=0,i; //���� ����� ����
	char str[20];

	cout<<"���ڿ� �Է�(20�� �̳�): ";
	gets(str);

	for(i=0; str[i]!='\0'; i++){ //���ڿ� ù��° �������� ���������� �ݺ�
		if(str[i]==' ')	//���� �� ������ �����̶��
			num++; //+1
	}
	cout<<num+1; //���� ��ģ ���ڿ� +1
		*/

	char one[100] = { 0, };
	char find[10] = { 0, };
	char* first;
	char* last;

	char change[10] = { 0, };
	char tmp[10] = { 0, };

	int i;

	cout << "���� ���ڿ� : ";
	cin.getline(one, 100); //cin.getline(char*,int cnt)�� ���������� �����Ͽ� �迭�� �ֽ��ϴ�.
								//����ڰ� ���� ġ�� �������� ��� ���ڿ��� ��Ե˴ϴ�.

	cout << "ã�� ���ڿ� : ";
	cin.getline(find, 10);
	cout << "�ٲ� ���ڿ� : ";
	cin.getline(change, 10);

	for (i = 0; i < strlen(one); i++) { //one �̶� �迭�� ��� �Ⱦ�ϴ�.
		first = &one[i]; // �Ⱦ�� ������ first.

		if (strncmp(first, find, strlen(find)) == 0) { //first�������� ã�� �ܾ��� ũ����� �ܾ ���ٸ�
		 //�������� �ٲ�����ϴ�.

			last = &one[i + strlen(find)]; // last�� �ٲ���� �ܾ� ������ ������ ����ϴ�.
			strncpy(tmp, change, strlen(change)); // last ���ķ� �ٲ� ���ڿ��� �ְ�,
			strncat(tmp, last, strlen(last)); // �����ĵ� �� �ֽ��ϴ�.
			strncpy(first, tmp, strlen(tmp)); // �ٲ� ���ڿ��� ù ��ġ���� tmp�� ������ �ٲ�ϴ�.

			memset(tmp, '\0', sizeof(tmp)); // �ӽù迭 �ʱ�ȭ
		}
	}
	cout << "��� ���ڿ� : ";
	cout << one << endl;

	return 0;
}