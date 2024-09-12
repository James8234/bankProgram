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
	doublyLinkedListType accountsList;


	//there should be a function for login here

	do
	{
	
   system("clear"); //clears to screen

	printAccountList(accountsList);
	
	totalNodes = nodeType::getNodeCount();

	cout << "Please enter a number -->:";
	userChoice = checkVaildInteger(totalNodes + 1, 0);

	if(userChoice >= 2)
	{
		
	}
	else if(userChoice == 1)
	{
		addAccount(accountsList);
		
//		accountsList.getHead()->next;

	}
	else if(userChoice == 0)
	{
		exitProgram = true;
	}



	}while(!(exitProgram));

//	cout << "LOOPED" << endl;
//	cin.ignore(10000 , '\n');


//   do
//	{
  // 	printMainMenu();
      
//		cout  << "Enter your choice -->: " << endl;
     //fixes input failure and does not allow the "enter correct choice" screen to repeat
//    	userChoice = checkVaildInteger(3, 1);
		
//		cout << "\033c";
                      
//		switch (userChoice)
//		{
//	   	case 1:
//		   	account(accountsList);
//		   	break;
//	   	case 2:
//				cout << "Receipt Menu" << endl;
//				accountsList.traverseLinkedList();
				
  		   	//receipt();
//	   	   break;
  //		   case 3:
	//			exitProgram = true;	
	//			accountsList.traverseLinkedList();
//		      break;
	  //  } //switch (userChoice)
  
//	} while (!(exitProgram));



//	accountsLists.deleteNodeType();

	return 0;
} //int main()
