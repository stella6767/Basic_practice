#include <iostream>
#include <string>
#include <stdlib.h>
#include "Lamp.h"

using namespace std;

void Lamp::turnOn() {
	isOn = true;
}

void Lamp::turnOff() {
	isOn = false;
}

void Lamp::print() {
	cout << "������" << (isOn == true ? "����" : "����") << endl;
}