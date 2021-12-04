#include "CashDispenser.h"

CashDispenser::CashDispenser()
{
	count = INITIAL_COUNT;
}

// simula a liberação da quantia em dinheiro especificada; supõe que há dinheiro suficiente
// disponível (chamada anterior para isSufficientCashAvailable retornou true)
void CashDispenser::dispenseCash(int amount)
{
	int billsRequired = amount / 20;
	count -= billsRequired;
}

// indica se o dispensador de cédulas pode entregar a quantia desejada
bool CashDispenser::isSufficientCashAvailable(int amount) const
{
	int billsRequired = amount / 20;

	if (count >= billsRequired)
		return true;
	else
		return false;
}