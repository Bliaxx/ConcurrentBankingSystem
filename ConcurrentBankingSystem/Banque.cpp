#include "Banque.h"

std::shared_ptr<Compte> Banque::AddAccount(int _id, double _balance)
{
    std::lock_guard<std::mutex> lock(banqueMtx);
    if (accountsMap.find(_id) != accountsMap.end()) {
        return nullptr;
    }
    auto account = std::make_shared<Compte>(_id, _balance, journal);
    accountsMap[_id] = account;
    return account;
}

std::shared_ptr<Compte> Banque::FindAccount(int _id)
{
    std::lock_guard<std::mutex> lock(banqueMtx);
    auto it = accountsMap.find(_id);
    if (it != accountsMap.end()) {
        return it->second;
    }
    return nullptr;
}
