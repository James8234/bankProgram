#ifndef HIGHINTERESTSAVINGSTYPE_H_
#define HIGHINTERESTSAVINGSTYPE_H_

#include "header.h"
#include "savingsAccountType.h"

class  highInterestSavingsType: public savingsAccountType
{
public:
	//uber constructors
	highInterestSavingsType(string n, int acctNumber, double bal);
//	highInterestSavingsType(string n, int acctNumber, double bal, string last);
	highInterestSavingsType(string n, int acctNumber, double bal, 
								double intRate, double minBalance);
//	highInterestSavingsType(string n, int acctNumber, double bal, double intRate, string test);

//	highInterestSavingsType();
	
	double getMinimumBalance();
	bool verifyMinimumBalance(double amount);
	virtual void createMonthlyStatement() override;
	virtual void withdraw(double amount) override;
	virtual void print();

protected:
	double minimumBalance;

private:
	static const double MINIMUM_BALANCE; //2500.00
	static const double INTEREST_RATE; // 0.05		

};

//void testFunction();

#endif
