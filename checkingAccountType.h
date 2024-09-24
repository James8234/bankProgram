#ifndef CHECKINGACCOUNTTYPE_H
#define CHECKINGACCOUNTTYPE_H

#include <string>
#include "bankAccountType.h"

class checkingAccountType: public bankAccountType
{
	public:
   	checkingAccountType(std::string n, std::string acctNumber, double bal);

		//copy constructor
		checkingAccountType(const checkingAccountType &object);

      virtual void writeCheck(double amount) = 0;

		virtual bankAccountType *clone() const override = 0;

		virtual std::string getAccountType() const override;
};

#endif
