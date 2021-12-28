
#include "ATM.h"
#include "Transaction.h"
#include "BalanceInquiry.h"
#include "Withdrawal.h"
#include "Deposit.h"

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
} // fim da função run


// tenta autenticar o usuário contra contra o banco de dados
void ATM::authenticateUser()
{
	screen.displayMessage("\nPorfavor entre com seu numero da conta: ");
	int accountNumber = keypad.getInput();             // insere o numero da conta
	screen.displayMessage("\nEntre com numero PIN: "); // solicita PIN
	int pin = keypad.getInput();                       // insere o pin

	// configura userAuthenticated como um valor bool retornado pelo banco de dados
	userAuthenticated = bankDatabase.authenticateUSer(accountNumber, pin);

	//veridifica se a autenticação foi bem sucedida
	if (userAuthenticated)
	{
		currentAccountNumber = accountNumber; // salva a conta do usuário
	}
	else
	{
		screen.displayMessageLine("Numero da conta ou PIN Inválido. Porfavor, tente novamente.");
	}
} // fim da função authenticateUser


// exibe o menu principal e realiza transações
void ATM::performTransactions()
{
	// ponteiro local para armazenar a transação atualmente processada
	Transaction* CurrentTransactionPtr;

	bool userExited{ false }; // o usuário optou por não sair

	// faz um loop enquanto o usuário não escolher a opção para sair do sistema
	while (!userExited)
	{
		// mostra o menu principal e obtém a seleção de usuário
		int mainMenuSelection = displayMainMenu();

		// decide como prosseguir com base na seleção do menu feita pelo usuário
		switch (mainMenuSelection)
		{
			// o usuário optou por realizar um entre três tipos de transação
			case BALANCE_INQUIRY:
			case WITHDRAWAL:
			case DEPOSIT:
				// inicializa como o novo obejto do tipo escolhido
				CurrentTransactionPtr = CreateTransaction(mainMenuSelection);

				CurrentTransactionPtr->execute(); // executa transação

				// libera o espaço para a Transaction dinamicamente alocada
				delete CurrentTransactionPtr;

				break;
			case EXIT:  // o usuário optou por terminar a sessão
				screen.displayMessageLine("\nSaindo do sistema...");
				userExited = true; // essa sessão de ATM deve terminar
				break;
			default:  // o usuário não inseriu um inteiro de 1 a 4
				screen.displayMessageLine("\nVocê não entrou com uma seleção válida. Tente novamente.");
				break;
		}
	}
} // fim da função performTransactions


int ATM::displayMainMenu() const
{
	screen.displayMessageLine("\nMenu Principal:");
	screen.displayMessageLine("1 - Ver meu saldo");
	screen.displayMessageLine("2 - Retirar o dinheiro");
	screen.displayMessageLine("3 - Fundos de depósito");
	screen.displayMessageLine("4 - Sair\n");
	screen.displayMessage("Insira uma escolha: “");
	
	return keypad.getInput(); // retorna a seleção do usuário
}


// retorna o objeto da classe derivada Transaction especificada
Transaction* ATM::CreateTransaction(int type) {
	Transaction* tempPtr; // ponteiro Transaction temporario

	// determina que tipo Transaction criar
	switch (type)
	{
		case BALANCE_INQUIRY: // cria uma nova transação BalanceInquiry
			tempPtr = new BalanceInquiry(
				currentAccountNumber, screen, bankDatabase
			);
			break;
		case WITHDRAWAL:
			tempPtr = new Withdrawal(
				currentAccountNumber, screen, bankDatabase, keypad, cashDispenser
			);
			break;
		case DEPOSIT:
			tempPtr = new Deposit(
				currentAccountNumber, screen, bankDatabase, keypad, depositSlot
			);
			break;
	}
	return tempPtr;
}