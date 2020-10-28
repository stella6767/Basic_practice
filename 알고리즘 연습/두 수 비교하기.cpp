#include <iostream>

using namespace std;

int main()
{

	/*int h;

	cin >> h;
	
	for(int i=0;i<9;i++)
		printf("%d * %d = %d \n", h, i+1, h*(i+1));*/


	cin.tie(NULL);
	int num, a, b;
	cin >> num;
	if (num > 10000000) { return 0; }
	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		cout << a + b << "\n";




		//int n;
//int a, b;

//cin >> n;


//for (int i = 1; i <= n; i++) {
//	cin >> a >> b;
//	cout << "Case #" << i << ": " << a + b;

//}


		//int a;


		//cin >> a;
		////if (a < 0 && a>99)

		//if (a < 10)
		//	a + 10;

		//int b = a / 10; //십의 자리
		//int c = a % 10; // 일의 자리
		//int e = b + c;


		//int num = (c * 10) + (e % 10);
		//int count = 1;

		//while (num != a) {
		//	b = num / 10;
		//	c = num % 10;
		//	e = b + c;
		//	num = (c * 10) + (e % 10);
		//	count++;
		//}

		//cout << count;



		//int a, k, c = 0;
		//scanf("%d", &a);
		//k = a;
		//do {
		//	a = a % 10 * 10 + (a / 10 + a % 10) % 10;
		//	c++;
		//} while (a != k);
		//printf("%d", c);

		//int X, R;
		//int S() { R = R % 10 * 10 + (R / 10 + R % 10) % 10; return X == R ? 1 : 1 + S(); }
		//int main() { scanf("%d", &X); R = X; printf("%d\n", S()); }




		//int c, k = 1;
		//cin >> c;
		//for (int i = 1; i > 0; i += k) {
		//	for (int j = 0; j < i; j++) printf("*");
		//	printf("\n");
		//	if (i > c - 1) k *= -1;
		//}

	return 0;
}


#include<iostream>

	using namespace std;

	int main()
	{
		int num;
		cin >> num;

		char* sumlist = new char[num];
		int sum = 0;

		for (int i = 0; i < num; i++)
		{
			cin >> sumlist[i];
			sum += (int)(sumlist[i] - '0');
		}

		cout << sum << endl;
	}

#include <iostream>
#include <algorithm>
#include <string>

	using namespace std;


	int main() {

		int n, m;
		int sum, max = 0;
		int num[100] = { 0, };

		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					sum = num[i] + num[j] + num[k];
					if (sum > max && sum <= m)
						max = sum; //가장 가까운 값 갱신될 때마다 max에 저장
				}
			}

		}
		cout << max;


	}
#include <iostream>
#include <algorithm>
#include <string>

	using namespace std;


	int main() {

		int b;
		int a[10];

		for (int i = 0; i < 10; i++)
		{
			cin >> b;
			a[i] = b;
		}

		int c[10] = { 0, };

		for (int j = 0; j < 10; j++)
		{
			c[a[j]]++;
		}


		int min = 0;
		int cnt = 0;

		for (int k = 0; k < 10; k++)
		{
			if (cnt < c[k])
			{
				cnt = c[k];
				min = k;
			}
		}

		cout << "최빈수: " << min << "cnt: " << cnt;


	}

#include <iostream>

#include <vector>

#include <algorithm>

	using namespace std;



	int N, M;

	int result;

	vector<int> v;



	void sumOfCards(int idx, int cnt, int sum)

	{

		//조건 만족할 경우

		if (cnt == 3 && sum <= M)

		{

			result = max(result, sum);

			return;

		}

		//기저 사례

		if (idx >= N || cnt > 3 || sum > M)

			return;



		//해당 카드 선택

		sumOfCards(idx + 1, cnt + 1, sum + v[idx]);

		//해당 카드 선택 X

		sumOfCards(idx + 1, cnt, sum);

	}



	int main(void)

	{

		ios_base::sync_with_stdio(0);

		cin.tie(0);

		cin >> N >> M;



		v.resize(N);

		for (int i = 0; i < N; i++)

			cin >> v[i];



		sumOfCards(0, 0, 0);

		cout << result << "\n";

		return 0;

	}



#include <iostream>
#include <algorithm>
#include <string>

	using namespace std;

	int fibo(int n);

	int main() {

		for (int i = 1; i <= 10; i++)
		{
			cout << fibo(i) << " ";
		}

	}

	int fibo(int n) {
		//base case
		if (n < 2)
			return n;
		else
			return fibo(n - 1) + fibo(n - 2);

	}