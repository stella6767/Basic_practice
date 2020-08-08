#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
	int balance = 0, balance2 = 0;
public:
	int getbalance();
	void setbalance(int amount);

	int getbalance2();
	void setbalance2(int amount);

	void deposit(int amount);
	void deposit2(int amount);
	void withdraw(int amount);
	void print();
	void transfer(int amount, BankAccount& b);
};

int BankAccount::getbalance() {
	return balance;
}

void BankAccount::setbalance(int amount) {
	balance = amount;
}

int BankAccount::getbalance2() {
	return balance2;
}

void BankAccount::setbalance2(int amount) {
	balance2 = amount;
}

void BankAccount::deposit(int amount) {
	balance += amount;
}

void BankAccount::deposit2(int amount) {
	balance2 += amount;
}

void BankAccount::withdraw(int amount) {
	balance -= amount;
}

void BankAccount::print() {
	if (balance)
		cout << "계좌a의 잔액은" << balance << "입니다." << endl;
	else
		cout << "계좌 b의 잔액은" << balance2 << "입니다." << endl;
}

void BankAccount::transfer(int amount, BankAccount& b) {
	if (balance < amount)
		cout << "전송하려는 양보 잔액이 더 적습니다." << endl;
	balance -= amount;
	balance2 += amount;
	b.deposit2(balance2);
}

int an()
{
	BankAccount a, b;
	a.setbalance(0);
	b.setbalance2(0);

	a.deposit(10000);
	b.deposit2(1000);

	a.print(), b.print();

	a.withdraw(2000);
	cout << "계좌 a에서 2000원 인출한 후 >>";
	a.print();
	a.transfer(5000, b);
	cout << "계좌 a에서 5000원을 계좌 b로 이체 후 >>";
	a.print(), b.print();

	return 0;
}