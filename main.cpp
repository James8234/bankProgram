#include "header.h"
#include "bankAccountType.h"
#include "certificationOfDepositType.h"
#include "checkingAccountType.h"
#include "highInterestSavingsType.h"
#include "savingsAccountType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "noServiceChargeCheckingType.h"

/**
 * 
 *
 *
 */

int main()
{
	vector<bankAccountType *> accountsList;
        
	//variables
   int userChoice = 0;
	bool exitProgram = false;



   cout << "\033c"; //clears to screen

   do
	{
   	printMainMenu();
      
		cout  << "Enter your choice -->: " << endl;
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

	return 0;
} //int main()

























        
        
        // accountsList.push_back(new savingsAccountType("Bill", 10200, 2500));
        // accountsList.push_back(new highInterestSavingsType("Susan", 10210, 2000));
        // accountsList.push_back(new noServiceChargeCheckingType("John", 20100, 3500));
        // accountsList.push_back(new serviceChargeCheckingType("Ravi", 30100, 1800));
        // accountsList.push_back(new highInterestCheckingType("Sheila", 20200, 6000));
        // accountsList.push_back(new certificateOfDepositType("Hamid", 51001, 18000, 0.075, 18));


        //in order for this to work I had to change the for loops from (int i = 0;) to the (vector<bankAccountType*>::size_type i = 0;)

    //     cout << "January:\n-------------" << endl;
    //     for (vector<bankAccountType*>::size_type i = 0; i < accountsList.size(); i++)
    //     {
    //             accountsList[i]->createMonthlyStatement();
    //             accountsList[i]->print();
    //             cout << endl;
    // }

    //     cout << "\nFebruary:\n-------------" << endl;
    //     for (vector<bankAccountType*>::size_type i = 0; i < accountsList.size(); i++)
    //     {
    //             accountsList[i]->createMonthlyStatement();
    //             accountsList[i]->print();
    //             cout << endl;
    //     }

    //     for (vector<bankAccountType*>::size_type i = 0; i < accountsList.size(); i++)
    //     {
    //             accountsList[i]->withdraw(500);
    //     }

    //     cout << "\nMarch:\n-------------" << endl;
    //     for (vector<bankAccountType*>::size_type i = 0; i < accountsList.size(); i++)
    //     {
    //             accountsList[i]->createMonthlyStatement();
    //             accountsList[i]->print();
    //             cout << endl;
    //     }
