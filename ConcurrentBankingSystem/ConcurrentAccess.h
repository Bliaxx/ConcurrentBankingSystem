#pragma once
#include "Compte.h"

class ConcurrentAccess
{
private:
	static std::mutex mtx;
	Compte& account;

public:
	ConcurrentAccess(Compte& _account) : account(_account) {}

	void operator()();
};

