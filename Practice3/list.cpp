#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

class Student {
private:
	string name;
	int num;
public:
	Student(string n = "", int u = 0) { name = n; num = u; }
	void display() {
		cout << name << ": " << num << endl;
	}

	string getName() { return name; }
	int getNum() { return num; }
};

void PrintAll(list<Student>& li) {
	list<Student>::iterator it;
	for (it = li.begin(); it != li.end(); ++it)
		it->display();
	cout << endl;
}

void Add(list<Student>& li) {
	int num; string name;
	cout << "�߰��� �л� �̸�:";
	cin >> name;
	cout << "�߰��� �� ��:";
	cin >> num;

	li.push_back(Student(name, num));
}

void Search(list<Student>& li) {
	int num; string name;

	list<Student>::iterator it;
	cout << "ã�� �̸�:";
	cin >> name;

	//	find(li.begin(), li.end(), name);
	//	if (it != li.end()) {
	//		cout << "�л� �̸�:" << endl;
	//		cout<<"�� ��"<< endl;}
	//	else
	//		cout << "not find " << endl;

	for (it = li.begin(); it != li.end(); it++) {
		if (it->getName() == name) {
			cout << "�л� �̸�:" << name << endl;
			cout << "�� ��:" << it->getNum() << endl;
		}
	}

	if (it->getName() != name)
		cout << "�ش� �̸��� �л��� �����ϴ�" << endl; //�� ������ ���� ��������?
}

void Delete(list<Student>& li) {
	int num; string name;

	list<Student>::iterator it;
	cout << "������ �̸�:";
	cin >> name;

	//	it=find(li.begin(), li.end(), name);
	// 	li.erase(it);

	for (it = li.begin(); it != li.end(); it++) {
		if (it->getName() == name) {
			it = li.erase(it);   //���� �̻�, ù��° �� �Է½� �۵��� �ȵ�
			cout << name << "�� �����Ǿ����ϴ�!" << endl;
		}
	}
	if (it->getName() != name)
		cout << "�ش� �̸��� �л��� �����ϴ�" << endl;
}

int main(int argc, char** argv) {
	list<Student> s; int sel;

	s.push_back(Student("a", 1));
	s.push_back(Student("b", 2));
	s.push_back(Student("c", 3));

	while (1) {
		cout << "1.�л����� �߰�  2.�л����� �˻�  3.�л����� ����  4.�л����� ���  5.EXIT" << endl;
		cout << ">>";  cin >> sel;

		if (sel == 1)  Add(s);
		else if (sel == 2) Search(s);
		else if (sel == 3) Delete(s);
		else if (sel == 4) PrintAll(s);
		else if (sel == 5) return 0;
	}

	return 0;
}