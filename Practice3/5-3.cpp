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
		cout << "주사위의 숫자는" << D1.getface() << "입니다." << endl;
	}

	return 0;
}