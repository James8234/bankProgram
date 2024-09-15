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


void addAccount(doublyLinkedListType &accountsList) {
    // variables
    string name;
    string accountNumber;
    double balance = 0.0;
    int accountTypeChoice;
    int choice;
    bool exitAddAccount = false;

    // Dynamically create a base account object
    bankAccountType* newAccount = nullptr;

    do {
        cout << "\033c"; // Clear screen

        // Display current entered information
        cout << "------------------------" << endl;
        cout << "Enter Initial Information" << endl;
        cout << "------------------------" << endl;
        cout << "<1> Account Holder's Name: " << name << endl;
        cout << "<2> Account Number: " << accountNumber << endl;
        cout << "<3> Initial Balance: $" << balance << endl;
        cout << "<4> Choose Account Type: ";
        switch (accountTypeChoice) {
            case 1: cout << "Savings Account" << endl;
                                                  break;
            case 2: cout << "High Interest Savings" << endl;
                                                  break;
            case 3: cout << "No Service Charge Checking" << endl;
                                                  break;
            case 4: cout << "Service Charge Checking" << endl;
                                                  break;
            case 5: cout << "High Interest Checking" << endl;
                                                  break;
            case 6: cout << "Certificate of Deposit" << endl;
                                                  break;
            default: cout << "Not Selected" << endl;
        }
        cout << "<5> Save Account" << endl;
        cout << "<0> Return to Account Menu" << endl;
        cout << "------------------------" << endl;

        // Ask user what they want to modify
        cout << "please enter a number here-->: ";

        // Input validation for choice
        choice = checkVaildInteger(5,0);

        // Switch case for user choices
        switch (choice) {
            case 1:
                cout << endl;
                cout << "Enter account holder's name: ";
                getline(cin, name);
                break;
            case 2:
                cout << endl;
                cout << "Enter account number: ";
                getline(cin, accountNumber);
                break;
            case 3:
                cout << endl;
                cout << "Enter initial balance: ";
                cin >> balance;
                break;
            case 4:
                cout << endl;
                printAddAcctMenu();  // Show account type options
                cout << "Enter account type: ";
                accountTypeChoice = checkVaildInteger(6, 1);
                break;
            case 5:
                // Create the correct account type and add it to the list
                switch (accountTypeChoice) {
                    case 1:
                        newAccount = new savingsAccountType(name, accountNumber, balance);
                        break;
                    case 2:
                        newAccount = new highInterestSavingsType(name, accountNumber, balance);
                        break;
                    case 3:
                        newAccount = new noServiceChargeCheckingType(name, accountNumber, balance);
                        break;
                    case 4:
                        newAccount = new serviceChargeCheckingType(name, accountNumber, balance);
                        break;
                    case 5:
                        newAccount = new highInterestCheckingType(name, accountNumber, balance);
                        break;
                    case 6:
                        newAccount = new certificationOfDepositType(name, accountNumber, balance);
                        break;
                    default:
                        cout << "Please select a valid account type before saving." << endl;
                        continue;
                }

                // Add the new account to the list
                accountsList.createNodeType(newAccount);
                cout << "Account saved successfully." << endl;

                // Reset for adding a new account
                newAccount = nullptr;
                name = "";
                accountNumber = "";
                balance = 0.0;
                accountTypeChoice = 0;
                break;
            case 0:
                // Return to previous menu
                cout << "Returning to Account Menu." << endl;
                exitAddAccount = true;
                break;
        }
    } while (!exitAddAccount);
}
