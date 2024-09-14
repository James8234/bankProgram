#include "header.h"
#include "doublyLinkedListType.h"
#include "nodeType.h"

void printAccountList(doublyLinkedListType accountList)
{
	nodeType *current = accountList.getHead();
	int userChoice = 0;
	int index = 0;
	int row = 2;
	int totalAccounts = 0;

	cout << "Saucy Banking " << endl;
	cout << setfill ('-') << setw(25) << " " << setfill(' ') << endl;
	cout << "Select an Account!" << endl;
	printLine();
	cout << "<0> Exit account: " << endl;
	cout << "<1> Create an account: " << endl;
	
	totalAccounts = nodeType::getNodeCount();

	while(totalAccounts >= index && current != nullptr)
	{
		cout << "<" << row << "> " << "Name: " << current->data->getName() << " " << "ID: " << current->data->getAccountNumber() << endl;
		current = current->next;
		index++;
		row++;
	}
	
	cout << setfill('-') << setw(25) << " " << setfill(' ') << endl;
	
}
