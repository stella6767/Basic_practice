#include <iostream>
#include <math.h>

using namespace std;

/*int main()//연습문제 3장 3
{
	double num[10]={0}; //10개 이하의 실수 자료를 배열에 저장하기 위해
	double sum1=0,sum2=0,m,v,s;//평균,분산,표준변차 계산에 필요
	int n,i=0;//실수 자료 개수, 반복문 변수

	cout<<"10개 이하의 개수 :";
	cin>>n;

	cout<<"실수 입력: "<<endl;

	if(n<=10){ //실수 개수가 10개 이하면
	for(i=0;i<n;i++){
		cin>>num[i]; //n번만큼 실수입력
		sum1 += num[i]; //실수 총합
	}
	m=sum1/n; //실수 총합의 평균

	for(i=0;i<n;i++)
		sum2 += (num[i]-m)*(num[i]-m);
	v=sum2/n; //분산
	s=sqrt(v);//표준편차

	cout<<"평균: "<<m<<endl;
	cout<<"분산: "<<v<<endl;
	cout<<"표준편차: "<<s<<endl;
	}

	return 0;
}*/

int n()//연습문제 3장 5번
{
	int matrix[3][5] = { {12,56,32,16,98}, //3행 5열의 이차원 배열을 만들고 변수마다 값을 집어넣음
				 {99,56,34,41,3},
				 {65,3,87,78,21} };
	int sum = 0, n, i;

	for (int n = 0; n < 3; n++) //행을 3번 돌림
	{
		for (i = 0; i < 5; i++) {  //행마다 5개 열의 채워질때까지
			sum += matrix[n][i];
		}

		cout << n + 1 << "행의 합계: " << sum << endl;
		sum = 0;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int n = 0; n < 3; n++) {
			sum += matrix[n][i];
		}
		cout << i + 1 << "열의 합계: " << sum << endl;
		sum = 0;
	}
	return 0;
}