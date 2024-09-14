#ifndef HIGHINTERESTSAVINGSTYPE_H
#define HIGHINTERESTSAVINGSTYPE_H

#include <string>
#include "savingsAccountType.h"


class highInterestSavingsType: public savingsAccountType
{
public:
        highInterestSavingsType(std::string n, std::string acctNumber, double bal);
        highInterestSavingsType(std::string n, std::string acctN, double balance, double intRate, double minBalance);
        double getMinimumBalance();
        bool verifyMinimumBalance(double amount);
        virtual void withdraw(double amount);
        virtual void print();

			virtual std::string getAccountType() const override;

protected:
        double minimumBalance;

private:
        static const double MINIMUM_BALANCE; // = 2500.00
        static const double INTEREST_RATE; // = 0.05
};

#endif
