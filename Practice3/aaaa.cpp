#include <iostream>
#include <math.h>

using namespace std;

/*int main()//�������� 3�� 3
{
	double num[10]={0}; //10�� ������ �Ǽ� �ڷḦ �迭�� �����ϱ� ����
	double sum1=0,sum2=0,m,v,s;//���,�л�,ǥ�غ��� ��꿡 �ʿ�
	int n,i=0;//�Ǽ� �ڷ� ����, �ݺ��� ����

	cout<<"10�� ������ ���� :";
	cin>>n;

	cout<<"�Ǽ� �Է�: "<<endl;

	if(n<=10){ //�Ǽ� ������ 10�� ���ϸ�
	for(i=0;i<n;i++){
		cin>>num[i]; //n����ŭ �Ǽ��Է�
		sum1 += num[i]; //�Ǽ� ����
	}
	m=sum1/n; //�Ǽ� ������ ���

	for(i=0;i<n;i++)
		sum2 += (num[i]-m)*(num[i]-m);
	v=sum2/n; //�л�
	s=sqrt(v);//ǥ������

	cout<<"���: "<<m<<endl;
	cout<<"�л�: "<<v<<endl;
	cout<<"ǥ������: "<<s<<endl;
	}

	return 0;
}*/

int n()//�������� 3�� 5��
{
	int matrix[3][5] = { {12,56,32,16,98}, //3�� 5���� ������ �迭�� ����� �������� ���� �������
				 {99,56,34,41,3},
				 {65,3,87,78,21} };
	int sum = 0, n, i;

	for (int n = 0; n < 3; n++) //���� 3�� ����
	{
		for (i = 0; i < 5; i++) {  //�ึ�� 5�� ���� ä����������
			sum += matrix[n][i];
		}

		cout << n + 1 << "���� �հ�: " << sum << endl;
		sum = 0;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int n = 0; n < 3; n++) {
			sum += matrix[n][i];
		}
		cout << i + 1 << "���� �հ�: " << sum << endl;
		sum = 0;
	}
	return 0;
}