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
	// obtém as referências ao banco de dados e tela do banco
	BankDatabase& bankDatabase = getBankDatabase();
	Screen & screen = getScreen();

	// obtém o saldo disponível da Account do usuário atual
	double availableBalance =
	bankDatabase.getAvailableBalance( getAccountNumber() );
	// obtém o saldo total da Account do usuário atual
	double totalBalance =
	bankDatabase.getTotalBalance( getAccountNumber() );
 
	// exibe as informações sobre o saldo na tela
	screen.displayMessageLine( "\nInformação de balanco");
	screen.displayMessage( " - Available balance : ");
	screen.displayDollarAmount( availableBalance );
	screen.displayMessage( "\n - Balanco total : ");
	screen.displayDollarAmount( totalBalance );
	screen.displayMessageLine( "");
}