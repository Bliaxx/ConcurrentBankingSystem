#pragma once
#include<unordered_map>
#include <memory>
#include "Compte.h"

class Banque
{
private:
    std::unordered_map<int, std::shared_ptr<Compte>> accountsMap;
    std::mutex banqueMtx;
    Journal& journal;

public:
    Banque(Journal& _journal) : journal(_journal) {}

    std::shared_ptr<Compte> AddAccount(int _id, double _balance);
    std::shared_ptr<Compte> FindAccount(int _id);
};

