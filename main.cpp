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
	int index = -1;
	vector<User> userList;
	User initialUser;
   index = initialUser.displayLoginMenu(userList);


	if(index <= -1)
	{
		return 0; //ends program
	}

	accountsList = *(userList[index].getLinkList());

	


//	initialUser.print();

//	doublyLinkedListType accountList;
//	userAccount user;

//	user = login();
//
//	accountList = *(user->getLinkedList());

	//the function isVaild will make sure that the data matchs and 
//	if(user.isVaild())
//	{ 
//
		//the rest of the code go's here
//	}




	do
	{
	
	   cout << "\033c"; //clears to screen

		printAccountList(accountsList);
	
		totalNodes = nodeType::getNodeCount();

		userChoice = checkVaildInteger(totalNodes + 1, 0); //the +1 is because by check for vail integer dose not include the exact number but one off

		if(userChoice >= 2)
		{
			nodeAddress = accountsList.getAccountByIndex(userChoice);

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
