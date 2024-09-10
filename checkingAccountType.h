#ifndef CHECKINGACCOUNTTYPE_H
#define CHECKINGACCOUNTTYPE_H

#include <string>
#include "bankAccountType.h"

class checkingAccountType: public bankAccountType
{
	public:
   	checkingAccountType(std::string n, int acctNumber, double bal);

      virtual void writeCheck(double amount) = 0;
};

#endif
