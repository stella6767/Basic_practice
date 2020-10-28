#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

//삽입정렬
void insertion_sort(int* arr, int n) {
	for (int i = 1, j; i < n; i++) {
		int t = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > t; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = t;
	}
}

//선택정렬
void selection_sort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int idx = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[idx])idx = j;
		}
		swap(&arr[i], &arr[idx]);
	}
}

//버블정렬
void bubble_sort(int* arr, int n) {
	int sorted = 1;
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				sorted = 0;
			}
		}
		if (sorted)break;
	}
}

//merge 정렬
int merge_arr[1000001];

//병합부분
void merge(int* arr, int l, int r) {
	int m = (l + r) / 2;
	int L = l;
	int R = m;
	int index = l;

	while (L < m && R < r) {
		if (arr[L] > arr[R])merge_arr[index++] = arr[R++];
		else merge_arr[index++] = arr[L++];
	}

	while (L < m)merge_arr[index++] = arr[L++];
	while (R < r)merge_arr[index++] = arr[R++];

	for (int i = l; i < r; i++)
		arr[i] = merge_arr[i];
}

//분할 부분
void mergesort(int* arr, int l, int r) {
	if (l >= r || abs(r - l) <= 1)return;
	int m = (l + r) / 2;
	mergesort(arr, l, m);
	mergesort(arr, m, r);
	merge(arr, l, r);
}

//퀵 소트
void partition(int* arr, int l, int r, int* pivot) {
	int i, j = l, p = arr[l];
	for (i = l + 1; i < r; i++) {
		if (arr[i] < p) {
			j++;
			swap(&arr[i], &arr[j]);
		}
	}
	*pivot = j;
	swap(&arr[l], &arr[*pivot]);
}

void quicksort(int* arr, int l, int r) {
	if (l >= r)return;
	int pivot;
	partition(arr, l, r, &pivot);
	quicksort(arr, l, pivot);
	quicksort(arr, pivot + 1, r);
}

//three-median quicksort
int get_pivot(int* arr, int l, int m, int r) {
	if (arr[l] > arr[m]) {
		if (arr[m] > arr[r]) {
			swap(&arr[r], &arr[l]);
			return arr[l];
		}
		else {
			swap(&arr[m], &arr[l]);
			return arr[l];
		}
	}
	else {
		if (arr[l] > arr[r]) {
			swap(&arr[r], &arr[l]);
			return arr[l];
		}
		else {
			return arr[l];
		}
	}
}

void partition_median(int* arr, int l, int r, int* pivot) {
	int m = (l + r) / 2, j = l;
	int p = get_pivot(arr, l, m, r - 1);
	for (int i = l + 1; i < r; i++) {
		if (arr[i] < p) {
			j++;
			swap(&arr[i], &arr[j]);
		}
	}
	*pivot = j;
	swap(&arr[l], &arr[*pivot]);
}

void quicksort_median(int* arr, int l, int r) {
	if (l >= r)return;
	int pivot;
	partition_median(arr, l, r, &pivot);
	quicksort_median(arr, l, pivot);
	quicksort_median(arr, pivot + 1, r);
}

//shell 정렬
void Insertion(int* arr, int l, int r, int g) {
	int key;
	for (int j, i = l + g - 1; i < r; i += g) {
		key = arr[i];
		for (j = i - g; j >= l && key < arr[j]; j -= g) {
			arr[j + g] = arr[j];
		}
		arr[j + g] = key;
	}
}

void shellsort(int* arr, int l, int r) {
	int n = r - l;
	for (int g = n / 2; g > 0; g /= 2) {
		if ((g % 2) == 0)g++;
		for (int i = 0; i < g; i++) {
			Insertion(arr, i, r, g);
		}
	}
}

int main() {
	int arr[1000001];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	//quicksort_median(arr, 0, n); //=> W(n^2), A(n^2)
	//insertion_sort(arr, n);      //=> O(n^2)
	//selection_sort(arr, n);      //=> O(n^2)
	//bubble_sort(arr, n);         //=> O(n^2)
	//mergesort(arr, 0, n);        //=> O(nlogn)
	//quicksort(arr, 0, n);        //=> O(nlogn), W(n^2)
	shellsort(arr, 0, n);        //=> O(nlogn), W(n^2)
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}