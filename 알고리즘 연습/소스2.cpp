#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

static int ta = -1000; //�ִ� Ta

static vector<int> c;//�ִ� Ta�� �迭
static vector<int> cnt;

static int aa=0;


void printArray(vector<int> arr, int n)
{
	int sum = 0, num = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		cout << arr[i] << " ";
	}

	cout <<"�� �κ����� ������ "<<sum<<"�� "<<5+n<<"���� ����  "<<sum/(5+n)<<endl;

	if (ta <= sum / (5 + n)) {
		ta = sum / (5 + n);

		if (arr.size() >= c.size()) { //ta�� �ߺ��̸� ���Ұ����� ���� �� �켱
			c.clear();
			for (int i = 0; i < n; i++) {
				//cout << arr[i] << " ";
			}
			//cout << endl;
			for (int i = 0; i < n; i++) {
				c.push_back(arr[i]);
			}
		}
	}
}

//����Լ��� �̿��ؼ� ������ ��� �κ������� �˾Ƴ���. ������� O
void printSubsequences(vector<int> arr, int index,
	vector<int> subarr)
{
	if (index == arr.size())
	{
		int l = subarr.size();

		if (l != 0) {
			printArray(subarr, l);
		}
	}
	else
	{
		printSubsequences(arr, index + 1, subarr);

		subarr.push_back(arr[index]);

		printSubsequences(arr, index + 1, subarr);
	}

	//cnt.push_back(aa);
	//aa++;
	return;
}

int main()
{
	//vector<int> arr{ 1, 5, -1, -2, 2, 10, 9 };
	//vector<int> arr{ 3, 0, -1, -2};
	vector<int> arr{ 1, 2, 3};

	int n, j;

	vector<int> b;

	//vector<int> arr;
	//cin >> n;
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> j;
	//	arr.push_back(j);
	//}

	printSubsequences(arr, 0, b);

	sort(c.begin(), c.end(), greater<int>()); //������������ ����


	/*if (ta != 0) {
		for (int i = 0; i < c.size(); i++)
		{
			cout << c[i] << " ";
		}
	}

	else
		cout << ta;*/


	for (int i = 0; i< cnt.size(); i ++)
	{
		cout << cnt[i] << " ";
	}


	return 0;
}