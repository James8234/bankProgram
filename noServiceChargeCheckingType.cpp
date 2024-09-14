//implementation file

#include <iostream>
#include <string>
#include <iomanip>
#include "noServiceChargeCheckingType.h"
#include "header.h"

using namespace std;

const double noServiceChargeCheckingType::MIN_BALANCE = 1000.00;
const double noServiceChargeCheckingType::INTEREST_RATE = 0.02;

noServiceChargeCheckingType::noServiceChargeCheckingType(string n, string acctNumber, double bal)
                                                                        : checkingAccountType(n, acctNumber, bal)
{
        minimumBalance = MIN_BALANCE;
        interestRate = INTEREST_RATE;
}

noServiceChargeCheckingType::noServiceChargeCheckingType(string n, string acctNumber, double bal,
                                                                                                                       double minBalance, double intRate)
                                                                        : checkingAccountType(n, acctNumber, bal)
{
        minimumBalance = minBalance;
        interestRate = intRate;
}

double noServiceChargeCheckingType::getMinimumBalance()
{
        return minimumBalance;
}

void noServiceChargeCheckingType::setMinimumBalance(double minBalance)
{
        minimumBalance = minBalance;
}

double noServiceChargeCheckingType::getInterestRate()
{
	return interestRate;
}

void noServiceChargeCheckingType::setInterestRate(double rate)
{
	interestRate = rate;
}

bool noServiceChargeCheckingType::verifyMinimumBalance(double amount)
{
        return (balance - amount >= minimumBalance);
}

void noServiceChargeCheckingType::writeCheck(double amount)
{
        if (verifyMinimumBalance(amount))
                balance = balance - amount;
}

void noServiceChargeCheckingType::withdraw(double amount)
{
        if (verifyMinimumBalance(amount))
                balance = balance - amount;
}

void noServiceChargeCheckingType::createMonthlyStatement()
{
}

void noServiceChargeCheckingType::print()
{
	cout << "\033c";
	cout << fixed << showpoint << setprecision(2);

	cout << "< View account > " << endl;
	printLine();
	cout << "Account type:    " << getAccountType()    << endl
        << "Savings Account: " << getName()           << endl
        << "ACCT#            " << getAccountNumber()  << endl
        << "Balance:        $" << getBalance()        << endl
        << "Interest Rate:   " << getInterestRate()   << endl
   	  << "Minimum balance  " << getMinimumBalance() << endl;
	printLine();
	cout << "Enter anything to continue: ";
	cin.ignore(10000 , '\n');
}

string noServiceChargeCheckingType::getAccountType() const
{
	return "No Service charge checking account" ;
}
