//implementation file

#include <iostream>
#include <string>
#include <iomanip>
#include "highInterestSavingsType.h"
#include "header.h"

using namespace std;

const double highInterestSavingsType::MINIMUM_BALANCE = 2500.00;
const double highInterestSavingsType::INTEREST_RATE = 0.05;

highInterestSavingsType::highInterestSavingsType(string n, string acctNumber, double bal)
                                                : savingsAccountType(n, acctNumber, bal, INTEREST_RATE)
{
        minimumBalance = MINIMUM_BALANCE;
}

highInterestSavingsType::highInterestSavingsType(string n, string acctN, double balance, double intRate, double minBalance)                                                :savingsAccountType(n, acctN, balance, intRate)
{
//	cout << "This constructor was called" << endl;
//	cin.ignore(10000 , '\n');
	minimumBalance = minBalance;
}

//copy constructor
highInterestSavingsType::highInterestSavingsType(const highInterestSavingsType &object)
	: savingsAccountType(object), minimumBalance(MINIMUM_BALANCE) {}


bool highInterestSavingsType::verifyMinimumBalance(double amount)
{
	return (balance - amount >= minimumBalance);
}

void highInterestSavingsType::withdraw(double amount)
{
        if (verifyMinimumBalance(amount))
                        balance = balance - amount;
}

void highInterestSavingsType::print()
{
        cout << "\033c";
        cout << fixed << showpoint << setprecision(2);

        cout << "< View account > " << endl;
        printLine();
        cout << "Account type:    " << getAccountType() << endl
                  << "Savings Account: " << getName() << endl
                  << "ACCT#            " << getAccountNumber() << endl
                  << "Balance:        $" << getBalance() << endl
                  << "Interest Rate:   " << getInterestRate() << endl
						<< "Minimum balance  " << getMinimumBalance() << endl;
        printLine();
        cout << "Enter anything to continue: ";
        cin.ignore(10000 , '\n');
}

double highInterestSavingsType::getMinimumBalance()
{
		return MINIMUM_BALANCE;
}



string highInterestSavingsType::getAccountType() const
{
	return "highInterestSavingsType";
}
