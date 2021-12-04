#pragma once

class CashDispenser
{
public:
	CashDispenser(); // o construtor inicializa contagem de conta para 500

	// simula a entrada da quantia especifica de celulas
	void dispenseCash(int);

	// indica se o dispensador de celulas pode entregar a quantia desejada
	bool isSufficientCashAvailable(int) const;

private:
	const static int INITIAL_COUNT = 500;
	int count{};
};