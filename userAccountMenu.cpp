#include "header.h"
#include "userAccount.h"
#include "doublyLinkedListType.h"
#include  "fileManager.h"


void userAccountMenu(userAccount *initialUser, vector<userAccount*> &userList)
{

	size_t userChoice = 0;
	size_t totalNodes = 0;
	size_t index = 0;
	int num = 0;
	bool exitProgram = false;
	nodeType *nodeAddress = nullptr;


	do 
	{
	   cout << "\033c"; //clears to screen
    
		printAccountMenu();

		totalNodes = nodeType::getNodeCount();
		userChoice = checkVaildInteger(4, 0); //the +1 is because by check for vail integer dose not include the exact number but one off
	 
		switch(userChoice)
		{
			case 0 :
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
	 		         	cout << "A null was returned enter anything to continue" << endl;
	  	         		cin.ignore(100000, '\n');
	       	 		}
						initialUser->unlockBankAccounts(initialUser); //unlocks the text file
					} //if(totalNodes > 0 && initialUser->getLinkList() != nullptr)
					else
					{
						cout << "Sorry there are no accounts enter anything to contine --> ";
						cin.ignore(100000 , '\n');
					}
				} //if(lockBankAccount(initialUser))
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
					if(nodeType::getNodeCount() > 1)
					{
						transferBetweenBankAccounts(initialUser);
					}
					else
					{
						cout << "Please create two accounts to transfer between. Enter anything to continue..." << endl;
						cin.ignore(10000 , '\n');
					}

					initialUser->unlockBankAccounts(initialUser); //unlocks the text file
				}
				break;
			default :
				cout << "Input Error " << endl;
				cin.ignore(1000000 , '\n');
		}//switch(userChoice)

//once the user has selceted an bank account it will return its index and get the nodeAddress
	} while (!(exitProgram));

}
