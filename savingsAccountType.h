#ifndef SAVINGSACCOUNTTYPE_H_
#define SAVINGSACCOUNTTYPE_H_

#include "header.h"
#include "bankAccountType.h"

class savingsAccountType: public bankAccountType
{
public:
	savingsAccountType(string n, int acctNumber, double bal);

	savingsAccountType(string n, int acctNumber, double bal, double intRate);

	double getInterestRate();
	void setInterestRate(double rate);
	void postInterest();
	virtual void createMonthlyStatement() override;
	virtual void print();

protected:
	double interestRate;

private:
	static const double INTEREST_RATE; // = 0.03 //
};

#endif
