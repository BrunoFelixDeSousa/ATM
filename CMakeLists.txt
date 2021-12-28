# CMakeList.txt: projeto de CMake para ATM, incluir origem e definir
# lógica específica a um projeto aqui.
#
cmake_minimum_required (VERSION 3.8)

project(
	"ATM"
	VERSION 0.0.1 
	LANGUAGES CXX
)

# Adicione a origem ao executável deste projeto.
add_executable (ATM 
 "ATM.cpp" 
 "ATM.h" 
 "Screen.h"
 "Screen.cpp"
 "Keypad.h" 
 "Keypad.cpp" 
 "CashDispenser.h"
 "CashDispenser.cpp"
 "DepositSlot.h"
 "DepositSlot.cpp" 
 "Account.h" 
 "Account.cpp" 
 "BankDatabase.h" 
 "BankDatabase.cpp" 
 "Transaction.h" 
 "Transaction.cpp" 
 "BalanceInquiry.h" 
 "BalanceInquiry.cpp" 
 "Withdrawal.h" 
 "Withdrawal.cpp"
 "Deposit.h")

# TODO: Adicione testes e instale destinos, se necessário.
