#include <iostream>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void copy(int* A, int* B, int n); //��ȯ�� ����  int �� �Ű����� 2���� �ݺ����� �� �Ű�����

void get_stat(double A[], double* p_avg, double* p_max, double* p_sum); //�迭�� �����͸� ����

int mai(int argc, char** argv) {
	double num[10] = { 0 }; //10�� ������ �Ǽ� �ڷḦ �迭�� �����ϱ� ����
	double sum1 = 0, sum2 = 0, m, v, s;//���,�л�,ǥ�غ��� ��꿡 �ʿ�
	int n, i = 0;//�Ǽ� �ڷ� ����, �ݺ��� ����

	cout << "10�� ������ ���� :";
	cin >> n;

	cout << "�Ǽ� �Է�: " << endl;

	if (n <= 10) { //�Ǽ� ������ 10�� ���ϸ�
		for (i = 0; i < n; i++) {
			cin >> num[i]; //n����ŭ �Ǽ��Է�
			sum1 += num[i]; //�Ǽ� ����
		}
		m = sum1 / n; //�Ǽ� ������ ���

		for (i = 0; i < n; i++)
			sum2 += (num[i] - m) * (num[i] - m);
		v = sum2 / n; //�л�
		s = sqrt(v);//ǥ������

		cout << "���: " << m << endl;
		cout << "�л�: " << v << endl;
		cout << "ǥ������: " << s << endl;
	}

	/*int matrix[3][5]={{12,56,32,16,98},
					 {99,56,34,41,3},//3�� 5���� ������ �迭�� ����� �������� ���� �������
					 {65,3,87,78,21}};
		int sum=0,n,i;

		for(n=0;n<3;n++) //���� 3�� ����
		{
			for(i=0;i<5;i++){  //�ึ�� 5�� ���� ���� �ݺ�
				sum+=matrix[n][i];} // sum���� ������ ���� ����

			cout<<n+1<<"���� �հ�: "<<sum<<endl; //1��° ���� �հ� ���
			sum=0;//sum �� �ʱ�ȭ �� �ٽ� �ٱ� for������
		}

		for(i=0;i<5;i++) //���� 5��
		{
			for(n=0;n<3;n++){
				sum+=matrix[n][i];}
			cout<<i+1<<"���� �հ�: "<<sum<<endl;
			sum=0;
		}

		int A[10]={1,2,3,4,5,6,7,8,9,10}; //������ �迭 ����
		int B[10]; //������� �迭�� ������� ����
		copy(A, B, 10); //�Լ� ȣ�� -a�� 10���� ���� b��� �迭�� ����
		*/

	double matrix[5] = { 1.1, 2.2,5.5,4.4,3.3 }; //�Ǽ��� �迭 ����
	double p_avg, p_max, p_sum;
	get_stat(matrix, &p_avg, &p_max, &p_sum);
	cout << " �迭�����: " << p_avg << endl;
	cout << " �ִ밪: " << p_max << endl;
	cout << " ��: " << p_sum << endl;

	return 0;
}

void copy(int* A, int* B, int n) {
	int i;
	for (i = 0; i < n; i++) {
		B[i] = A[i]; //b�迭 ������� 1�� ���� a�� �迭���� ���� 1�� ��, a�� �迭 2���� ���� b�� �迭 2���� ��- 10������ �ݺ�
		cout << B[i];
	}
}

void get_stat(double A[], double* p_avg, double* p_max, double* p_sum) {
	double sum = 0; //��ü�� �� �ʱ�ȭ
	double max = 0; //�ִ밪 �ʱ�ȭ

	for (int i = 0; i < 5; i++) {
		sum += A[i]; //�ټ��� ������ �迭 ������ sum ���� ����
		if (A[i] > max) //�ټ��� ���� ������ max �� ����. ���� ���� max���� ���� �迭 ������ ũ�ٸ� ����ȵ�
			max = A[i];
	}
	*p_avg = sum / 5; //��հ�
	*p_sum = sum;//����
	*p_max = max;//�ִ밪
}