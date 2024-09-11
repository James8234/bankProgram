#include "header.h"
#include "savingsAccountType.h"
#include "highInterestSavingsType.h"
#include "noServiceChargeCheckingType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "certificationOfDepositType.h"
#include "doublyLinkedListType.h"

void account(doublyLinkedListType &accountsList)
{
	//variables  
	int userChoice = 0;
	bool exitAccount = false;   

	cout << "\033c";
  
	do
	{
		system("clear");
		printAcctMenu();
		cout  << "Enter your choice: " << endl;

		//fixes input failure and does not allow the "enter correct choice" screen to repeat
     
		userChoice = checkVaildInteger(6, 0);
    
      cout << "\033c";
      
		switch (userChoice)
		{
      	case 1:
         	cout << "Add Account" << endl;
            addAccount(accountsList);
           break;
         case 2:
            cout << "Edit Account" << endl;
            //Edit Account();
            break;
         case 3:
//            cout << "Delete Account" << endl;
				accountsList.deleteAccount();
				break;
			case 4:
				cout << "View Account" << endl;
				//viewAccount();
				break;
			case 5:
				cout << "Exit" << endl;
				exitAccount = true;
				break;
		}
	
  } while (!(exitAccount));
  
}


//***************************************
//
//
//
//                Menus
//
//
//
//**************************************/


void printAcctMenu(){
  cout << "1. Add Account" << endl;
  cout << "2. Edit Account" << endl;
  cout << "3. Delete Account" << endl;
  cout << "4. View Account" << endl;
  cout << "5. Exit" << endl;
}
