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
	doublyLinkedListType accountsList;


	//there should be a function for login here

	do
	{
	
	   cout << "\033c"; //clears to screen

		printAccountList(accountsList);
	
		totalNodes = nodeType::getNodeCount();

		cout << "Please enter a number -->:";
		userChoice = checkVaildInteger(totalNodes + 1, 0);

		if(userChoice >= 2)
		{
			nodeAddress = accountsList.getAccountByIndex(userChoice);
	//		cout << nodeType::getNodeCount();
	//		accountsList.traverseLinkedList();
	//		cin.ignore(10000 , '\n');

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

	return 0;
} //int main()
