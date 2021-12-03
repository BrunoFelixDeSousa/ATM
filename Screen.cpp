#include <iostream>
using namespace std;

#include <iomanip>

#include "Screen.h"

// gera saida de uma mensagem sem uma nova linha
void Screen::displayMessage(string message) const
{
	cout << message;
}

// gera saida de uma mensagem com uma nova linha
void Screen::displayMessageLine(string message) const
{
	cout << message << '\n';
}

// gera sa�da de um valor em d�lar
void Screen::displayDollarAmount(double amount) const
{
	cout << fixed << setprecision(2) << "$" << amount;
}