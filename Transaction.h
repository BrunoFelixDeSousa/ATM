#pragma once

class Screen; // declara��o antecipada da classe Screen
class BankDatabase; //declara antecipada da classe BankDatabase

class Transaction
{
public:
	// o construtor inicializa recursos comuns de todas as Transactions
	Transaction(int, Screen &, BankDatabase &);

	virtual ~Transaction(){} // destrutor virtual do corpo vazio

	int getAccountNumber() const; // retornao n�mero da conta
	Screen& getScreen() const; // retorna a referencia � tela
	BankDatabase& getBankDatabase() const; // retorna referencia ao banco de dados

	virtual void execute() = 0;

private:
	int accountNumber;
	Screen& screen;
	BankDatabase& bankDatabase;

};