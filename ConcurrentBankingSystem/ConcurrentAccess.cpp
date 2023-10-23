#include "ConcurrentAccess.h"
#include <iostream>

std::mutex ConcurrentAccess::mtx;

void ConcurrentAccess::operator()()
{
    account.PutMoney(100.0);
    account.Withdraw(50.0);
    std::lock_guard<std::mutex> _lock(mtx);
    std::cout << "Solde après accès concurrent: " << account.GetBalance() << std::endl;
}
