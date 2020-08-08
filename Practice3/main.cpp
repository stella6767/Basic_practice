#include <iostream>
#include <string>
#include <stdlib.h>
#include "Lamp.h"

using namespace std;

int main(int argc, char** argv) {
	Lamp lamp;

	lamp.turnOn();
	lamp.print();
	lamp.turnOff();
	lamp.print();

	return 0;
}