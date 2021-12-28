#pragma once

#include "Transaction.h"
class Keypad;
class DepositSlot;

class Deposit : public Transaction
{
public:
	Deposit(int, Screen&, BankDatabase&, Keypad&, DepositSlot&);
	virtual void execute();

private:
	double amount;
	Keypad& keypad;
	DepositSlot& depositSlot;
	double promptForDepositAmount() const;
};