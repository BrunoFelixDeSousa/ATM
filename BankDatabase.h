#pragma once 

#include <vector>
using std::vector;

#include "Account.h"

class BankDatabase
{
public:
	BankDatabase(); // constutor inicializa as contas

	bool authenticateUSer(int, int); // retorna true se a Account for autêntica
	double getAvailableBalance(int); // ontem um saldo disponivel
	double getTotalBalance(int); // obtem saldo total de account
	void credit(int, double);
	void debit(int, double);

private:
	vector<Account> accounts;

	Account* getAccount(int);
};