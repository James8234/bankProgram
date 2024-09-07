#ifndef CERTIFICATEOFDEPOSITTYPE_H
#define CERTIFICATEOFDEPOSITTYPE_H

#include "bankAccountType.h"
#include <string>

using namespace std;

class certificateOfDepositType: public bankAccountType
{
public:
        certificateOfDepositType(string n, int acctNumber, double bal);
        certificateOfDepositType(string n, int acctNumber, double bal, double intRate, int maturityMon);

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

        void print();

private:
        static const double INTEREST_RATE;
        static const int NUMBER_OF_MATURITY_MONTHS;

        double interestRate;
        int maturityMonths;

        int cdMonth;
};

#endif
