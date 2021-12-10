#pragma once

class Screen; // declaração antecipada da classe Screen
class BankDatabase; //declara antecipada da classe BankDatabase

class Transaction
{
public:
	// o construtor inicializa recursos comuns de todas as Transactions
	Transaction(int, Screen &, BankDatabase &);

	virtual ~Transaction(){} // destrutor virtual do corpo vazio

	int getAccountNumber() const; // retornao número da conta
	Screen& getScreen() const; // retorna a referencia á tela
	BankDatabase& getBankDatabase() const; // retorna referencia ao banco de dados

	// função virtual pura para realizar a transação
	virtual void execute() = 0; // sobrescrita em classes derivadas

private:
	int accountNumber;
	Screen& screen;
	BankDatabase& bankDatabase;

};