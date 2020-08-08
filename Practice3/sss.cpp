#include <iostream>

using namespace std;

class Point {
	int x, y;

public:
	Point(int xx, int yy);
	int GetX();
	int GetY();
};

Point::Point(int xx, int yy) :x(xx), y(yy) {
}

int Point::GetX() {
	return x;
}

int Point::GetY() {
	return y;
}

class Circle {
	Point Center;
	int R;

public:
	Circle(int xx, int yy, int rr);
	void ShowCircle();
};

void Circle::ShowCircle() {
	cout << xx << endl;
}

int main() {
	Circle cir_1(10, 20, 5), cir_2(20, 30, 10);

	cir_1.ShowCircle();
	cir_2.ShowCircle();

	return 0;
}