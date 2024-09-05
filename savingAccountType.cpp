#include <iostream>
#include <string>
#include <iomanip>
#include "savingAccountType.h"

using namespace std;

const double savingAccountType::INTEREST_RATE = 0.03;

savingAccountType::savingAccountType(string n, int accNumber, double bal)
					: bankAccountType(n, accNumber, bal)
{
	interestRate = INTEREST_RATE;
}

savingAccountType::savingAccountType(string n, int accNumber, double bal, double intRate)
					: bankAccountType(n, accNumber, bal)
{
	setInterestRate(intRate);
}

double savingAccountType::getInterestRate()
{
	return interestRate;
}

void savingAccountType::setInterestRate(double rate)
{
	interestRate = rate;
}

void savingAccountType::postInterest()
{
	balance = balance + balance * interestRate;
}

void savingAccountType::createMonthlyStatement()
{
	postInterest();
}

void savingAccountType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Savings Account:" << getName() << "\t ACCT# "
		  << getAccountNumber() << "\tBlance:" << getBalance() << endl;
}



