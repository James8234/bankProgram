#ifndef BANKACCOUNTTYPE_H
#define BANKACCOUNTTYPE_H

#include <string>

class bankAccountType
{

public:
	bankAccountType(std::string n = "", std::string acctNumber = 0, double bal = 0);
	std::string getAccountNumber();
	void setAccountNumber(std::string num);
   double getBalance();
   std::string getName();
   void setName(std::string n);
   virtual void withdraw(double amount);
   void deposit(double amount);
   virtual void createMonthlyStatement() = 0;
   virtual void print();
	virtual double getMinimumBalance();
	virtual ~bankAccountType() {} //virtual destructor for proper cleanup

	//constructor
	virtual bankAccountType* clone() const = 0;


	virtual std::string getAccountType() const
	{
		return "Bank Account";
	}

	virtual double getRate() const //not used
	{
		return 0;
	}

protected:
   std::string accountNumber;
   std::string name;
   double balance;
};

#endif
