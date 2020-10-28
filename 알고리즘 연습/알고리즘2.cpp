#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int binary_search(int n, int List[], int num);

int main() {


	int list[400];



	cout << binary_search(380,list,50) << endl;


} 

int binary_search(int n, int List[], int num) { //¼øÂ÷ Å½»ö
 int low = 0, middle, high = n - 1;
	 while (low <= high) 
	 {
		middle = (low + high) / 2;
		if (num == List[middle]) return middle;
		else if (num < List[middle]) high = middle - 1;
		else low = middle + 1;
	
	}
	 return -1;


}
