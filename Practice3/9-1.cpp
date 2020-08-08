#include<iostream>
#include<string>

using namespace std;

class AbstractGate
{
protected:
	int x, y;
public:
	void inputSet(bool x, bool y) { this->x = x; this->y = y; }
	virtual void op() = 0;
};

class ANDGate :public AbstractGate
{
public:
	ANDGate(bool x = false, bool y = false)
	{
		inputSet(x, y);
	}
	void op()
	{
		int z;

		if (x == true && y == true)
		{
			z = 1;
		}
		else
			z = 0;

		cout << "AND input : " << x << " " << y << "->" << z << endl;
	}
};

class ORGate :public AbstractGate
{
public:
	ORGate(bool x = false, bool y = false)
	{
		inputSet(x, y);
	}
	void op()
	{
		int z;
		if (x == true || y == true)
		{
			z = 1;
		}
		else
			z = 0;

		cout << "OR input : " << x << " " << y << "->" << z << endl;
	}
};

class XORGate :public AbstractGate
{
public:
	XORGate(bool x = true, bool y = true)
	{
		inputSet(x, y);
	}
	void op()
	{
		int z;
		if (x != y)
		{
			z = 1;
		}
		else
			z = 0;

		cout << "XOR input : " << x << " " << y << "->" << z << endl;
	}
};

int main()
{
	ANDGate andd;
	ORGate orr;
	XORGate xorr;

	andd.inputSet(true, false);
	andd.op();
	andd.inputSet(true, true);
	andd.op();

	orr.inputSet(true, false);
	orr.op();
	orr.inputSet(true, true);
	orr.op();

	xorr.inputSet(true, false);
	xorr.op();
	xorr.inputSet(true, true);
	xorr.op();

	cout.setf(ios::boolalpha);
}