#include "CashDispenser.h"

CashDispenser::CashDispenser()
{
	count = INITIAL_COUNT;
}

// simula a libera��o da quantia em dinheiro especificada; sup�e que h� dinheiro suficiente
// dispon�vel (chamada anterior para isSufficientCashAvailable retornou true)
void CashDispenser::dispenseCash(int amount)
{
	int billsRequired = amount / 20;
	count -= billsRequired;
}

// indica se o dispensador de c�dulas pode entregar a quantia desejada
bool CashDispenser::isSufficientCashAvailable(int amount) const
{
	int billsRequired = amount / 20;

	if (count >= billsRequired)
		return true;
	else
		return false;
}