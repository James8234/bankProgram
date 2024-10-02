//implementation file

#include <iostream>
#include <string>
#include <iomanip>
#include "certificationOfDepositType.h"
#include "header.h"

using namespace std;

const double certificationOfDepositType::INTEREST_RATE = 0.05;
const int certificationOfDepositType::NUMBER_OF_MATURITY_MONTHS = 6;

certificationOfDepositType::certificationOfDepositType(string n, string acctNumber, double bal)
                                                : bankAccountType(n, acctNumber, bal)
{
        interestRate = INTEREST_RATE;
        maturityMonths = 0;
        cdMonth = 0;
}

certificationOfDepositType::certificationOfDepositType(string n, string acctNumber, double bal, double intRate, int maturityMon)
                                                : bankAccountType(n, acctNumber, bal)
{
        interestRate = intRate;
        maturityMonths = maturityMon;
        cdMonth = 0;
}

//copy constructor
certificationOfDepositType::certificationOfDepositType(const certificationOfDepositType &object)
	:bankAccountType(object)
{
       interestRate = INTEREST_RATE;
        maturityMonths = 0;
        cdMonth = 0;
}

double certificationOfDepositType::getInterestRate()
{
        return interestRate;
}

void certificationOfDepositType::setInterestRate(double rate)
{
        interestRate = rate;
}

double certificationOfDepositType::getCurrentCDMonth()
{
        return cdMonth;
}

void certificationOfDepositType::setCurrentCDMonth(int month)
{
        cdMonth = month;
}

int certificationOfDepositType::getMaturityMonths()
{
        return maturityMonths;
}

void certificationOfDepositType::setMaturityMonths(int month)
{
        maturityMonths = month;
}

void certificationOfDepositType::postInterest()
{
        balance = balance + balance * interestRate;
}

void certificationOfDepositType::withdraw(double amount)
{
        //no withdraw until maturity
}

void certificationOfDepositType::withdraw()
{
        if (cdMonth > maturityMonths)
                balance = 0;
        else
                cout << "CD has not been matured. No withdrawal." << endl;
}

void certificationOfDepositType::createMonthlyStatement()
{
        postInterest();
        cdMonth++;
}

void certificationOfDepositType::print()
{
        cout << "\033c";
        cout << fixed << showpoint << setprecision(2);

        cout << "< View account > " << endl;
        printLine();
        cout << "Account type: " << getAccountType()    << endl
        << "Savings Account:   " << getName()           << endl
        << "ACCT#              " << getAccountNumber()  << endl
        << "Balance:          $" << getBalance()        << endl
        << "Interest Rate:     " << getInterestRate()   << endl
        << "MaturityMonths     " << getMaturityMonths() << endl
		  << "cdMonths           " << getCurrentCDMonth() << endl;

        printLine();
        cout << "Enter anything to continue: ";
        cin.ignore(10000 , '\n');
}

string certificationOfDepositType::getAccountType() const
{
	return "certificationOfDepositType";
}


