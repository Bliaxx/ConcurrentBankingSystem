#pragma once
#include "Transaction.h"
#include <vector>

class Journal
{
private:
	std::vector<Transaction> transactions;

public:
    inline void AddTransaction(const Transaction& _t) { transactions.push_back(_t); }

    void ShowLog() const;
};

