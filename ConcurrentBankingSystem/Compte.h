#pragma once
#include <mutex>
#include "Journal.h"

class Compte
{
private:
    int id;
    double balance;
    std::mutex mtx;
    Journal& journal;


public:
    Compte(int _id, double _balance, Journal& _journal) : id(_id), balance(_balance), journal(_journal) {}

    inline int GetID() const { return id; }
    double GetBalance();
    void PutMoney(double _amount);
    bool Withdraw(double _amount);
};

