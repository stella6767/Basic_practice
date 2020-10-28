#include <iostream> 
#include <stack> 
#include<vector>
using namespace std;

// Function to return the required sum 
int findMaxSum(int arr[], int n)
{

    //int cl[n]; //비주얼 스튜디오에서는 배열을 변수로 할당받거나 동적으로 할당받는거 포인터 안쓰면 불가능
    //return n; // 배열 크기는 상수로 정해져야 함. 그래서 vector로 변경

    //int n = sizeof(arr) / (sizeof(arr[0])*3);
    //vector<int> cl(n);
    //cl = { 0 };
    //vector<int> cr(n);
    //cr = { 0 };


    int* cl = new int[n]{0};  //이렇게 해야만 초기화가 가능!!!!!
    int* cr = new int[n]{0};
   

    //int cl[4] = { 0 }, cr[4] = { 0 };

    // arrays for maintaining left and right count 
    //int cl[n] = { 0 }, cr[n] = { 0 };

    // stack for storing the indexes 
    stack<int> q;

    // calculate left count for every index 
    for (int i = 0; i < n; i++) {
        while (q.size() != 0 && arr[q.top()] <= arr[i]) {
            cl[i] += cl[q.top()] + 1;
            q.pop();
        }
        q.push(i);
    }

    // clear the stack 
    while (q.size() != 0)
        q.pop();

    // calculate right count for every index 
    for (int i = n - 1; i >= 0; i--) {
        while (q.size() != 0 && arr[q.top()] < arr[i]) {
            cr[i] += cr[q.top()] + 1;
            q.pop();
        }
        q.push(i);
    }

    // clear the stack 
    while (q.size() != 0)
        q.pop();

    // to store the required sum 
    int ans = 0;

    // calculate the final sum 
    for (int i = 0; i < n; i++)
        ans += (cl[i] + 1) * (cr[i] + 1) * arr[i];

    return ans;

    delete[] cl,cr;
}

// Driver code 
int main()
{
    int arr[] = { 1, 3, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findMaxSum(arr, n);
}