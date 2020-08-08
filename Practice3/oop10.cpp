#include <iostream>
#include <string.h>
using namespace std;

class Student {
	friend ostream& operator<<(ostream& os, const Student& v);
private:
	char* name; char* job;
public:
	Student(char* namevalue = NULL, char* jobvalue = NULL) :name(namevalue), job(jobvalue) {}

	Student operator+(Student& v2) {
		Student v;
		v.name = this->name;
		v.job = strcat(this->job, v2.job);
		return v;
	}

	Student& operator=(const Student& v2) {
		this->name = v2.name;
		this->job = v2.job;
		return *this;
	}
};

ostream& operator<<(ostream& os, const Student& v) {
	os << "(" << v.name << "," << v.job << ")" << endl;
	return os;
}

int main(int argc, char** argv) {
	Student a("철수", "학생"), b("순이", "사장"), c, d = a;

	c = b;
	cout << c;

	c = a + b;
	cout << c;

	return 0;
}