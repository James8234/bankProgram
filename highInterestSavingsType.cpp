#include "highInterestSavingsType.h"
#include "header.h"
//Define static constants
const double highInterestSavingsType::MINIMUM_BALANCE = 2500.000;
const double highInterestSavingsType::INTEREST_RATE = 0.05;




highInterestSavingsType::highInterestSavingsType(string n, int acctNumber, double bal)
							:savingsAccountType(n , acctNumber, bal)
{
	minimumBalance = MINIMUM_BALANCE;
}

//highInterestSavingsType::highInterestSavingsType(string n, int acctNumber, double bal, string last)
//							: savingsAccountType(n , acctNumber, bal)
//{
//	name = n;
//}

highInterestSavingsType::highInterestSavingsType(string n, int acctNumber, double bal,
														 double intRate, double minBalance)
							: savingsAccountType( n , acctNumber, bal, intRate)
{
	minimumBalance = minBalance;
}

//highInterestSavingsType::highInterestSavingsType(string n , int acctNumber, double bal, double intRate, string test)
//							: savingAccountType( n , acctNumber, bal, intRate)
//{

//}

double highInterestSavingsType::getMinimumBalance()
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

void highInterestSavingsType::createMonthlyStatement()
{
	cout << "highInterest account" << endl;
//	postInterest();
}

void highInterestSavingsType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "High interest savings: " << getName() << "\t ACCT# "
			<< getAccountNumber() << "\tBalance: $" << getBalance() << endl;
}

//void testFunction()
//{
//	cout << "this file is linked" << endl;
//}
