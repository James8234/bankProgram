#ifndef CHECKINGACCOUNTTYPE_H_
#define CHECKINGACCOUNTTYPE_H_

#include <string>

#include "bankAccountType.h"

using namespace std;

class checkingAccountType: public bankAccountType
{
	public:
		checkingAccountType(string n, int accNumber, double bal);

		virtual void writeCheck(double amount) = 0;

};

#endif
