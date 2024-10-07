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
#include "userAccount.h"
#include "fileManager.h"
#include <stdexcept>


 /**
 *
 *
 */

int main()
{
	//makes sure it exist and can be make to slove corrup files
	createSubdirectory();

	//variables
   int userChoice = 0;
	bool exitProgram = false;
	int totalNodes = 0;
	//memory variables
	nodeType *nodeAddress = nullptr;
	vector<userAccount*> userList; //make sure the account is recognized here
	userAccount *initialUser = nullptr; //constructor with default values wwill be used

	//This memeory variable store the transactionHistory
//	const vector<transaction> & transactionHistory

	//there should be a function for login here
	int index = 0;

	//This function reads in the text dataa base
	readCredatialsFile(userList);
	

	try
	{
		while(index >= 0)
		{
		
			
			//this function gets the index of the user instead replace it with no index but a call to read in the doublyed liked list from the file
			index = initialUser->displayLoginMenu(userList);

			if(index <= -1)
				throw std::runtime_error(" ");
		
		//This statement gets the index of the desired account and stores it in a userAccount object to pass arount
		if(userList[index]->getLinkList() != nullptr)
		{
			//this gets the linked list. a function is needed to read in the text file
			initialUser = userList[index]; 
		}
		else
		{
			cout << "Error: linked list pointer is null" << endl; //just to prevent crashes
		}

	exitProgram = false; // sets it back to false

	do
	{

	   cout << "\033c"; //clears to screen

		printAccountList(initialUser);
	
		totalNodes = nodeType::getNodeCount();

		userChoice = checkVaildInteger(totalNodes + 1, 0); //the +1 is because by check for vail integer dose not include the exact number but one off

		if(userChoice >= 2)
		{
			//this function gets the desired bankaccount
			nodeAddress = initialUser->getLinkList()->getAccountByIndex(userChoice);

			if(nodeAddress != nullptr)
			{
				accountUI(initialUser, nodeAddress);
			}
			else
			{
				cout << "A null was returned enter anything to continue" << endl;
				cin.ignore(100000 , '\n');
			}
		}
		else if(userChoice == 1)
		{
			addAccount(initialUser);
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
	
	initialUser->deleteAllAccounts(userList);

	return 0;
} //int main()
