#include "header.h"
#include "savingsAccountType.h"
#include "highInterestSavingsType.h"
#include "noServiceChargeCheckingType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "certificationOfDepositType.h"
#include "doublyLinkedListType.h"


void printAddAcctMenu(){
  cout << "What kind of account would you like? " << endl;
  cout << "1. Savings Account" << endl;
  cout << "2. High Interest Savings Account" << endl;
  cout << "3. No Service Charge Checking Account" << endl;
  cout << "4. Service Charge Checking Account" << endl;
  cout << "5. High Interest Checking Account" << endl;
  cout << "6. Certificate of Deposit Account" << endl;
  cout << "7. Exit" << endl;        
}


//****************************************
//
//
//              Add Account
//
//
//****************************************/

void addAccount(doublyLinkedListType accountsList)
{
	//variables
	string name;
	int accountNumber;
   double balance;
	int userChoice = 0;
	bool exitAddAccount = false;
        
   cout << "\033c";
   // Ask the user for their name, account number, and balance
   cout << "Enter account holder's name: " << endl;
   cin.ignore();  // To handle any newline characters left in the buffer
   getline(cin, name);

   cout << "Enter account number: " << endl;
   cin >> accountNumber;

   cout << "Enter initial balance: " << endl;
   cin >> balance;

		printAddAcctMenu();
      cout  << "Enter your choice: " << endl;
      userChoice = checkVaildInteger(8, 0);

		cout << "\033c";
		switch (userChoice)
		{                                 
		case 1:
      	//savings account 
      	accountsList.createNodeType(new savingsAccountType(name, accountNumber, balance));
      	cout << "Account Added";
      	break;
      case 2:
        	//high interest savings account
         accountsList.createNodeType(new highInterestSavingsType(name, accountNumber, balance));
         cout << "Account Added";
         break;
      case 3:
        //No Service Charge Checking Account
        accountsList.createNodeType(new noServiceChargeCheckingType(name, accountNumber, balance));
        cout << "Account Added";
        break;
      case 4:
        //Service Charge Checking Account
        accountsList.createNodeType(new serviceChargeCheckingType(name, accountNumber, balance));
        cout << "Account Added";
        break;
      case 5:
        //High Interest Checking Account
        accountsList.createNodeType(new highInterestCheckingType(name, accountNumber, balance));
        cout << "Account Added";
        break;
      case 6:
        //Certificate of Deposit Account
        accountsList.createNodeType(new certificationOfDepositType(name, accountNumber, balance));
        cout << "Account Added";
        break;
      case 7:
        //exit
			exitAddAccount = true;
       break;
      }
  
} 
