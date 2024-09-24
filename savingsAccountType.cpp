//implementation file

#include <iostream>
#include <string>
#include <iomanip>
#include "header.h"
#include "savingsAccountType.h"

using namespace std;

const double savingsAccountType::INTEREST_RATE = 0.03;

savingsAccountType::savingsAccountType(string n, string acctNumber, double bal)
                                : bankAccountType(n, acctNumber, bal) , interestRate(INTEREST_RATE) {}

// copy constructor
savingsAccountType::savingsAccountType(const savingsAccountType& object)
	: bankAccountType(object), interestRate(INTEREST_RATE) {} // Initialize with INTERSET_RATE

savingsAccountType::savingsAccountType(string n, string acctNumber, double bal, double intRate)
                                : bankAccountType(n, acctNumber, bal)
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
	cout << "\033c";
	cout << fixed << showpoint << setprecision(2);

	cout << "< View account > " << endl;
	printLine();
	cout << "Account type:    " << getAccountType() << endl;
	cout << "Savings Account: " << getName() << endl;
	cout << "ACCT#            " << getAccountNumber() << endl;
	cout << "Balance:        $" << getBalance() << endl;
	cout << "Interest Rate:   " << getInterestRate() << endl;
	printLine();
	cout << "Enter anything to continue: ";
	cin.ignore(10000 , '\n');

}

string savingsAccountType::getAccountType() const
{
	return "SavingAccount";
}
