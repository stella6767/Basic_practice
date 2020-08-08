#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class CShape {
protected:
	int x, y;
public:
	void setOrigin(int x, int y) {
		this->x = x;
		this->y = y;
	}
	virtual void Draw() = 0;
};

class Rectangle :public CShape {
private:
	int width, height;
public:
	void setWidth(int w) {
		width = w;
	}
	void setHeight(int h) {
		height = h;
	}

	void Draw() {
		cout << "Rectangle Draw" << endl;
	}
};

class CCircle :public CShape {
private:
	int x, y, z, r;
public:
	CCircle(int x, int y, int z, int r) :x(x), y(y), z(z), r(r) {}
	void Draw() {
		cout << "Circle Draw" << endl;
	}
};

class CLine :public CShape {
private:
	int x, y, z, r;
public:
	CLine(int x, int y, int z, int r) :x(x), y(y), z(z), r(r) {}
	void Draw() {
		cout << "Line Draw" << endl;
	}
};
int main(int argc, char** argv) {
	CCircle a(1, 1, 5, 5);
	CCircle b(5, 5, 9, 9);
	CShape* p;

	a.Draw();
	b.Draw();

	p = new CLine(10, 10, 100, 100);
	p->Draw();
	p = new CLine(100, 100, 200, 200);
	p->Draw();

	delete p;

	return 0;
}