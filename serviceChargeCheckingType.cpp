//implementation file

#include <iostream>
#include <string>
#include <iomanip>
#include "serviceChargeCheckingType.h"
#include "header.h"

using namespace std;

const double serviceChargeCheckingType::ACCOUNT_SERVICE_CHARGE = 10.00;
const int serviceChargeCheckingType::MAXIMUM_NUM_OF_CHECKS = 5;
const double serviceChargeCheckingType::SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS = 5;

serviceChargeCheckingType::serviceChargeCheckingType(string n, string acctNumber, double bal)
                                                                :checkingAccountType(n, acctNumber, bal)
{
        serviceChargeAccount = ACCOUNT_SERVICE_CHARGE;
        numberOfChecksWritten = 0;
        serviceChargeCheck = 0;
}

serviceChargeCheckingType::serviceChargeCheckingType(string n, string acctNumber, double bal, double servChargeAmount, double servChargeCheck)
                                                                : checkingAccountType(n, acctNumber, bal)
{
        serviceChargeAccount = servChargeAmount;
        serviceChargeCheck = servChargeCheck;
        numberOfChecksWritten = 0;
}

double serviceChargeCheckingType::getServiceChargeAccount()
{
        return serviceChargeAccount;
}

void serviceChargeCheckingType::setServiceChargeAccount(double amount)
{
        serviceChargeAccount = amount;
}

double serviceChargeCheckingType::getServiceChargeCheck()
{
        return serviceChargeCheck;
}

void serviceChargeCheckingType::setServiceChargeCheck(double amount)
{
        serviceChargeCheck = amount;
}

int serviceChargeCheckingType::getNumberOfChecksWritten()
{
        return numberOfChecksWritten;
}

void serviceChargeCheckingType::setNumberOfChecksWritten(int num)
{
        numberOfChecksWritten = num;
}

void serviceChargeCheckingType::postServiceCharge()
{
        balance = balance - serviceChargeAccount;
}

void serviceChargeCheckingType::writeCheck(double amount)
{
        if (numberOfChecksWritten < MAXIMUM_NUM_OF_CHECKS)
                balance = balance - amount;
        else
                balance = balance - amount - serviceChargeCheck;

        numberOfChecksWritten++;
}

void serviceChargeCheckingType::createMonthlyStatement()
{
        postServiceCharge();
}

void serviceChargeCheckingType::print()
{
        cout << "\033c";
        cout << fixed << showpoint << setprecision(2);

        cout << "< View account > " << endl;
        printLine();
        cout << "Account type:     " << getAccountType()    << endl
        << "Savings Account:       " << getName()           << endl
        << "ACCT#                  " << getAccountNumber()  << endl
        << "Balance:              $" << getBalance()        << endl
        << "SericeChargeAccount:   " << getServiceChargeAccount()   << endl
        << "ServiceChargeCheck:    " << getServiceChargeCheck() << endl
		  << "numberOfChecksWritten: " << getNumberOfChecksWritten() << endl;
        printLine();
        cout << "Enter anything to continue: ";
        cin.ignore(10000 , '\n');
}

string serviceChargeCheckingType::getAccountType() const 
{
	return "Service charge checking account";
}
