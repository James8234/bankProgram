//implementation file

#include <iostream>
#include <string>
#include "checkingAccountType.h"

using namespace std;

checkingAccountType::checkingAccountType(string n, std::string acctNumber, double bal)
                                                : bankAccountType(n, acctNumber, bal)
{
}

//copy constructor
checkingAccountType::checkingAccountType(const checkingAccountType &object)
	:bankAccountType(object) {}

string checkingAccountType::getAccountType() const
{
	return "checkingAccountType";
}
