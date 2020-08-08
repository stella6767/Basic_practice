#include <iostream>

using namespace std;

class Complex
{
	float real;
	float imag;
public:
	float getreal()
	{
		return real;
	}
	float getimag()
	{
		return imag;
	}

	void set(float r, float i)
	{
		real = r;
		imag = i;
	}
	void print()
	{
		if (imag > 0)
			cout << real << "+" << imag << "i" << endl;
		else if (imag < 0)
			cout << real << imag << "i" << endl;
	}
	friend Complex operator+(Complex& o1, Complex& o2)
	{
		Complex res = o1;
		res.real += o2.real;
		res.imag += o2.imag;
		return res;
	}
	friend Complex operator-(Complex& o1, Complex& o2)
	{
		Complex res = o1;
		res.real -= o2.real;
		res.imag -= o2.imag;
		return res;
	}
};
int main()
{
	Complex c1, c2, c3, c4;
	c1.set(6, -9);
	c2.set(2, 5);
	c1.print();
	c2.print();
	c3 = c1 + c2;
	c4 = c1 - c2;
	c3.print();
	c4.print();
	return 0;
}