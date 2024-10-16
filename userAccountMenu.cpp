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
		userChoice = checkVaildInteger(3, 0); //the +1 is because by check for vail integer dose not include the exact number but one off
	 
		switch(userChoice)
		{
			case 0 :
				exitProgram = true;
				break;
			case 1 :
				addAccount(initialUser);
				break;
			case 2 :
				updateBankAccountFile(initialUser);

				if(totalNodes > 0 && initialUser->getLinkList() != nullptr)
				{
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
				}
				else
				{
					cout << "Sorry there are no accounts enter anything to contine --> ";
					cin.ignore(100000 , '\n');
				}
				break;
			case 3 :
				//gets data up to date
				num = initialUser->findAccountIndex( userList, initialUser->getUsername(), initialUser->getPassword());
				initialUser->deleteAllAccounts(userList);
				readCredatialsFile(userList);
				initialUser = userList[num];
				readAccountFile(userList, num);
				initialUser->editUserAccount(initialUser, userList);
//				updateCredentialsFile(userList);
				break;
//			case 4 :
//				deleteUserAccount();
//				break;
			default :
				cout << "Input Error " << endl;
				cin.ignore(1000000 , '\n');
		}//switch(userChoice)

//once the user has selceted an bank account it will return its index and get the nodeAddress


	} while (!(exitProgram));

}
