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
	cout << "추가할 학생 이름:";
	cin >> name;
	cout << "추가할 학 번:";
	cin >> num;

	li.push_back(Student(name, num));
}

void Search(list<Student>& li) {
	int num; string name;

	list<Student>::iterator it;
	cout << "찾을 이름:";
	cin >> name;

	//	find(li.begin(), li.end(), name);
	//	if (it != li.end()) {
	//		cout << "학생 이름:" << endl;
	//		cout<<"학 번"<< endl;}
	//	else
	//		cout << "not find " << endl;

	for (it = li.begin(); it != li.end(); it++) {
		if (it->getName() == name) {
			cout << "학생 이름:" << name << endl;
			cout << "학 번:" << it->getNum() << endl;
		}
	}

	if (it->getName() != name)
		cout << "해당 이름의 학생이 없습니다" << endl; //왜 끝번에 가면 나오는지?
}

void Delete(list<Student>& li) {
	int num; string name;

	list<Student>::iterator it;
	cout << "삭제할 이름:";
	cin >> name;

	//	it=find(li.begin(), li.end(), name);
	// 	li.erase(it);

	for (it = li.begin(); it != li.end(); it++) {
		if (it->getName() == name) {
			it = li.erase(it);   //무언가 이상, 첫번째 값 입력시 작동이 안됨
			cout << name << "이 삭제되었습니다!" << endl;
		}
	}
	if (it->getName() != name)
		cout << "해당 이름의 학생이 없습니다" << endl;
}

int main(int argc, char** argv) {
	list<Student> s; int sel;

	s.push_back(Student("a", 1));
	s.push_back(Student("b", 2));
	s.push_back(Student("c", 3));

	while (1) {
		cout << "1.학생정보 추가  2.학생정보 검색  3.학생정보 삭제  4.학생정보 출력  5.EXIT" << endl;
		cout << ">>";  cin >> sel;

		if (sel == 1)  Add(s);
		else if (sel == 2) Search(s);
		else if (sel == 3) Delete(s);
		else if (sel == 4) PrintAll(s);
		else if (sel == 5) return 0;
	}

	return 0;
}