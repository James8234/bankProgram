#include "header.h"
#include "doublyLinkedListType.h"
#include "nodeType.h"
#include "userAccount.h"

void printAccountList(userAccount *initialUser)
{
	nodeType *current = initialUser->getLinkList()->getHead();
	size_t index = 0;
	size_t row 	 = 0;
	size_t totalAccounts = 0;

	//clear the screen
	cout << "\033c";
	cout << "\033[1;32m";

	cout << "Saucy Banking " << endl;
	printLine();
	cout << "Select an Account!" << endl;
	printLine();


	totalAccounts = nodeType::getNodeCount();
	
	while(totalAccounts >= index && current != nullptr)
	{
		cout << "<" << row << "> " << "Name: " << current->data->getName() << " " << "ID: " << current->data->getAccountNumber() << endl;
		current = current->next;
		index++;
		row++;
	}
	
	printLine();
	cout << "\033[5;1;32m";
	cout << "Please enter a number here -->: ";	
	cout << "\033[0m";
}
