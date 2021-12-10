#include "BalanceInquiry.h"
#include "Screen.h"
#include "BankDatabase.h"

BalanceInquiry::BalanceInquiry(int userAccountNumber, Screen& atmScreen, BankDatabase& atmBankDatabase) :
	Transaction(userAccountNumber, atmScreen, atmBankDatabase)
{
	//corpo vazio
}

void BalanceInquiry::execute()
{
	// obt�m as refer�ncias ao banco de dados e tela do banco
	BankDatabase& bankDatabase = getBankDatabase();
	Screen & screen = getScreen();

	// obt�m o saldo dispon�vel da Account do usu�rio atual
	double availableBalance =
	bankDatabase.getAvailableBalance( getAccountNumber() );
	// obt�m o saldo total da Account do usu�rio atual
	double totalBalance =
	bankDatabase.getTotalBalance( getAccountNumber() );
 
	// exibe as informa��es sobre o saldo na tela
	screen.displayMessageLine( "\nInforma��o de balanco");
	screen.displayMessage( " - Available balance : ");
	screen.displayDollarAmount( availableBalance );
	screen.displayMessage( "\n - Balanco total : ");
	screen.displayDollarAmount( totalBalance );
	screen.displayMessageLine( "");
}