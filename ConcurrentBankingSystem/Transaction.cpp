#define _CRT_SECURE_NO_WARNINGS

#include "Transaction.h"
#include <iostream>

void Transaction::Show() const
{
	std::cout << "Compte ID: " << accountId << ", Montant: " << amount << ", Type: " << type << "Date: " << std::ctime(&timestamp) << std::endl;
}
