#include<stdlib.h>
#include<time.h>
#include<stdio.h>

int arr[10];

void print(int bit)
{
    int idx = 0;
    while (bit)
    {
        if (bit & 1)
        {
            printf("%d ", arr[idx]);
        }
        bit >>= 1;
        idx++;
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));

    int t = 10;
    while (t--)
    {
        int len = rand() % 5 + 1;

        printf("nums : ");
        for (int i = 0; i < len; i++)
        {
            arr[i] = rand() % 10;
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("sub set\n");

        for (int i = 0; i < (1 << len); i++)
        {
            print(i);
        }
        printf("\n");
    }

    return 0;
}
