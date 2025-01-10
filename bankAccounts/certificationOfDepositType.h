#ifndef CERTIFICATIONOFDEPOSITTYPE_H
#define CERTIFICATIONOFDEPOSITTYPE_H

#include "bankAccountType.h"
#include <string>

class certificationOfDepositType: public bankAccountType
{
	public:
        certificationOfDepositType(std::string n, std::string acctNumber, double bal);
        certificationOfDepositType(std::string n, std::string acctNumber, double bal, double intRate, int maturityMon);

		//copy constructor
		certificationOfDepositType(const certificationOfDepositType &object);

        double getInterestRate();
        void setInterestRate(double rate);
        double getCurrentCDMonth();
        void setCurrentCDMonth(int month);
        int getMaturityMonths();
        void setMaturityMonths(int month);
        void postInterest();
        void withdraw(double amount);
        void withdraw();
        void createMonthlyStatement();

        virtual void print() override;

		~certificationOfDepositType() override {}

		virtual bankAccountType *clone() const override
		{
			return new certificationOfDepositType(*this);
		}


			virtual std::string getAccountType() const override;
private:
        static const double INTEREST_RATE;
        static const int NUMBER_OF_MATURITY_MONTHS;

        double interestRate;
        int maturityMonths;

        int cdMonth;
};

#endif
