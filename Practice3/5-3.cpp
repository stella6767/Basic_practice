#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Dice
{
private:
	int face;
public:
	void roll();

	int getface();
};

void Dice::roll() {
	face = (int)(rand() % 6 + 1);
}

int Dice::getface() {
	return face;
}

int man()
{
	int i;
	Dice D1;
	srand(time(NULL));
	for (i = 0; i < 10; i++) {
		D1.roll();
		cout << "�ֻ����� ���ڴ�" << D1.getface() << "�Դϴ�." << endl;
	}

	return 0;
}