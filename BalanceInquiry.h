#pragma once

#include "Transaction.h"

class BalanceInquiry : public Transaction
{
public:
	BalanceInquiry(int, Screen&, BankDatabase&);
	virtual void execute(); // realiza a transa��o
};