#include <iostream>

using namespace std;

void merge(int list[], int low, int mid, int high) {
	//int size = sizeof(list) / sizeof(list[0]);
	int n1 = low, n2 = mid + 1, s = low, sorted[1000] = { 0 }, i;
	 while (n1 <= mid && n2 <= high) {
		 if (list[n1] <= list[n2]) sorted[s++] = list[n1++];
		 else sorted[s++] = list[n2++];
		
	}
	 if (n1>mid) {
		 while (n2 <= high)
			 sorted[s++] = list[n2++];
	 }
	 else while (n1 <= mid) sorted[s++] = list[n1++];
	 for (i = low; i <= high; i++) list[i] = sorted[i];
	
}
void merge_sort_DC(int list[], int low, int high) {
	int middle;
	 if (low <high) {
		 middle = (low + high) / 2;
		 merge_sort_DC(list, low, middle);
		 merge_sort_DC(list, middle + 1, high);
		 merge(list, low, middle, high);
		
	}
	
}

int maximum_DC(int list[], int low, int high) { //분할정복으로 최댓값 구하기
	 int middle, lmax, hmax;
	 if (low == high) return list[low];
	 else if (low == high - 1) {
		 if (list[low] >= list[high]) return list[low];
		 else return list[high];
		
	}
	else {
		 middle = (low + high) / 2;
		 lmax = maximum_DC(list, low, middle);
		 hmax = maximum_DC(list, middle + 1, high);
		 if (lmax >= hmax) return lmax;
		 else return hmax;
		
	}
	
}



int main() {

	int* data;
	int n,max;

	int low, high;

	cin >> n;
	data = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
	}


	low = 0;
	high = n-1;

	merge_sort_DC(data, low, high);

	max = maximum_DC(data, low, high);

	for (int i = 0; i < n; i++)
	{
		cout << data[i] << "\n";
	}


}