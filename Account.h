#pragma once

class Account
{
public:
	Account(int, int, double, double); // o construtor configura atributos
	bool validattePIN(int) const; // o PIN especificado pelo usuário é correto?
	double getAvailableBalance() const; // retorna o saldo disponível
	double getTotalBalance() const; // retorna o saldo total
	void credit(double); // adiciona um valor ao de Account
	void debit(double); // subtrai uma quantia do saldo de Account
	int getAccountNumber() const; // retorna o número da conta

private:
	int accountNumber{};       // número da conta
	int pin{};                 // PIN para autenticação
	double availableBalance{}; // fundos disponíveis para retirada
	double totalBalance{};     // fundos disponíveis + fundos esperando compensação
};