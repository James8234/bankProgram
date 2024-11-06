#include "header.h"
#include "savingsAccountType.h"
#include "highInterestSavingsType.h"
#include "noServiceChargeCheckingType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "certificationOfDepositType.h"
#include "doublyLinkedListType.h"
#include "userAccount.h"
#include "fileManager.h"
#include <random>
#include <ctime>


void printAddAcctMenu()
{
	cout << "\033[1;32m"; //makes text green
	cout << "What kind of account would you like? " << endl;
	printLine();
	cout << "1. Savings Account" << endl;
	cout << "2. High Interest Savings Account" << endl;
	cout << "3. No Service Charge Checking Account" << endl;
	cout << "4. Service Charge Checking Account" << endl;
	cout << "5. High Interest Checking Account" << endl;
	cout << "6. Certificate of Deposit Account" << endl;
	cout << "7. Exit" << endl;
	printLine();
	cout << "\033[0m"; //sets colors back
}

string generateRandomAccountNumber()
{
	random_device rd;  // Random number generator
	mt19937 gen(rd()); // Seed the generator with a random device
	uniform_int_distribution<> dist(10000, 99999); // Distribution in the range [10000, 99999]

	return to_string(dist(gen));  // Convert the generated number to a string
}

void printAddAccounts(string acNum, string name, double balance, string accountType)
{
	cout << "\033[1;32m"; //makes green text
	cout << "------------------------" << endl;
   cout << "Enter Initial Information" << endl;
   cout << "------------------------" << endl;
   cout << "Account Number: " << acNum << endl;
	printLine();
   cout << "<1> Account Holder's Name:  " << name << endl;
   cout << "<2> Initial Balance:      $ " << balance << endl;
	cout << "<3> Choose Account Type:    " << accountType << endl;
	cout << "<4> Save Account" << endl;
	cout << "<0> Return to Account Menu" << endl;
	cout << "------------------------" << endl;
   cout << "please enter a number here-->: ";  // Ask user what they want to modify
	cout << "\033[0m"; //makes white text
}

void addAccount(userAccount *&initialUser)
{
   //variables
	string name = "EMPTY ";
	string accountNumber = generateRandomAccountNumber();
	double balance = 0.0;
	int accountTypeChoice = 0;
	int choice = 0;
	string accountType = "EMPTY";
	char leaveData;

	//LCV
	bool exitAddAccount = false;
	bool unsavedData = false;
	bool correctData = true;

	// Dynamically create a base account object
	bankAccountType* newAccount = nullptr;

	do
	{
		cout << "\033c"; // Clear screen

      // Display current entered information
		printAddAccounts(accountNumber, name, balance, accountType);

		// Input validation for choice
		choice = checkVaildInteger(4,0);

        // Switch case for user choices
		switch (choice)
		{
			case 0:
				// Return to previous menu
				if(unsavedData == true)
				{
      	   	cout << "Are you sure you want to leave unsavedData? y/n: ";
					cin.get(leaveData);
					leaveData = toupper(leaveData);
					cin.ignore(10000 , '\n'); //clea input buffer

					if(leaveData = 'Y')
					{
						exitAddAccount = true;
					}
				}
				else
				{
					exitAddAccount = true;
				}
				break;

			case 1:
				cout << endl;
				cout << "Enter account holder's name: ";
				getline(cin, name);
				unsavedData = true;
				break;

			case 2:
				cout << endl;
				cout << "Enter initial balance: ";
				cin >> balance;
				cin.ignore(10000 , '\n');
				unsavedData = true;
				break;

			case 3:
				cout << "\033c";
				printAddAcctMenu();  // Show account type options
				cout << "Enter account type: ";
				accountTypeChoice = checkVaildInteger(7, 1);
				unsavedData = true;
				break;

			case 4:
				// Create the correct account type and add it to the list
				if(unsavedData && accountTypeChoice > 0)
				{
					switch (accountTypeChoice)
					{
						case 1:
							newAccount = new savingsAccountType(name, accountNumber, balance);
							break;

						case 2:
							if(balance >= 2500)
							{
                        newAccount = new highInterestSavingsType(name, accountNumber, balance);
								correctData = true;
							}
							else
							{
								cout << "Please enter an amount higher than -> 2500. enter anything to continue" << endl;
								cin.ignore(10000 , '\n');
								correctData = false;			
							}
                     break;

						case 3:
							if(balance >= 1000)
							{
								newAccount = new noServiceChargeCheckingType(name, accountNumber, balance);
								correctData = true;
							}
							else
							{
								cout << "Please enter an amount higher than -> 1000. enter anything to continue" << endl;
								cin.ignore(10000 , '\n');
								correctData = false;
							}
							break;

						case 4:
							newAccount = new serviceChargeCheckingType(name, accountNumber, balance);
							break;

						case 5:
							if(balance >= 5000)
							{
                        newAccount = new highInterestCheckingType(name, accountNumber, balance);
								correctData = true;
							}
							else
							{
								cout << "Please enter an amount higher than -> 5000. enter anything to continue" << endl;
								cin.ignore(10000 , '\n');
								correctData = false;
							}
                     break;
						case 6:
							newAccount = new certificationOfDepositType(name, accountNumber, balance);
							break;
						default:
							cout << "Please select a valid account type before saving." << endl;
					}//switch(accountTypeChoice)

					// Add the new account to the list
					if(correctData == true)
					{
						//adds to the text data base
						createBankAccount(initialUser, newAccount->getAccountType(), name, accountNumber, balance);
						//adds to memory
						initialUser->getLinkList()->createNodeType(newAccount);
						exitAddAccount = true;//exits after account is create
					}
					else 
					{
						cout << "an error has accor enter anything to continue " << endl;
						cin.ignore(10000 , '\n');
					}                 
        			break;

				default: cout << "an input error has happened" << endl;

				}//if(unsavedData && accountTypeChoice > 0)

		}// switch(choice)


		//get accountType display from user unput
      switch (accountTypeChoice)
      {
      	case 1:
         	accountType = "Savings Account";
            break;
         case 2:
           	accountType = "High Interest Savings";
            break;
        	case 3:
            accountType = "No Service Charge Checking";
            break;
         case 4:
            accountType = "Service Charge Checking";
            break;
        case 5:
            accountType = "High Interest Checking";
            break;
        case 6:
            accountType = "Certificate of Deposit";
            break;
       default: cout << "Not Selected" << endl;
     }


	}while (!exitAddAccount);

	delete newAccount; //clean up
}
