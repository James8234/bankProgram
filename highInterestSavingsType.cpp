#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
#include "highInterestSavingsType.h"

const double highInterestSavingsType::MINIMUM_BALANCE = 2500.000;
const double highInterestSavingsType::INTEREST_RATE = 0.05;


highInterestSavingsType::highInterestSavingsType(string n, int acctNumber, double bal)
							: savingAccountType(n , acctNumber, bal)
{
	minimumBalance = MINIMUM_BALANCE;
}

highInterestSavingsType::highInterestSavingsType(string n, int acctNumber, double bal, string last)
							: savingAccountType(n , acctNumber, bal)
{
	name = n;
}

highInterestSavingsType::highInterestSavingsType(string n, int acctNumber, double bal,
														 double intRate, double minBalance)
							: savingAccountType( n , acctNumber, bal, intRate)
{
	minimumBalance = minBalance;
}

double  highInterestSavingsType::getMinimumBalance()
{
	return minimumBalance;
}

bool highInterestSavingsType::verifyMinimumBalance(double amount)
{
	return (balance - amount >= minimumBalance);
}

void  highInterestSavingsType::withdraw(double amount)
{
	if(verifyMinimumBalance(amount))
		balance = balance - amount;
}

void highInterestSavingsType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "High interest savings: " << getName() << "\t ACCT# "
			<< getAccountNumber() << "\tBalance: $" << getBalance() << endl;
}
