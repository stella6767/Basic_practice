#include <iostream>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void copy(int* A, int* B, int n); //반환값 없음  int 형 매개변수 2개와 반복문에 쓸 매개변수

void get_stat(double A[], double* p_avg, double* p_max, double* p_sum); //배열의 포인터를 받음

int mai(int argc, char** argv) {
	double num[10] = { 0 }; //10개 이하의 실수 자료를 배열에 저장하기 위해
	double sum1 = 0, sum2 = 0, m, v, s;//평균,분산,표준변차 계산에 필요
	int n, i = 0;//실수 자료 개수, 반복문 변수

	cout << "10개 이하의 개수 :";
	cin >> n;

	cout << "실수 입력: " << endl;

	if (n <= 10) { //실수 개수가 10개 이하면
		for (i = 0; i < n; i++) {
			cin >> num[i]; //n번만큼 실수입력
			sum1 += num[i]; //실수 총합
		}
		m = sum1 / n; //실수 총합의 평균

		for (i = 0; i < n; i++)
			sum2 += (num[i] - m) * (num[i] - m);
		v = sum2 / n; //분산
		s = sqrt(v);//표준편차

		cout << "평균: " << m << endl;
		cout << "분산: " << v << endl;
		cout << "표준편차: " << s << endl;
	}

	/*int matrix[3][5]={{12,56,32,16,98},
					 {99,56,34,41,3},//3행 5열의 이차원 배열을 만들고 변수마다 값을 집어넣음
					 {65,3,87,78,21}};
		int sum=0,n,i;

		for(n=0;n<3;n++) //행을 3번 돌림
		{
			for(i=0;i<5;i++){  //행마다 5개 열의 값을 반복
				sum+=matrix[n][i];} // sum에다 열마다 값을 축적

			cout<<n+1<<"행의 합계: "<<sum<<endl; //1번째 부터 합계 출력
			sum=0;//sum 값 초기화 후 다시 바깥 for문으로
		}

		for(i=0;i<5;i++) //열을 5번
		{
			for(n=0;n<3;n++){
				sum+=matrix[n][i];}
			cout<<i+1<<"열의 합계: "<<sum<<endl;
			sum=0;
		}

		int A[10]={1,2,3,4,5,6,7,8,9,10}; //복사할 배열 선언
		int B[10]; //복사당할 배열의 저장공간 선언
		copy(A, B, 10); //함수 호출 -a의 10개의 값을 b라는 배열에 복사
		*/

	double matrix[5] = { 1.1, 2.2,5.5,4.4,3.3 }; //실수형 배열 선언
	double p_avg, p_max, p_sum;
	get_stat(matrix, &p_avg, &p_max, &p_sum);
	cout << " 배열의평균: " << p_avg << endl;
	cout << " 최대값: " << p_max << endl;
	cout << " 합: " << p_sum << endl;

	return 0;
}

void copy(int* A, int* B, int n) {
	int i;
	for (i = 0; i < n; i++) {
		B[i] = A[i]; //b배열 저장공간 1의 값은 a의 배열공간 저장 1의 값, a의 배열 2번의 값은 b의 배열 2번의 값- 10번까지 반복
		cout << B[i];
	}
}

void get_stat(double A[], double* p_avg, double* p_max, double* p_sum) {
	double sum = 0; //전체합 값 초기화
	double max = 0; //최대값 초기화

	for (int i = 0; i < 5; i++) {
		sum += A[i]; //다섯번 돌리며 배열 값들을 sum 값에 축적
		if (A[i] > max) //다섯번 돌릴 때마다 max 값 갱신. 만약 전의 max값이 다음 배열 값보다 크다면 시행안됨
			max = A[i];
	}
	*p_avg = sum / 5; //평균값
	*p_sum = sum;//총합
	*p_max = max;//최대값
}