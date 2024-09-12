#include "header.h"
#include "nodeType.h"
#include "doublyLinkedListType.h"

void printAccountInfo(nodeType *node)
{
	system("clear");

	cout << setfill('-') << setw(25) << " " << endl;
	cout << "<#> " << node->data->getAccountType() << endl;
	cout << setfill('-') << setw(25) << " " << endl;
	cout << " -  AccountNumber " << node->data->getAccountNumber() << endl;
	cout << " -  Name          " << node->data->getName() << endl;
	cout << " -  Balance       " << node->data->getBalance() << endl;
	cout << setfill('-') << setw(25) << " " << endl;
	cout << "Options : " << endl;

	cin.ignore(1000 , '\n');

}

