#pragma once

#include <string>
using std::string;

class Screen
{
public:
	void displayMessage(string) const;      // gera saida de uma mensagem
	void displayMessageLine(string) const;  // gera saida da mensagem com nova linha
	void displayDollarAmount(double) const; // gera saida de um valor em dólar
};