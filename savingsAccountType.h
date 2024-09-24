#ifndef SAVINGSACCOUNTTYPE_H
#define SAVINGSACCOUNTTYPE_H

#include <string>
#include "bankAccountType.h"

class savingsAccountType: public bankAccountType
{
public:
        savingsAccountType(std::string n, std::string acctNumber, double bal);

        savingsAccountType(std::string n, std::string acctNumber, double bal, double intRate);
        virtual double getInterestRate();
        void setInterestRate(double rate);
        void postInterest();
        virtual void createMonthlyStatement();
        virtual void print() override;
			
			virtual std::string getAccountType() const override;

	//copy constructor
	savingsAccountType(const savingsAccountType& object);



	virtual bankAccountType* clone() const override
	{
		return new savingsAccountType(*this);
	}

protected:
        double interestRate;

private:
        static const double INTEREST_RATE; // = 0.3

};

#endif
