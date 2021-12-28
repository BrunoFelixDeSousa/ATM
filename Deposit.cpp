#include "Deposit.h"
#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "DepositSlot.h"

const static int CANCELED = 0;

Deposit::Deposit(int userAccountNumber, Screen& atmScreen, BankDatabase& atmBankdatabase, Keypad& atmKeypad, DepositSlot& atmDepositSlot) :
	Transaction(userAccountNumber, atmScreen, atmBankdatabase),
	keypad(atmKeypad),
	depositSlot(atmDepositSlot)
{
	
}

void Deposit::execute()
{
	BankDatabase& bankDatabase = getBankDatabase();
	Screen& screen = getScreen();

	amount = promptForDepositAmount();

	if (amount != CANCELED)
	{
		screen.displayMessage("\nPor favor, insira um envelope de dep�sito contendo");
		screen.displayDollarAmount(amount);
		screen.displayMessageLine("no slot de dep�sito.");

		bool envelopeReceived = depositSlot.isEnvelopeReceived();

		if (envelopeReceived)
		{
			screen.displayMessageLine("\nSeu envelope foi recebido."
				"NOTA: O dinheiro simplesmente n�o estar� dispon�vel at� que n�s"
				"verificar o valor de qualquer dinheiro incluso, e qualquer anexo"
				"verifica a libera��o.");

			bankDatabase.credit(getAccountNumber(), amount);
		}
		else
		{
			screen.displayMessageLine("Voc� n�o inseriu um envelope, ent�o o caixa eletr�nico cancelou sua transa��o");
		}
	}
	else
	{
		screen.displayMessageLine("\nCancelando transacao...");
	}
}

double Deposit::promptForDepositAmount() const
{
	Screen& screen = getScreen();

	screen.displayMessage("Insira um valor de dep�sito em CENTS (ou 0 para cancelar): ");

	int input = keypad.getInput();

	if (input == CANCELED)
		return CANCELED;
	else
	{
		return static_cast<double>(input) / 100;
	}
}