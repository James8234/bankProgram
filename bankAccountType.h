#ifndef BANKACCOUNTTYPE_H
#define BANKACCOUNTTYPE_H

#include <string>

class bankAccountType
{

public:
	bankAccountType(std::string n = "", int acctNumber = 0, double bal = 0);
	int getAccountNumber();
   double getBalance();
   std::string getName();
   void setName(std::string n);
   virtual void withdraw(double amount);
   void deposit(double amount);
   virtual void createMonthlyStatement() = 0;
   virtual void print();
	virtual ~bankAccountType() {} //virtual destructor for proper cleanup

	virtual std::string getAccountType() const
	{
		return "Bank Account";
	}

protected:
   int accountNumber;
   std::string name;
   double balance;
};

#endif
