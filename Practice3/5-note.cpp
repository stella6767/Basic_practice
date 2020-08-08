#include <iostream>
#include <string>

using namespace std;

class BankAccount {
	int accountNumber;
	string owner;
	int balance;
	int Account1 = 1000000;
	int Account2 = 0;

	void deposit(int amount) {//�Ա�
		balance += amount;
	}
	void withdraw(int amount) {//���
		balance -= amount;
	}
	public string tostring() {
		return "���� �ܾ��� " + balance + "�Դϴ�";
	}
	public string transfer(int amount, BankAccount otherAccount) {
		if (Account1 >= amount) {
			Account1 -= amount;
			otherAccount.Account2 += amount;
			return "��ü�� �ݾ���" + amount + "�Դϴ�";
		}
		else {
			return "�ܾ��� �����մϴ�.";
		}
	}
}

int main() {
	public static void main(string[] args) {
		Scanner sc = new Scanner(System.in);

		BankAccount my = new BankAccount();
		BankAccount you = new BankAccount();

		System.out.println("��ü�� �ݾ��� �Է��Ͻÿ�");
		int amount = sc.nextInt();
		System.out.println(my.transfer(amount, you));

		System.out.println("�� ���� �ܾ� : " + my.Account1);
		System.out.println("�����ô� �� �ܾ� : " + you.Account2);
	}
}