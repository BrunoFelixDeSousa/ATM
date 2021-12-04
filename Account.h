#pragma once

class Account
{
public:
	Account(int, int, double, double); // o construtor configura atributos
	bool validattePIN(int) const; // o PIN especificado pelo usu�rio � correto?
	double getAvailableBalance() const; // retorna o saldo dispon�vel
	double getTotalBalance() const; // retorna o saldo total
	void credit(double); // adiciona um valor ao de Account
	void debit(double); // subtrai uma quantia do saldo de Account
	int getAccountNumber() const; // retorna o n�mero da conta

private:
	int accountNumber{};       // n�mero da conta
	int pin{};                 // PIN para autentica��o
	double availableBalance{}; // fundos dispon�veis para retirada
	double totalBalance{};     // fundos dispon�veis + fundos esperando compensa��o
};