//implementation file

#include <iostream>
#include <string>
#include "checkingAccountType.h"

using namespace std;

checkingAccountType::checkingAccountType(string n, std::string acctNumber, double bal)
                                                : bankAccountType(n, acctNumber, bal)
{
}

string checkingAccountType::getAccountType() const
{
	return "Checking account";
}
