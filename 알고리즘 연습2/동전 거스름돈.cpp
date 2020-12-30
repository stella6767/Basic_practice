#include <iostream>
#include<queue>
#include <algorithm>

using namespace std;

//int coins[5] = { 500,130,100,50,10 };
//
//int coinChange(int amount) {
//    if (amount == 0) return 0;
//    if (amount < 0) return -1;
//
//    int minn = -1;
//    for (int coin : coins) {
//        int currentMin = coinChange(amount - coin);
//
//        // if amount is less than coin value
//        if (currentMin >= 0) {
//            minn = minn < 0 ? currentMin : min(currentMin, minn);
//        }
//    }
//
//    return minn < 0 ? -1 : minn + 1;
//}
#define MAX 10000
#define infi 100000

int W[5] = { 500,130,100,50,10 };
int CC[MAX] = { 0 };
int B[];



int coin_change_making_DP(int W[], int n, int M) {
    int C[MAX] = { 0 }, i, k;
    int B[MAX] = { 0 };
    for (i = 10; i <= M; i = i + 10)    
        for (C[i]=INT_MAX, k = 1; k <= n; k++)  //�̷� ���� FOR���� �����ϱ���!!!!!!  ���� �� �����ؾ��� �����ذᵵ �����ϰ�, 
            if (i >= W[k] && C[i - W[k]] + 1 < C[i]) {  //�ּ�Ƚ���� ����ؾ��ϱ� ������ C[] ��� �ƽ������� ä�����Ѵ�.
                C[i] = C[i - W[k]] + 1;
                B[i] = i - W[k];
            }
    return C[M];
}




//// CC[MAX]={0}�� B[]�� ��������
//void count_coins() {
//    
//    int i = 5;
//    //int i = M;
//    while (i > 0) {
//        CC[(i - B[i])]++;
//        i = B[i];
//    }
//}
//
//// CC[MAX]={0}�� B[]�� ��������, i=M���� ȣ��
//void count_coins_R(int i) {
//    CC[(i - B[i])]++;
//    count_coins_R(i - B[i]);
//}


int main() {

    cout << coin_change_making_DP(W, 5, 150)<<endl;

   
	
}