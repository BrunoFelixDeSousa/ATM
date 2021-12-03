
#include "ATM.h"
#include "Transaction.h"
#include "BalanceInquiry.h"
#include "Withdrawal.h"
#include "DepositSlot.h"

// constantes de enumeração representam as principais opções de menu
enum MenuOption{ BALANCE_INQUIRY = 1, WITHDRAWAL, DEPOSIT, EXIT };

// o construtor-padrão ATM inicializa os membros de dados
ATM::ATM()
	: userAuthenticated(false), // o usuario não foi autencticado para iniciar
	currentAccountNumber(0)     // nenhum numero atual de conta para iniciar
{
	// corpo vazio
} // fim do construtor padrao ATM

void ATM::run()
{
	while (true)
	{
		while (!userAuthenticated)
		{
			screen.displayMessageLine("\nBem-Vindo!!!");
			authenticateUser(); // autentica o usuario
		}

		performTransactions(); // o usuario agora está autenticado
		userAuthenticated = false; // reinicializa antes da próxima sessão do ATM
		currentAccountNumber = 0; // reinicializa antes da próxima sessão do ATM
		screen.displayMessageLine("\nObrigado, Até mais...");
	}
} // fim do run



int main()
{
	
	return 0;
}
