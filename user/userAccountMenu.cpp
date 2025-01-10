#include "header.h"
#include "userAccount.h"
#include "doublyLinkedListType.h"
#include "fileManager.h"
#include "tools.h"


void userAccountMenu(userAccount *initialUser, vector<userAccount*> &userList)
{

	size_t userChoice = 0;
	size_t totalNodes = 0;
	size_t index = 0;
	int num = 0;
	bool exitProgram = false;
	nodeType *nodeAddress = nullptr;
	string activity = "logged out";

	do 
	{
	   cout << "\033c"; //clears to screen
    
		printAccountMenu();

		totalNodes = doublyLinkedListType::getNodeCount();
		userChoice = checkVaildInteger(4, 0); //the +1 is because by check for vail integer dose not include the exact number but one off
	 
		switch(userChoice)
		{
			case 0 :
				//logs when the user logged out
				logActivity(initialUser->getID(), activity);
				exitProgram = true;
				break;
			case 1 :
				addAccount(initialUser);
				break;
			case 2 :

				//gets up to date data
				num = initialUser->findAccountIndex(userList, initialUser->getUsername(), initialUser->getPassword());
				initialUser->deleteAllAccounts(userList);
				readCredatialsFile(userList);
				initialUser = userList[num];
				readBankAccountFile(userList, num);

				if(initialUser->lockBankAccounts(initialUser)) // this function locked the file and returns false when locked
				{
					if(totalNodes > 0 && initialUser->getLinkList() != nullptr) //checks if there are accounts 
					{
						//I need a check for dead lock here
						printAccountList(initialUser);
						index = checkVaildInteger(totalNodes, 0);	

   		      	nodeAddress = initialUser->getLinkList()->getAccountByIndex(index);

				  		if (nodeAddress != nullptr) 
						{
  			      		accountUI(initialUser, nodeAddress);
  		      		} 
						else
						{
							printErrorMessage("A null was returned");
	       	 		}
						initialUser->unlockBankAccounts(initialUser); //unlocks the text file
					} //if(totalNodes > 0 && initialUser->getLinkList() != nullptr)
					else
					{
						printErrorMessage("Sorry there are no accounts");

					}
				} //if(lockBankAccount(initialUser))
				else
				{
					printErrorMessage("file is locked");
				}
				break;
			case 3 :
				//gets data up to date
				//gests the index of where this object is
				num = initialUser->findAccountIndex(userList, initialUser->getUsername(), initialUser->getPassword());
				//deletes all objectd in vector and linklist
				initialUser->deleteAllAccounts(userList);
				// loads the vector again and the linklist 
				readCredatialsFile(userList);
				// gets the object of the choicen index
				initialUser = userList[num];
				// reads the bank accouts for the index
				readBankAccountFile(userList, num);
				initialUser->editUserAccount(initialUser, userList);

				break;
			case 4 :
				if(initialUser->lockBankAccounts(initialUser)) // this function locked the file and returns false when locked
				{
					if(doublyLinkedListType::getNodeCount() > 1)
					{
						transferBetweenBankAccounts(initialUser);
					}
					else
					{
						printErrorMessage("Please create two accounts to transfer between.");
					}

					initialUser->unlockBankAccounts(initialUser); //unlocks the text file
				}
				break;
			default :
				printErrorMessage("Input Error");

		}//switch(userChoice)

//once the user has selceted an bank account it will return its index and get the nodeAddress
	} while (!(exitProgram));

}
