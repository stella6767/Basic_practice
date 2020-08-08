#include <iostream>

using namespace std;

int main()
{
	int x[3][5] = { {12,56,32,16,98},
				 {99,56,34,41,3},
				 {65,3,87,78,21} };
	int sum = 0, h, i;
	for (h = 0; h < 3; h++)
	{
		for (i = 0; i < 5; i++)
			sum += x[h][i];
		cout << h + 1 << "행의 합계: " << sum << endl;
		sum = 0;
	}
	for (i = 0; i < 5; i++)
	{
		for (h = 0; h < 3; h++)
			sum += x[h][i];
		cout << i + 1 << "열의 합계: " << sum << endl;
		sum = 0;
	}
	return 0;
}