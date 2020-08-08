#include <iostream>

using namespace std;

int main() {
	string s("Hello world!");
	s.erase(3, 2);
	cout << s << endl;

	int i = s.find("w", 0);
	cout << i << endl;

	return 0;
}