#include "header.h"
#include "nodeType.h"
#include "doublyLinkedListType.h"
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

	while(node != nullptr && !(exitProgram))
	{
		//clear the screen
		cout << "\033c";

		printAccountInfo(node);
	
		choice = checkVaildInteger(6 , 0);
		
		switch(choice)
		{
			case 1:
				node->data->print(); //view account
				break;
			case 2:
				amount = checkVaildInteger(node->data->getBalance(), -1); //withdraw
				node->data->withdraw(amount);
				break;
			case 3:
				amount = checkVaildInteger(10000, -1);
				node->data->deposit(amount);
				break;
			case 4:
				initialUser->getLinkList()->editAccount(node);
				break;
			case 5:
				initialUser->getLinkList()->deleteAccount(node);
				exitProgram = true;
				break;
			case 6:
				exitProgram = true;
				break;
			default :
				cout << "An input error has occured" << endl;

		}//switch(choice)

	}//while(node != nullptr && !(exitProgram))

}//void
