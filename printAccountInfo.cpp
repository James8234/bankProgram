#include "header.h"
#include "nodeType.h"
#include "doublyLinkedListType.h"

void printAccountInfo(nodeType *node)
{
	cout << setfill('-') << setw(25) << " " << endl;
	cout << "<#> " << node->data->getAccountType() << endl;
	cout << setfill('-') << setw(25) << " " << endl;
	cout << " -  AccountNumber " << node->data->getAccountNumber() << endl;
	cout << " -  Name          " << node->data->getName() << endl;
	cout << " -  Balance     $ " << node->data->getBalance() << endl;
	cout << setfill('-') << setw(25) << " " << endl;
	cout << "Options : " << endl;
	cout << "<1> View account" << endl;
	cout << "<2> Withdraw" << endl;
	cout << "<3> Deposit " << endl;
	cout << "<4> Edit account" << endl;
	cout << "<5> Delete account" << endl;
	cout << "<6> Exit account" << endl;
	cout << setfill('-') << setw(25) << " " << endl;
	cout << "Please enter a number here-->: " ;

}

