#include <iostream>
using std::cin;

#include "Keypad.h"

int Keypad::getInput() const
{
	int input; // variavel para armazenar a entrada
	cin >> input;
	return input;
}