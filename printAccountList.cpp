#include "header.h"
#include "doublyLinkedListType.h"
#include "nodeType.h"

void printAccountList(doublyLinkedListType *accountList)
{
	nodeType *current = accountList->getHead();
	int userChoice = 0;
	int index = 0;
	int row = 2;
	int totalAccounts = 0;

	cout << "Saucy Banking " << endl;
	printLine();
	cout << "Select an Account!" << endl;
	printLine();
	cout << "<0> Exit account: " << endl;
	cout << "<1> Create an account: " << endl;
	
	totalAccounts = nodeType::getNodeCount();


//	cout << "The account list will be output" << endl;
//	cin.ignore(10000 , '\n');

//	if(current == nullptr)
//	{
//		cout << "The current varible is nullptr";
//		cin.ignore(10000 , '\n');
//	}

//	if(accountList->getHead() == nullptr)
//	{
//		cout << "head variable is null" << endl;
//		cin.ignore(10000 , '\n');
//	}

	while(totalAccounts >= index && current != nullptr)
	{
		cout << "<" << row << "> " << "Name: " << current->data->getName() << " " << "ID: " << current->data->getAccountNumber() << endl;
		current = current->next;
		index++;
		row++;
	}
	
	printLine();
	cout << "Please enter a number here -->: ";
	
}
