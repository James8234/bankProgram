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
                double getInterestRate();
                void setInterestRate(double intRate);
                void postInterest();
                void createMonthlyStatement();
                virtual void print();

					virtual std::string getAccountType() const override;
        private:
                static const double INTEREST_RATE; // = 0.05;
                static const double MIN_BALANCE; // = 5000.00;
};

#endif
