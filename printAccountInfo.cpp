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
	cout << "<1> view rate" << endl;
	cout << "<2> withdraw" << endl;
	cout << "<3> Deposit " << endl;
	cout << "<4> edit account" << endl;
	cout << "<5> delete account" << endl;
	cout << "<6> exit account" << endl;
	cout << setfill('-') << setw(25) << " " << endl;
	cout << "please enter a number here-->: " ;

}

