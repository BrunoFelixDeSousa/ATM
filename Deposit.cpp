#include "Deposit.h"
#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "DepositSlot.h"

const static int CANCELED = 0;

Deposit::Deposit(int userAccountNumber, Screen& atmScreen, BankDatabase& atmBankdatabase, Keypad& atmKeypad, DepositSlot& atmDepositSlot) :
	Transaction(userAccountNumber], atmScreen, atmBankdatabase),
	keypad(atmKeypad),
	depositSlot(atmDepositSlot)
{
	
}

