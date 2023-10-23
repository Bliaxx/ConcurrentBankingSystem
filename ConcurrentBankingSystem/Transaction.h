#pragma once
#include <chrono>
#include <string>

class Transaction
{
private:
    int accountId;
    double amount;
    std::string type;
    std::time_t timestamp;

public:
    Transaction(int _accountId, double _amount, const std::string& _type) : accountId(_accountId), amount(_amount), type(_type), timestamp(std::time(nullptr)) {}

    void Show() const;
};

