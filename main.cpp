#include "bankAccountType.h"
#include "header.h"
#include "savingAccountType.h"

#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "highInterestSavingsType.h"
#include "highInterestSavingsType.h"

#include "certificationOfDepositType.h"
#include "checkingAccountType.h"

int main()
{
	//variables
	int elements = 0;
	int index = 0;
	vector<bankAccountType *> accountList;

	//test fill classes
	accountList.push_back(new savingAccountType("Bill", 10200, 2500));

   accountList.push_back(new highInterestCheckingType("Bill", 10200, 2500));

	accountList.push_back(new noServiceChargeCheckingType("Joe" , 12000, 1500));

	accountList.push_back(new serviceChargeCheckingType("James" , 12000, 1500));

	accountList.push_back(new highInterestSavingsType("Colin" , 12000, 4500, "R"));

	//get elements
	elements = accountList.size();
//	cout << "your elements:" << elements << endl;
//	cin.ignore(10000 , '\n');

	if(elements > 0)
	{
		while( elements > index)
		{
			accountList[index]->print();
			index++;	
//			cout << "index:" << index << endl;
//			cin.ignore(1000000 , '\n');
		}
	}

//	delete [] accountList;

//	cout << " Hello world " << endl;

	//clear variables
//	studentType* studentPtr = nullptr;
	
	
	//saves the pointer 
//	studentPtr =  new studentType;

//	(*studentPtr).gpa = 3.9;
//	studentPtr->gpa = 3.9;

//	cout << "Your gpa is " << studentPtr->gpa << endl;

	

	
	

//	int *ptrNum = nullptr ;
//	int num =  25;

//	ptrNum = &num;

//	cout << " Your number is " << *ptrNum << endl;
//	cout << " Your number address is " << ptrNum << endl;

//	delete studentPtr;

	return 0;
}
