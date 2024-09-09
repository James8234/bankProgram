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
//	vector<bankAccountType *> accountsList;
        
	//variables
   int userChoice = 0;
	bool exitProgram = false;
	doublyLinkedListType accountsList;

   cout << "\033c"; //clears to screen

   do
	{
   	printMainMenu();
      
//		cout  << "Enter your choice -->: " << endl;
     //fixes input failure and does not allow the "enter correct choice" screen to repeat
    	userChoice = checkVaildInteger(4, 0);
		
		cout << "\033c";
                      
		switch (userChoice)
		{
	   	case 1:
		   	account(accountsList);
		   	break;
	   	case 2:
				cout << "Receipt Menu" << endl;
  		   	//receipt();
	   	   break;
  		   case 3:
				exitProgram = true;
		      break;
	    } //switch (userChoice)
  
	} while (!(exitProgram));



//	accountsLists.deleteNodeType();

	return 0;
} //int main()
