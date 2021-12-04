#include "Account.h"

// o construtor Account inicializa os atributos
Account::Account(int theAccountNumber, int thePin, double theAvailableBalance, double theTotalBalance) :
	accountNumber(theAccountNumber),
	pin(thePin),
	availableBalance(theAvailableBalance),
	totalBalance(theTotalBalance)
{

}

// determina se um PIN especificado pelo usuário corresponde ao PIN em Account
bool Account::validatePIN(int userPIN) const
{
	if (userPIN == pin)
		return true;
	else
		return false;
}

// retorna saldo disponivel
double Account::getAvailableBalance() const
{
	return availableBalance;
}

// retorna o saldo total
double Account::getTotalBalance() const
{
	return totalBalance;
}

// credita uma quantia à conta
void Account::credit(double amount)
{
	totalBalance += amount;
}

// debita uma quantia da conta
void Account::debit(double amount)
{
	availableBalance -= amount;
	totalBalance -= amount;
}

// retorna o número da conta
int Account::getAccountNumber() const
{
	return accountNumber;
}