//implementation file

#include <iostream>
#include <string>
#include <iomanip>
#include "highInterestCheckingType.h"
#include "header.h"

using namespace std;

const double highInterestCheckingType::INTEREST_RATE = 0.05;
const double highInterestCheckingType::MIN_BALANCE = 5000.00;

highInterestCheckingType::highInterestCheckingType(string n, string acctNumber, double bal)
                                                                :noServiceChargeCheckingType(n, acctNumber, bal)
{
        minimumBalance = MIN_BALANCE;
        interestRate = INTEREST_RATE;
}

highInterestCheckingType::highInterestCheckingType(string n, string acctNumber,  double bal, double minBal, double intRate)
                                                                : noServiceChargeCheckingType(n, acctNumber, bal, minBal, intRate)
{
}

//copy constructor
highInterestCheckingType::highInterestCheckingType(const highInterestCheckingType &object)
	:noServiceChargeCheckingType(object)
{

        minimumBalance = MIN_BALANCE;
        interestRate = INTEREST_RATE;

}

double highInterestCheckingType::getInterestRate()
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

string highInterestCheckingType::getAccountType() const
{
	return "highInterestCheckingType";
}
