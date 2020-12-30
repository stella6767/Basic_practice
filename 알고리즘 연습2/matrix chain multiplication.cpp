#include<iostream>

using namespace std;

#define MIN(A, B) ((A)>(B)?(B):(A))
#define MAX_VALUE 9999999
#define MAX_SIZE 101

int S[MAX_SIZE][MAX_SIZE];
int c[MAX_SIZE];
int T[MAX_SIZE][MAX_SIZE];

int main()
{
    int size = 6;

    c[0] = 9, c[1] = 3, c[2] = 12, c[3] = 2, c[4] = 10; c[5] = 4;

    for (int diagonal = 0; diagonal < size; diagonal++)
    {
        for (int i = 1; i <= size - diagonal; i++)
        {
            int j = i + diagonal;
            if (j == i)
            {
                S[i][j] = 0;
                T[i][j] = 0;
                continue;
            }
            S[i][j] = MAX_VALUE;
            for (int k = i; k <= j - 1; k++)
                if (S[i][k] + S[k + 1][j] + c[i - 1] * c[k] * c[j] < S[i][j]) {
                     S[i][j] = S[i][k] + S[k + 1][j] + c[i - 1] * c[k] * c[j];
                     T[i][j] = k;                    
                }
                

        }
    }

    /*결과 출력*/
    cout << S[1][size] << endl;
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            cout << S[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }




    cout << 9 * 3 * 12;
    return 0;
}
