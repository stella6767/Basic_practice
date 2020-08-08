#include <iostream>

using namespace std;

class Complex
{
	double real;
	double img;
public:
	double getComplex();
	void setComplex(double r1, double i1);

	void Add(double r1, double r2, double i1, double i2);
	void Sub(double r1, double r2, double i1, double i2);
	void print();
};

double Complex::getComplex() {
	return real, img;
}

void Complex::setComplex(double r, double i) {
	real = r;
	img = i;
}

void Complex::Add(Complex c1, Complex c2, Complex c3) {
	sum = real + real;
	sum2 = img + img;
}

void Complex::Sub(Complex& c1, Complex& c2, Complex& c3) {
	sub = r1 - r2;
	sub2 = i1 - i2;
}

void print()
{
	if (imag > 0)
		cout << real << "+" << imag << "i" << endl;
	else if (imag < 0)
		cout << real << imag << "i" << endl;
}

int main()
{
	double r1, i1, r2, i2;  Complex c1, c2, c3;
	cout << "1���� �Ǽ��ο� ����θ� �Է��ϼ���: "; cin >> r1 >> i1;
	cout << "2���� �Ǽ��ο� ����θ� �Է��ϼ���: "; cin >> r2 >> i2;
	cout << "==========================================" << endl;
	c1.setComplex(r1, i1);   cout << "���Ҽ���: "; c1.print();
	c2.setComplex(r2, i2);   cout << "���Ҽ���: "; c2.print();

	c3.Add(r1, r2, i1, i2);   cout << "����: ";   c3.print();
	c3.Sub(r1, r2, i1, i2);  cout << "�߼���: "; c3.print();
	cout << "==========================================" << endl;

	return 0;
}