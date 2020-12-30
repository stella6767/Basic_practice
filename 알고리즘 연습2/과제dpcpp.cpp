#include<iostream>
#include<string>
#include<memory.h>
#include<time.h>
using namespace std;
int dp[16][16];
//테스트 케이스 문자열 a와 b의 길이는 최대 15
//dp[i][j]=a문자열 i번째까지 b문자열 j번째 까지 사용했을때 
//c문자열이 셔플문자열이 가능한지 불가능한지를 나타냄
string a, b, c;
int aLen;
int bLen;
void solve() {
	for (int j = 0; j <= aLen; j++) {
		for (int k = 0; k <= bLen; k++) {
			if (j == 0 && k == 0) {
				dp[j][k] = 1;
			}
			if ((j > 0) && (c[j + k - 1] == a[j - 1]) && (dp[j - 1][k])) {
				//dp[j-1][k]가 참이면서 c[j+k-1]과 a[j-1]이 같으면
				//dp[j][k]에 dp[j-1][k]즉 참을 넣는다.
				dp[j][k] = dp[j - 1][k];
			}
			if ((k > 0) && (c[j + k - 1] == b[k - 1]) && (dp[j][k - 1])) {
				//dp[j-1][k]가 참이면서 c[j+k-1]과 b[k-1]이 같으면
				//dp[j][k]에 dp[j][k-1]즉 참을 넣는다.
				dp[j][k] = dp[j][k - 1];
			}
		}
	}
	if (dp[aLen][bLen]) {     //solve(a.length(), b.length())를 체크 
		cout << "yes\n";      //참이면 yes
	}
	else {
		cout << "no\n";       //거짓이면 no 출력
	}
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false); //입출력속도향상
	clock_t start, end;
	double result;
	start = clock();
	int t;
	cin >> t;										//테스트 케이스 개수 입력
	for (int i = 0; i < t; i++) {
		cin >> a >> b >> c;
		memset(dp, 0, sizeof(dp));					//dp테이블 초기화
		cout << "Test case " << (i + 1) << ": ";
		aLen = a.length();
		bLen = b.length();
		solve();
	}
	end = clock();
	cout << (double)(end - start) / 1000 << "SEC"<<endl;

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			cout << dp[i][j];
		}
		cout << endl;
	}

	return 0;
}