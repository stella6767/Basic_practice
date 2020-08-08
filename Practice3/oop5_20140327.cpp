#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Car {
private:
	int speed;
	int gear;
	string color;

public:
	int getSpeed();
	void setSpeed(int s);
	int getGear();
	void setGear(int g);
	string getColor();
	void setColor(string c);

	void speedUP();
	void speedDown();
	void init(int s, int gear, string c);
	void show();
};

int Car::getSpeed() {
	return speed;
}

void Car::setSpeed(int s) {
	speed = s;
}

int Car::getGear() {
	return gear;
}

void Car::setGear(int g) {
	gear = g;
}

string Car::getColor() {
	return color;
}

void Car::setColor(string c) {
	color = c;
}

void Car::speedUP() {
	speed += 10;
}

void Car::speedDown() {
	speed -= 10;
}

void Car::init(int s, int g, string c) {
	speed = s;
	gear = g;
	color = c;
}

void Car::show() {
	cout << "==================" << endl;
	cout << "속도: " << speed << endl;
	cout << "기어: " << gear << endl;
	cout << "색상: " << color << endl;
	cout << "==================" << endl;
}

int main(int argc, char** argv) {
	Car car1, car2;

	car1.init(rand() % 200, 1, "red");
	car1.show();

	car1.init(rand() % 200, 1, "red");
	car1.show();

	if (car1.getSpeed() > car2.getSpeed())
		cout << "car1이 승리하였습니다" << endl;
	else
		cout << "car2가 승리하였습니다" << endl;

	return 0;
}