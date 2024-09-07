#include "header.h"
#include "savingsAccountType.h"

using namespace std;

const double savingsAccountType::INTEREST_RATE = 0.03;

savingsAccountType::savingsAccountType(string n, int accNumber, double bal)
					: bankAccountType(n, accNumber, bal)
{
	interestRate = INTEREST_RATE;
}

savingsAccountType::savingsAccountType(string n, int accNumber, double bal, double intRate)
					: bankAccountType(n, accNumber, bal)
{
	setInterestRate(intRate);
}

double savingsAccountType::getInterestRate()
{
	return interestRate;
}

void savingsAccountType::setInterestRate(double rate)
{
	interestRate = rate;
}

void savingsAccountType::postInterest()
{
	balance = balance + balance * interestRate;
}

void savingsAccountType::createMonthlyStatement()
{
	postInterest();
}

void savingsAccountType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Savings Account:" << getName() << "\t ACCT# "
		  << getAccountNumber() << "\tBlance:" << getBalance() << endl;
}



