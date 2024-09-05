#ifndef SAVINGACCOUNTTYPE_H_
#define SAVINGACCOUNTTYPE_H_

#include <string>
#include "bankAccountType.h"

using namespace std;

class savingAccountType: public bankAccountType
{
public:
	savingAccountType(string n, int acctNumber, double bal);

	savingAccountType(string n, int acctNumber, double bal, double intRate);

	double getInterestRate();
	void setInterestRate(double rate);
	void postInterest();
	virtual void createMonthlyStatement();
	virtual void print();

protected:
	double interestRate;

private:
	static const double INTEREST_RATE; // = 0.03 //
};

#endif
