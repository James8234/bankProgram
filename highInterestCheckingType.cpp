#include <iostream>
#include <string>
#include <iomanip>


using namespace std;
#include "highInterestCheckingType.h"

const double highInterestCheckingType::MIN_BALANCE = 5000.000;
const double highInterestCheckingType::INTEREST_RATE = 0.05;


highInterestCheckingType::highInterestCheckingType(string n, int acctNumber, double bal)
							: noServiceChargeCheckingType(n , acctNumber, bal)
{
	minimumBalance = MIN_BALANCE;
	interestRate   = INTEREST_RATE;
	
}

highInterestCheckingType::highInterestCheckingType(string n, int acctNumber, double bal, double minBal, double intRate)
							: noServiceChargeCheckingType(n , acctNumber, bal, minBal, intRate)
{
	name = n;
	accountNumber = acctNumber;
	balance = bal;
	minimumBalance = minBal;
	interestRate = intRate;
	
	
}


double  highInterestCheckingType::getInterestRate()
{
	return interestRate;
}

void highInterestCheckingType::setInterestRate(double intRate)
{
	interestRate = intRate;
}

void highInterestCheckingType::postInterest()
{
	balance = balance + balance * interestRate;
}

void highInterestCheckingType::createMonthlyStatement()
{
	postInterest();
}



void highInterestCheckingType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "High interest Checking: " << getName() << endl
		  << "\tACCT# "      << getAccountNumber()	<< endl
		  << "\tBalance: $"   << getBalance()    		<< endl
		  << "\tMinBalance $" << getMinimumBalance() << endl
		  << "\tInterest"     << getInterestRate()   << endl;
}
