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
}//������ (�ɹ� �ʱ�ȭ ���)

int FruitSeller::SaleApples(int money)
{
	int num = money / applePrice;
	numOfApples -= num;
	myMoney += money;
	return num;
}
void FruitSeller::ShowSalesResult()
{
	cout << "���� ���: " << numOfApples << endl;
	cout << "�Ǹ� ����: " << myMoney << endl << endl;
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
	numOfApples += seller.SaleApples(money);  // �޽��� ����(Message Passing)
	myMoney -= money;
}
void FruitBuyer::ShowBuyResult()
{
	cout << "���� �ܾ�: " << myMoney << endl;
	cout << "��� ����: " << numOfApples << endl << endl;
}

int mssssn()
{
	FruitSeller seller(1000, 20, 0);

	FruitBuyer buyer(5000, 0);

	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ: " << endl;
	seller.ShowSalesResult();

	cout << "���� �������� ��Ȳ: " << endl;
	buyer.ShowBuyResult();

	return 0;
}