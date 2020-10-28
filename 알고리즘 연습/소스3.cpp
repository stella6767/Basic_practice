#include <iostream> 
#include <stack> 
#include<vector>
using namespace std;

// Function to return the required sum 
int findMaxSum(int arr[], int n)
{

    //int cl[n]; //���־� ��Ʃ��������� �迭�� ������ �Ҵ�ްų� �������� �Ҵ�޴°� ������ �Ⱦ��� �Ұ���
    //return n; // �迭 ũ��� ����� �������� ��. �׷��� vector�� ����

    //int n = sizeof(arr) / (sizeof(arr[0])*3);
    //vector<int> cl(n);
    //cl = { 0 };
    //vector<int> cr(n);
    //cr = { 0 };


    int* cl = new int[n]{0};  //�̷��� �ؾ߸� �ʱ�ȭ�� ����!!!!!
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