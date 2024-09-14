#ifndef NOSERVICECHARGECHECKINGTYPE_H
#define NOSERVICECHARGECHECKINGTYPE_H

#include <string>
#include "checkingAccountType.h"

class noServiceChargeCheckingType: public checkingAccountType
{
	public:
		noServiceChargeCheckingType(std::string n, std::string acctNumber, double bal);
		noServiceChargeCheckingType(std::string n, std::string acctNumber, double bal,
                                               double minBalance, double intRate);

		double getMinimumBalance();
		void setMinimumBalance(double minBalance);
		double getInterestRate();
		void setInterestRate(double rate);
		bool verifyMinimumBalance(double amount);
		void writeCheck(double amount);
		void withdraw(double amount);
		virtual void createMonthlyStatement();
		virtual void print() override;
		virtual std::string getAccountType() const override;

	protected:
		double minimumBalance;
		double interestRate;

	private:
		static const double MIN_BALANCE; // = 1000.00;
		static const double INTEREST_RATE; // = 0.02;
};

#endif
