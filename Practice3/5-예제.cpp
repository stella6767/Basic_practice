#include <iostream>

using namespace std;

class Complex {
	double real, imag;

public:
	Complex(double r, double i) : real(r), imag(i) {}
	Complex operator+ (const Complex& c); //멤버함수로 구현

	friend Complex operator- (const Complex& c1, const Complex& c2);
	friend ostream& operator<< (ostream& os, const Complex& c);
};

Complex Complex::operator+ (const Complex& c)
{
	return Complex(this->real + c.real, this->imag + c.imag);
}

Complex operator- (const Complex& c1, const Complex& c2)
{
	return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

ostream& operator<<(ostream& os, const Complex& c)
{
	os << c.real << " + " << c.imag << "i" << endl;

	return os;
}
int ain()
{
	Complex c1(1, 7), c2(3, 8), c3(0, 0);

	c3 = c1 + c2;

	cout << c3;

	c3 = c1 - c2;

	cout << c3;
}