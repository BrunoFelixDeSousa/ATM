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

// realizar transação
void Withdrawal::execute()
{
	bool cashDispensed = false;
	bool transactionCanceled = false;

	BankDatabase& bankDatabase = getBankDatabase();
	Screen& screen = getScreen();

	do
	{
		int selection = displayMenuOfAmoount();
		
		if (selection != CANCELED)
		{
			amount = selection;

			double availableBalance = bankDatabase.getAvailableBalance(getAccountNumber());
			
			if (amount <= availableBalance)
			{
				if (cashDispenser.isSufficientCashAvailable(amount))
				{
					bankDatabase.debit(getAccountNumber(), amount);

					cashDispenser.dispenseCash(amount);
					cashDispensed = true;

					screen.displayMessageLine("\n por favor, pegue seu dinheiro no terminal");
				}
				else
				{
					screen.displayMessageLine("\nDinheiro insuficiente disponível no caixa eletronico."
						"\npor favor escolha uma quantidade menor.");
				}
			}
			else
			{
				screen.displayMessageLine("\nFundos insuficientes em sua conta."
					"\npor favor escolha uma quantidade menor.");
			}
		}
		else
		{
			screen.displayMessageLine("\ncancelando transacao...");
			transactionCanceled = true;
		}
	} while (!cashDispensed && !transactionCanceled);
}

