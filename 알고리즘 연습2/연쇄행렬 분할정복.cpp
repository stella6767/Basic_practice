#include<iostream>
#include<algorithm>

using namespace std;
int dp[100][100] ;

// Function for matrix chain multiplication 
int matrixChainMemoised(int C[], int i, int j) {
    if (i == j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {
        dp[i][j] = min(
            dp[i][j], matrixChainMemoised(C, i, k)
            + matrixChainMemoised(C, k + 1, j)
            + C[i - 1] * C[k] * C[j]);
    }
    return dp[i][j];
}


int mat_chain_X_DP(int C[ ], int n) {
    int S[100][100], T[100][100];
    int d, i, j, k;
    for (i=1; i<=n; i++) S[i][i] = T[i][i] = 0;
    for (d = 1; d <= n-1; d++)
        for (i = 1; i <= n-d; i++) {
        j = i + d; 
        S[i][j] =INT_MAX;
        for (k = i; k <= j-1; k++) {
            if (S[i][k]+S[k+1][j]+C[i-1]*C[k]*C[j] < S[i][j]) {
                S[i][j] = S[i][k]+S[k+1][j]+C[i-1]*C[k]*C[j]; 
                T[i][j] = k;
            }
        }
    }
    return S[1][n];
}



// Driver Code 
int main() {
    int C[] = { 9, 3, 12, 2, 10, 4 };
    memset(dp, -1, sizeof dp);
    cout << "Minimum number of multiplications is "
        << matrixChainMemoised(C, 1,5);
}