#include<iostream>
#include<string>
#include<memory.h>
#include<time.h>
using namespace std;
int dp[16][16];
//�׽�Ʈ ���̽� ���ڿ� a�� b�� ���̴� �ִ� 15
//dp[i][j]=a���ڿ� i��°���� b���ڿ� j��° ���� ��������� 
//c���ڿ��� ���ù��ڿ��� �������� �Ұ��������� ��Ÿ��
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
				//dp[j-1][k]�� ���̸鼭 c[j+k-1]�� a[j-1]�� ������
				//dp[j][k]�� dp[j-1][k]�� ���� �ִ´�.
				dp[j][k] = dp[j - 1][k];
			}
			if ((k > 0) && (c[j + k - 1] == b[k - 1]) && (dp[j][k - 1])) {
				//dp[j-1][k]�� ���̸鼭 c[j+k-1]�� b[k-1]�� ������
				//dp[j][k]�� dp[j][k-1]�� ���� �ִ´�.
				dp[j][k] = dp[j][k - 1];
			}
		}
	}
	if (dp[aLen][bLen]) {     //solve(a.length(), b.length())�� üũ 
		cout << "yes\n";      //���̸� yes
	}
	else {
		cout << "no\n";       //�����̸� no ���
	}
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false); //����¼ӵ����
	clock_t start, end;
	double result;
	start = clock();
	int t;
	cin >> t;										//�׽�Ʈ ���̽� ���� �Է�
	for (int i = 0; i < t; i++) {
		cin >> a >> b >> c;
		memset(dp, 0, sizeof(dp));					//dp���̺� �ʱ�ȭ
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