#include <iostream>

using namespace std;

class FruitSeller
{
private:
	int applePrice;
	int numOfApples;
	int myMoney;
public:
	FruitSeller(int a, int n, int m);
	int  SaleApples(int money);
	void ShowSalesResult();
};

FruitSeller::FruitSeller(int a, int n, int m) :applePrice(a), numOfApples(n), myMoney(m) {
}//생성자 (맴버 초기화 목록)

int FruitSeller::SaleApples(int money)
{
	int num = money / applePrice;
	numOfApples -= num;
	myMoney += money;
	return num;
}
void FruitSeller::ShowSalesResult()
{
	cout << "남은 사과: " << numOfApples << endl;
	cout << "판매 수익: " << myMoney << endl << endl;
}

class FruitBuyer
{
private:
	int myMoney;
	int numOfApples;
public:
	FruitBuyer(int m, int n);
	void BuyApples(FruitSeller& seller, int money);
	void ShowBuyResult();
};

FruitBuyer::FruitBuyer(int m, int n) :myMoney(m), numOfApples(n)
{
}

void FruitBuyer::BuyApples(FruitSeller& seller, int money)
{
	numOfApples += seller.SaleApples(money);  // 메시지 전달(Message Passing)
	myMoney -= money;
}
void FruitBuyer::ShowBuyResult()
{
	cout << "현재 잔액: " << myMoney << endl;
	cout << "사과 개수: " << numOfApples << endl << endl;
}

int mssssn()
{
	FruitSeller seller(1000, 20, 0);

	FruitBuyer buyer(5000, 0);

	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황: " << endl;
	seller.ShowSalesResult();

	cout << "과일 구매자의 현황: " << endl;
	buyer.ShowBuyResult();

	return 0;
}