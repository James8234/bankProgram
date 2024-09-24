#ifndef HIGHINTERESTCHECKINGTYPE_H
#define HIGHINTERESTCHECKINGTYPE_H

#include <string>
#include "noServiceChargeCheckingType.h"

class highInterestCheckingType: public noServiceChargeCheckingType
{
	public:
		highInterestCheckingType(std::string n, std::string acctNumber, double bal);
		highInterestCheckingType(std::string n, std::string acctNumber, double bal,
                                                                                        double minBal, double intRate);
		//copy constructor
		highInterestCheckingType(const highInterestCheckingType &object);
	
		double getInterestRate();
		void setInterestRate(double intRate);
		void postInterest();
		void createMonthlyStatement();
		virtual void print() override;
		virtual std::string getAccountType() const override;

		virtual bankAccountType *clone() const override
		{
			return new highInterestCheckingType(*this);
		}

        private:
                static const double INTEREST_RATE; // = 0.05;
                static const double MIN_BALANCE; // = 5000.00;
};

#endif
