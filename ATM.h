// ATM.h: arquivo de inclusão para arquivos de inclusão padrão do sistema,
// ou arquivos de inclusão específicos a um projeto.

#pragma once

#include "Screen.h"
#include "Keypad.h"
#include "CashDispenser.h"
#include "DepositSlot.h"
#include "BankDatabase.h"

class Transaction;

class ATM
{
public:
	ATM(); // construtor inicializa membros de dados
	void run();

private:
	bool userAuthenticated{};    // se o usuário foi autenticado
	int currentAccountNumber{};  // número atual da conta de usuário
	Screen screen;               // tela do ATM
	Keypad keypad;               // teclado do ATM
	CashDispenser cashDispenser; // dispensador de cédulas do ATM
	DepositSlot depositSlot;     // abertura para depósito do ATM
	BankDatabase bankDatabase;   // banco de dados com as informações sobre as conta

	void authenticateUser();     // tentar autenticar o usuario
	void performTransactions();  // realiza transações
	int displayMainMenu() const; // exibe o menu principal

	Transaction* CreateTransaction(int);

};