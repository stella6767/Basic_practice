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
		cout << "����a�� �ܾ���" << balance << "�Դϴ�." << endl;
	else
		cout << "���� b�� �ܾ���" << balance2 << "�Դϴ�." << endl;
}

void BankAccount::transfer(int amount, BankAccount& b) {
	if (balance < amount)
		cout << "�����Ϸ��� �纸 �ܾ��� �� �����ϴ�." << endl;
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
	cout << "���� a���� 2000�� ������ �� >>";
	a.print();
	a.transfer(5000, b);
	cout << "���� a���� 5000���� ���� b�� ��ü �� >>";
	a.print(), b.print();

	return 0;
}