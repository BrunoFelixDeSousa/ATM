#include "Withdrawal.h"
#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "CashDispenser.h"

const static int CANCELED = 6;

Withdrawal::Withdrawal(int userAccountNumber, Screen& atmScreen, BankDatabase& atmBankDatabase, Keypad& atmkeypad, CashDispenser& atmCashDispenser) :
	Transaction(userAccountNumber, atmScreen, atmBankDatabase),
	keypad(atmkeypad),
	cashDispenser(atmCashDispenser)
{

}