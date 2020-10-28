#include <iostream>
using namespace std;

void
InitLargeInt(int X[], int n)//0으로 초기화
{
	for (int j = 0; j < n; j++)
		X[j] = 0;
}

/*
void
ShiftLargeInt (int X[], int n, int m)
{
	for (int j = n-1; j >= 0; j--) {
		X[j+m] = X[j];
		X[j]=0;
	}
}
*/

void
ReadLargeInt(int X[], int n)
{
	int i = 0;
	int* T = new int[n]; //64디짓(n만큼) 배열 가정
	char c; //문자로 받아줌

	while ((c = getchar()) == ' '); //앞에 공백 건너뛰고 문자열 입력 엔터 입력하면 -38입력되는듯? 엔터도 문자로 쳐서 그런듯

	T[i++] = (((int)c) - 48);
	while ((c = getchar()) != ' ') T[i++] = (((int)c) - 48); //문자를 정수로 변환해서 입력해준다

	for (int j = 0; j < i; j++) {
		X[j] = T[i - j - 1];   //자리바꿈
	}
}

int
AddLargeInt(int X[], int Y[], int Z[], int n, int carry_ = 0)
{
	int carry = carry_;
	int sum;
	for (int j = 0; j < n; j++)
	{
		sum = X[j] + Y[j] + carry;
		Z[j] = sum % 10;
		carry = sum / 10;
	}
	return carry;
}

void MulLargeInt(int X[], int Y[], int Z[], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Z[i + j] += X[i] * Y[j];
		}
	}

	for (int c = 0; c < 2 * n; c++)
	{
		Z[c + 1] += Z[c] / 10; //앞 자릿수를 다음 인덱스로 넘겨서 합친다.
		Z[c] %= 10; //원래 있던 숫자를 1의 자릿수로 바꿈
	}
}


//void karatsuba(int X[], int Y[], int Z[], int n) {
//
//	int half = n / 2;
//
//	if (X < Y) return karatsuba(b, a);
//	//a가 b보다 짧을 경우 둘을 바꾼다.
//	if (an == 0 || bn == 0) return vector<int>();
//	//기저사례:a나 b가 비어 있는 경우
//	if (an <= 50) return multiply(a, b);
//	//기저사례:a가 비교적 짧은 경우 O(n^2)곱셈으로 변경.
//	vector<int> a0(a.begin(), a.begin() + half);
//	vector<int> a1(a.begin() + half, a.end());
//	vector<int> b0(b.begin(), b.begin() + min<int>(half, b.size()));
//
//	vector<int> b1(b.begin() + min<int>(half, b.size()), b.end());
//	//z2=a1*b1
//	vector<int> z2 = karatsuba(a1, b1);
//	//z0=a0*b0
//	vector<int> z0 = karatsuba(a0, b0);
//
//	addTo(a0, a1, 0); addTo(b0, b1, 0);
//	//z1=(a1+a0)*(b1+b0)
//	vector<int> z1 = karatsuba(a0, b0);
//
//	subFrom(z1, z2);
//	subFrom(z1, z0);
//
//	vector<int> ret;
//	//ret=z0+z1*10^half+z2*10^(half*2)
//	addTo(ret, z0, 0);
//	addTo(ret, z1, half);
//	addTo(ret, z2, half + half);
//
//
//
//
//
//
//}

int
AddLargeInt4(int Y[], int Y00[], int Y01[], int Y10[], int Y11[], int n) // X += Y
{
	int m = n / 2;
	int sum;
	int carry = 0;
	for (int j = 0; j < n; j++)
	{
		Y[j] = Y00[j];
	}
	for (int j = 0; j < n; j++)
	{
		int sum = Y[j + m] + Y01[j] + Y10[j];
		Y[j + m] = sum % 10;
		//        carry = sum / 10;
		Y[j + m + 1] += sum / 10;
	}
	for (int j = 0; j < n; j++)
	{
		int sum = Y[j + n] + Y11[j];
		Y[j + n] = sum % 10;
		//        carry = sum / 10;
		Y[j + n + 1] += sum / 10;
	}
	return carry;
}

void
WriteLargeInt(int X[], int n)
{
	int j = n - 1;
	while (X[j] == 0 && j > 0) {
		j--;    //뒤에서부터 시작하여 0이 아닌 인덱스값까지 도달
	}
	for (; j >= 0; j--)
		cout << X[j];  //인덱스를 역순으로 출력
	cout << endl;
}
int
main()
{
	int n;
	int overFlow;
	cin >> n; //디짓(자릿수)
	int* A = new int[n]; InitLargeInt(A, n);
	int* B = new int[n]; InitLargeInt(B, n);
	int* C = new int[2 * n]; InitLargeInt(C, 2 * n);

	ReadLargeInt(A, n); //
	WriteLargeInt(A, n);
	//    ShiftLargeInt (A, n, 10);
	//    WriteLargeInt (A, n);
	ReadLargeInt(B, n);
	WriteLargeInt(B, n);

	//overFlow = AddLargeInt(A, B, C, n);

	MulLargeInt(A, B, C, n); //a,b를 곱한 값을 c 배열에 넣음
	WriteLargeInt(C, n);

	return 0;
}