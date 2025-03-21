#include "header.h"
#include "nodeType.h"
#include "doublyLinkedListType.h"
#include "fileManager.h"
#include "userAccount.h"

/**
 * @file accountUI.cpp
 *
 * @brief 
 * the purpose of this function is to provide an ui for the user to choice.
 * The user can change there account in this menu
 */

/**
 * @brief
 * The function will carry out the logic by getting the user input. This input will be promted by the ui and 
 * used though a while skipping it if no node was found. The function will use a switch statment to use the input
 * The user will be able to 1. view account, 2. edit account 3. withdraw 4. deposit 5. delete account 6. exit.
 *
 * @details
 * The function has the object accountList in its argument to access its functions like editAccount/deleteAccount
 * return void
 */

void accountUI(userAccount *&initialUser, nodeType *&node)
{
	int choice = 0;
	int amount = 0;
	bool exitProgram = false;
	string activity = "";

	string userID = initialUser->getID();

	while(node != nullptr && !(exitProgram))
	{
		//clear the screen
		cout << "\033c";

		printAccountInfo(node);
	
		choice = checkVaildInteger(5 , 0);
		
		switch(choice)
		{
			case 1:
				node->data->print(); //view account
				break;
			case 2:
				cout << "\033[5;1;32m";
				printLine();
				cout << "Enter amount -->: ";
				cout << "\033[0m";
				amount = checkVaildInteger(node->data->getBalance(), -1); //withdraw
				node->data->withdraw(amount);
				updateBankAccountFile(initialUser);
				// log withdrawal
				activity = "Withdrawal of $" + to_string(amount) + " from account " + node->data->getAccountType() + " [" + node->data->getName() + "]";
				logActivity(initialUser->getID(), activity);
				break;
			case 3:
				cout << "\033[5;1;32m";
				printLine();
				cout << "Enter amount -->: ";
				cout << "\033[0m";
				amount = checkVaildInteger(10000, -1);
				node->data->deposit(amount);
				updateBankAccountFile(initialUser);
				// log deposit
				activity = "Deposit of $" + to_string(amount) + " to account " + node->data->getAccountType() + " [" + node->data->getName() + "]";
				logActivity(initialUser->getID(), activity);
				break;
			case 4:
				initialUser->getLinkList()->editAccount(node);
//				updateBankAccountFile(initialUser);
				break;
			case 5:
				initialUser->getLinkList()->deleteAccount(node);
				exitProgram = true;
				break;
			case 0:
				exitProgram = true;
				break;
			default :
				cout << "An input error has occured" << endl;

		}//switch(choice)

	//updates the text file
	updateBankAccountFile(initialUser);

	}//while(node != nullptr && !(exitProgram))

}//void
