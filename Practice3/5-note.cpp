#include <iostream>
#include <string>

using namespace std;

class BankAccount {
	int accountNumber;
	string owner;
	int balance;
	int Account1 = 1000000;
	int Account2 = 0;

	void deposit(int amount) {//입금
		balance += amount;
	}
	void withdraw(int amount) {//출금
		balance -= amount;
	}
	public string tostring() {
		return "현재 잔액은 " + balance + "입니다";
	}
	public string transfer(int amount, BankAccount otherAccount) {
		if (Account1 >= amount) {
			Account1 -= amount;
			otherAccount.Account2 += amount;
			return "이체한 금액은" + amount + "입니다";
		}
		else {
			return "잔액이 부족합니다.";
		}
	}
}

int main() {
	public static void main(string[] args) {
		Scanner sc = new Scanner(System.in);

		BankAccount my = new BankAccount();
		BankAccount you = new BankAccount();

		System.out.println("이체할 금액을 입력하시오");
		int amount = sc.nextInt();
		System.out.println(my.transfer(amount, you));

		System.out.println("내 계좌 잔액 : " + my.Account1);
		System.out.println("받으시는 분 잔액 : " + you.Account2);
	}
}