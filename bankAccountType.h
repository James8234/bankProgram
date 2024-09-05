#ifndef BANKACCOUNTTYPE_H_
#define BANKACCOUNTTYPE_H_

#include <iostream>
using namespace std;

class bankAccountType
{
public:
	bankAccountType(string n = "", int acctNumber = 0, double bal = 0);
	int getAccountNumber();
	double getBalance();
	string getName();
	void setName(string n);
	virtual void withdraw(double amount);
	void deposit(double amount);
	virtual void createMonthlyStatement() = 0; // this makes it a pure virtual function meaning you can't create the base class object and need child CLASSES
	virtual void print();

protected: //child classes have direct access but not int main
	int accountNumber;
	string name;
	double balance;

};

#endif
