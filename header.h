#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include "bankAccountType.h"
#include "savingsAccountType.h"
#include "highInterestSavingsType.h"
#include "noServiceChargeCheckingType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "certificateOfDepositType.h"
#include "checkingAccountType.h"

using namespace std;

//Account menu to add/delete/edit accounts
void account(vector<bankAccountType*> &);

//menu's
void printMainMenu();
void printAcctMenu();
void printAddAcctMenu();

//add delete and edit accounts
void addAccount(vector<bankAccountType*> &);
//void deleteAccount();
//void editAccount();


#endif
