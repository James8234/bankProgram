#include "header.h"
#include "./bankAccounts/bankAccountType.h"
#include "certificationOfDepositType.h"
#include "checkingAccountType.h"
#include "highInterestSavingsType.h"
#include "savingsAccountType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "noServiceChargeCheckingType.h"
#include "nodeType.h"
#include "doublyLinkedListType.h"
#include "userAccount.h"
#include "fileManager.h"
#include "bankEmployee.h"
#include "deactivateAccount.h"
#include "UI.h"
#include <stdexcept>

 /**
 *
 *
 */

int main()
{
	//makes sure it exist and can be make to solve corrup files
	createSubdirectory();

	//This vector stores all the user accounts
	vector<userAccount*> userList; //make sure the account is recognized here

	userAccount *initialUser = nullptr; //constructor with default values wwill be used

	//there should be a function for login here
	int index = 0;

	//This function reads in the text data base
	readCredatialsFile(userList);



	while(index >= 0)
	{

		//this function gets the index of the user instead replace it with no index but a call to read in the doublyed liked list from the file
		index = initialUser->displayLoginMenu(userList);

		if(index >= 0)
		{
			//This statement gets the index of the desired account and stores it in a userAccount object to pass arount
			if(userList[index]->getLinkList() != nullptr)
			{
				//this gets the linked list. a function is needed to read in the text file
				initialUser = userList[index]; 
			}
			else
			{
				cout << "Error: linked list pointer is null" << endl; //just to prevent crashes
				return 0;
			}

			//menu for managering your useraccount or bankaccount this is ment for a user
			userAccountMenu(initialUser, userList);

		}//if(index >= 0)

	} //while(index >= 0)

	//clean up
	initialUser->deleteAllAccounts(userList);

	//cleans ncurses memory
//	endwin();

	return 0;
} //int main()
