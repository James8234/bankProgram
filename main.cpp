#include "header.h"
#include "bankAccountType.h"
#include "certificationOfDepositType.h"
#include "checkingAccountType.h"
#include "highInterestSavingsType.h"
#include "savingsAccountType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "noServiceChargeCheckingType.h"
#include "nodeType.h"
#include "doublyLinkedListType.h"
#include "login.h"
#include <stdexcept>

/**
 * 
 *
 *
 */

int main()
{

	//variables
   int userChoice = 0;
	bool exitProgram = false;
	int totalNodes = 0;
	nodeType *nodeAddress = nullptr;
	doublyLinkedListType *accountsList = nullptr;

	//there should be a function for login here
	int index = 0;
	vector<User> userList;
	User initialUser;

	try
	{
		while(index >= 0)
		{
	
			index = initialUser.displayLoginMenu(userList);
	
			if(index <= -1)
				throw std::runtime_error(" ");
		
		
		if(userList[index].getLinkList() != nullptr)
		{
			accountsList = userList[index].getLinkList();
		}
		else
		{
			cout << "Error: linked list pointer is null" << endl; //just to prevent crashes
		}

	exitProgram = false; // sets it back to false

	do
	{

	   cout << "\033c"; //clears to screen

		printAccountList(accountsList);
	
		totalNodes = nodeType::getNodeCount();

		userChoice = checkVaildInteger(totalNodes + 1, 0); //the +1 is because by check for vail integer dose not include the exact number but one off

		if(userChoice >= 2)
		{
			nodeAddress = accountsList->getAccountByIndex(userChoice);

			if(nodeAddress != nullptr)
			{
				accountUI(accountsList, nodeAddress);
			}
			else
			{
				cout << "A null was returned enter anything to continue" << endl;
				cin.ignore(10000 , '\n');
			}
		}
		else if(userChoice == 1)
		{
			addAccount(accountsList);
		}
		else if(userChoice == 0)
		{
			exitProgram = true;
		}

	}while(!(exitProgram));

	} //while(index >= 0)

	}
	catch(const std::runtime_error &e)
	{

	}
	catch(...)
	{

	}
	
	delete accountsList;

	return 0;
} //int main()
