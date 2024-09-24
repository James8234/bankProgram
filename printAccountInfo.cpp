#include "header.h"
#include "nodeType.h"
#include "doublyLinkedListType.h"

void printAccountInfo(nodeType *node)
{
	printLine();
	cout << "<#> " << node->data->getAccountType() << endl;
	printLine();
	cout << " -  AccountNumber " << node->data->getAccountNumber() << endl;
	cout << " -  Name          " << node->data->getName() << endl;
	cout << " -  Balance     $ " << node->data->getBalance() << endl;
	printLine();
	cout << "Options : " << endl;
	cout << "<1> View account" << endl;
	cout << "<2> Withdraw" << endl;
	cout << "<3> Deposit " << endl;
	cout << "<4> Edit account" << endl;
	cout << "<5> Delete account" << endl;
	cout << "<6> Exit account" << endl;
	printLine();
	cout << "Please enter a number here-->: " ;

}

