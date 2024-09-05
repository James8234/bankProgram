#ifndef HIGHINTERESTSAVINGSTYPE_H_
#define HIGHINTERESTSAVINGSTYPE_H_

#include <string>
#include "savingAccountType.h"
using namespace std;

class highInterestSavingsType: public savingAccountType
{
public:
	highInterestSavingsType(string n, int acctNumber, double bal);
	highInterestSavingsType(string n, int acctNumber, double bal, 
								double intRate, double minBalance);
	highInterestSavingsType(string n, int acctNumber, double bal, string last);
	
	double getMinimumBalance();
	bool verifyMinimumBalance(double amount);
	virtual void withdraw(double amount);
	virtual void print();

protected:
	double minimumBalance;

private:
	static const double MINIMUM_BALANCE; //2500.00
	static const double INTEREST_RATE; // 0.05		

};

#endif
