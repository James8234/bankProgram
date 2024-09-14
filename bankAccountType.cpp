//implementation file

#include <iostream>
#include <string>
#include <iomanip>
#include "bankAccountType.h"

using namespace std;

bankAccountType::bankAccountType(string n, string acctNumber, double bal)
{
        name = n;
        accountNumber = acctNumber;
        balance = bal;
}

string bankAccountType::getAccountNumber()
{
        return accountNumber;
}

double bankAccountType::getBalance()
{
        return balance;
}

string bankAccountType::getName()
{
        return name;
}

void bankAccountType::setName(string n)
{
        name = n;
}

void bankAccountType::setAccountNumber(string num)
{
	accountNumber = num;
}

void bankAccountType::withdraw(double amount)
{
        balance = balance - amount;
}

void bankAccountType::deposit(double amount)
{
        balance = balance + amount;
}

void bankAccountType::print()
{
        cout << fixed << showpoint << setprecision(2);
        cout << name << " " << accountNumber << " balance: $"
                        << balance;
}
