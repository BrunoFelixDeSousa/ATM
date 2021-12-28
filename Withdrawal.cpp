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

int Withdrawal::displayMenuOfAmoount() const
{
	int userChoice = 0;

	Screen& screen = getScreen();

	int amount[]{ 0, 20, 40, 60, 100, 200 };

	while ( userChoice == 0 )
	{
		screen.displayMessageLine("\nopcoes de retirada:");
		screen.displayMessageLine("1 - $20");
		screen.displayMessageLine("2 - $40");
		screen.displayMessageLine("3 - $60");
		screen.displayMessageLine("4 - $100");
		screen.displayMessageLine("5 - $200");
		screen.displayMessageLine("6 - cancelar transacao");
		screen.displayMessageLine("\nescolha opcao de retirada (1-6): ");
	
		int input = keypad.getInput();
		switch (input)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			userChoice = amount[input];
			break;
		case CANCELED:
			userChoice = CANCELED;
			break;
		default:
			screen.displayMessageLine("\nselecao invalida, tente novamente.");
		}
	}

	return userChoice;
}
