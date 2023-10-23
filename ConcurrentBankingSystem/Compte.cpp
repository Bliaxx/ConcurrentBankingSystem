#include "Compte.h"

double Compte::GetBalance()
{
	std::lock_guard<std::mutex> _lock(mtx);
	return balance;
}

void Compte::PutMoney(double _amount)
{
	if (_amount <= 0)
		return;
	std::lock_guard<std::mutex> _lock(mtx);
	Transaction _newTransaction(id, _amount, "dépôt");
	journal.AddTransaction(_newTransaction);
	balance += _amount;
}

bool Compte::Withdraw(double _amount)
{
	std::lock_guard<std::mutex> _lock(mtx);
	if (balance >= _amount) {
		Transaction _newTransaction(id, _amount, "retrait");
		journal.AddTransaction(_newTransaction);
		balance -= _amount;
		return true;
	}
	return false;
}
