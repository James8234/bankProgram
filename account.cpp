#include "header.h"
#include "savingsAccountType.h"
#include "highInterestSavingsType.h"
#include "noServiceChargeCheckingType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "certificationOfDepositType.h"


void account(vector<bankAccountType*>& accountsList)
{
  
  
  cout << "\033c";
  char userChoice = 0;
  do  {
     printAcctMenu();
     cout  << "Enter your choice: " << endl;
          cin  >> userChoice;

          //fixes input failure and does not allow the "enter correct choice" screen to repeat
          while (userChoice < 49 || userChoice > 53 ) {
                  cout << "\033c";
                  printAcctMenu();
                  cout << "Please enter a correct choice" << endl << endl;
                  cout << "Enter your choice:"  << endl;
                  cin  >> userChoice;
          }
    
          cout << "\033c";
          switch (userChoice) {
                  case '1':
                          cout << "Add Account" << endl;
                          addAccount(accountsList);
                          break;
                  case '2':
                          cout << "Edit Account" << endl;
                          //Edit Account();
                          break;
                  case '3':
                          cout << "Delete Account" << endl;
                          //deleteAccount();
                          break;
                  case '4':
                          cout << "View Account" << endl;
                          //viewAccount();
                          break;
                  case '5':
                          cout << "Exit" << endl;
                          break;
          }
          cout << endl;
  } while (userChoice != 53);

  
}


//***************************************
//
//
//
//                Menus
//
//
//
//**************************************/


void printAcctMenu(){
  cout << "1. Add Account" << endl;
  cout << "2. Edit Account" << endl;
  cout << "3. Delete Account" << endl;
  cout << "4. View Account" << endl;
  cout << "5. Exit" << endl;
}

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

void addAccount(vector<bankAccountType*>& accountsList){
        string name;
        int accountNumber;
        double balance;
        
        cout << "\033c";
        // Ask the user for their name, account number, and balance
            cout << "Enter account holder's name: " << endl;
            cin.ignore();  // To handle any newline characters left in the buffer
            getline(cin, name);

            cout << "Enter account number: " << endl;
            cin >> accountNumber;

            cout << "Enter initial balance: " << endl;
            cin >> balance;

        
          char userChoice = 0;
          do  {
             printAddAcctMenu();
             cout  << "Enter your choice: " << endl;
                  cin  >> userChoice;

                  //fixes input failure and does not allow the "enter correct choice" screen to repeat
                  while (userChoice < 49 || userChoice > 55 ) {
                          cout << "\033c";
                          printAddAcctMenu();
                          cout << "Please enter a correct choice" << endl << endl;
                          cout << "Enter your choice:"  << endl;
                          cin  >> userChoice;
                  }

                  cout << "\033c";
                  switch (userChoice) {                                 
                          case '1':
                                  //savings account 
                                  accountsList.push_back(new savingsAccountType(name, accountNumber, balance));
                                  cout << "Account Added";
                                  break;
                          case '2':
                                  //high interest savings account
                                  accountsList.push_back(new highInterestSavingsType(name, accountNumber, balance));
                                  cout << "Account Added";
                                  break;
                          case '3':
                                  //No Service Charge Checking Account
                                  accountsList.push_back(new noServiceChargeCheckingType(name, accountNumber, balance));
                                  cout << "Account Added";
                                  break;
                          case '4':
                                  //Service Charge Checking Account
                                  accountsList.push_back(new serviceChargeCheckingType(name, accountNumber, balance));
                                  cout << "Account Added";
                                  break;
                          case '5':
                                  //High Interest Checking Account
                                  accountsList.push_back(new highInterestCheckingType(name, accountNumber, balance));
                                  cout << "Account Added";
                                  break;
                          case '6':
                                  //Certificate of Deposit Account
                                  accountsList.push_back(new certificationOfDepositType(name, accountNumber, balance));
                                  cout << "Account Added";
                                  break;
                          case '7':
                                  //exit
                                  break;
                  }
                  cout << endl;
          } while (userChoice != 55);
  
}
