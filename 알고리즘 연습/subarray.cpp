#include <iostream> 
# include <vector> 
using namespace std;

// Recursive function to print all possible subarrays   
// for given array  
void printSubArrays(vector<int> arr, int start, int end)
{
    // Stop if we have reached the end of the array      
    if (end == arr.size())
        return;

    // Increment the end point and start from 0  
    else if (start > end)
        printSubArrays(arr, 0, end + 1);

    // Print the subarray and increment the starting point  
    else
    {
        cout << "[";
        for (int i = start; i < end; i++) {
            cout << arr[i] << ", ";
        }

        cout << arr[end] << "]" << endl;
        printSubArrays(arr, start + 1, end);
    }

    return;
}

int main()
{
    vector<int> arr = { 1, 2, 3 };
    printSubArrays(arr, 0, 0);
    return 0;
}

//Difference between SubArray, SubSequence and SubSet
//3개의 차이점을 이해하자. 이 코드는 subarry 즉 순서를 신경쓰고, 서로 붙어있는 집합들을 가리는 것이므로 {1,3} 같은 것은 안된다.
//subsequence 는 떨어져있는 것도 되지만 역시 순서를 신경쓴다.