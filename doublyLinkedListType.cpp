#include "nodeType.h" 
#include "nodeType.h"
#include "doublyLinkedListType.h"
#include "bankAccountType.h"
#include "userAccount.h"
#include "fileManager.h"
#include <iostream>

//const int doublyLinkedListType::ACCOUNT_OFFSET = 2;

/**
 * file doublyLinkedListType.cpp
 *
 * @brief
 * The purpose of this file is the contain the functions
 */

doublyLinkedListType::doublyLinkedListType()
{
	head = nullptr;
	tail = nullptr;
}

doublyLinkedListType::~doublyLinkedListType()
{
//	cout << "Within doublelinkedlist deconstructor " << endl;

	deleteNodeType();
//	cout << "deleteNodeType has been called" << endl;
//	cin.ignore(10000 , '\n');
//	cout << "After delete node type has been called " << endl;
}

/**
 * file doublyLinkedListType.cpp
 *
 * @brief
 * The purpose of this file is the contain the functions
 */


void doublyLinkedListType::createNodeType(bankAccountType *objData)
{
	nodeType *newNode;

	newNode = new nodeType;
	newNode->data = objData->clone();
	
	newNode->next = nullptr;
	newNode->prev = nullptr; //prevents errors

	if(head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	
	nodeType::incNodeCount();

}

/**
 * @function traverseLinkedList
 * @brief
 * This function purpose is traverse the link list
 * and output the
 */

void doublyLinkedListType::traverseLinkedList()
{
	nodeType *currentPtr;
	currentPtr = head;

	while(head != nullptr && currentPtr != nullptr)
	{
		currentPtr->data->print();
		currentPtr = currentPtr->next;
	}
	cin.ignore(10000 , '\n');
}

/**
 * @function deleteAccount
 * @brief
 * This function purpose is to delete a account. It will set the node before and after node linking them together.
 * And then it delete the current pointer 
 */

void doublyLinkedListType::deleteAccount(nodeType *&node)
{
	//variables
	nodeType *current = nullptr;
	char choice;
	//clear the screen
	cout << "\033c";

   //findNode returns a nullptr if no object is found	
	current = node;

	if(current != nullptr)
	{
		//display UI
		printDeleteAccount(node);

		//get user input
		cin.get(choice);
		choice = toupper(choice);
		cin.ignore(100000 , '\n');

		if(choice == 'N')
		{
			current = nullptr;
		} 
	}

	if(current != nullptr)
	{

		if(current->prev != nullptr)
		{
			current->prev->next = current->next;
		}
		else
		{
			head = current->next; //update the head before delete
		}

		if(current->next != nullptr)
		{
			current->next->prev = current->prev;
   	}
   	else
		{
			tail = current->prev; //update the tail before deleting it
		}
		delete current->data;
		delete current;
		current = nullptr;
		nodeType::decNodeCount();
	}
	else
	{
		if(choice == 'Y')
		{
			cout << "account was not found enter anything to contine" << endl;
			cin.ignore(10000 , '\n');
		}
	}

} //void

void doublyLinkedListType::printDeleteAccount(nodeType *node)
{
		cout << "Delete Account" << endl;
		printLine();
//		cout << node->data->getAccountType() << endl;
//		node->data->print();
		cout << node->data->getName() << endl;
		cout << node->data->getAccountNumber() << endl;
		printLine();
		cout << "Are you sure you want to delete your account <y/n> -->: ";
}


/**
 * @file getAccountByIndex
 *  
 * @brief
 * The purpose of this function is to get the user input and 
 * tranver to the desired account.
 *
 * @return *nodeType
 */

nodeType* doublyLinkedListType::getAccountByIndex(int accountIndex)
{
	nodeType *current = head;
	nodeType *previous = nullptr;
	accountIndex = accountIndex; //gets the accerate index sense the user choice start at one
	int index = 0;

	while(accountIndex >= index && current != nullptr)
	{
		previous = current;
		index++;
		current = current->next;
	}

	current = previous;

	return current;
}


/**
 * @file editAccount.cpp
 *  
 * @brief
 * The purpose of this function is to get the user input and 
 * tranver to the desired account.
 *
 * @return void
 */

void doublyLinkedListType::editAccount(nodeType *&node)
{
	//variables
	string tempName = node->data->getName();
	string tempID   = node->data->getAccountNumber();
	bool exitProgram = false;
	bool unsavedData = false;
	int choice = 0;
	char exit;

	while(node != nullptr && !(exitProgram))
	{
		//clears the screen
		cout << "\033c";
		//prints the UI
		printEditAccount(tempName, tempID);

		choice = checkVaildInteger(5, -1);

		switch(choice)
		{
			case 0:
				getline(cin,tempName);
				unsavedData = true;
				break;
			case 1:
				getline(cin, tempID);
				unsavedData = true;
				break;
			case 2:
				unsavedData = false;
				exitProgram = true;
				node->data->setName(tempName);
				node->data->setAccountNumber(tempID);
			case 3:
				if(unsavedData == true)
				{
					cout << "Are you sure you want to leave unsaved data? <Y/N> ";
					cin.get(exit);
					exit = toupper(exit);
					cin.ignore(10000 , '\n');
					if(exit == 'Y')
					{
						exitProgram = true;
					}
				}
				else
				{
					exitProgram = true;
				}
		} //switch(choice)

	} //while(node != nullptr && !(exitProgram))

}	//editAccount

void doublyLinkedListType::printEditAccount(string tempName, string tempID)
{
	cout << "Edit your account " << endl;	
	printLine();
	cout << "<0> Name    -> " << tempName << endl;
	cout << "<1> Account -> " << tempID   << endl;
	cout << "<2> SaveData" << endl;
	cout << "<3> Exit" << endl;
	printLine();
	cout << "Please enter here ->: ";
}



//testing function
nodeType* doublyLinkedListType::getHead()
{
	return head;
}

/**
 *
 */

bool doublyLinkedListType::lookUpAccount(string acctNum)
{
	nodeType* temp = head;
	while (temp != nullptr)
	{ 
		if (temp->data->getAccountNumber() == acctNum)
		{	
			 return true;
		}
		temp = temp->next;
	}
	return false;
}
	
/**
 * The purpose of this function is to clear all the nodes in linkedList when the program terminates
 */

void doublyLinkedListType::deleteNodeType()
{

	nodeType *current = head;
	nodeType *nextNode = nullptr;

	while(current != nullptr)
	{

		nextNode = current->next;

		delete current->data; //deletes the account
		delete current; //deletes the node

		current = nextNode;
	}
	
}

size_t doublyLinkedListType::getNodeCount() {
    size_t count = 0;
    nodeType* currentNode = head; // Assuming head points to the first node
    while (currentNode != nullptr) {
        count++;
        currentNode = currentNode->next; // Assuming next points to the next node
    }
    return count;
}

/**
 * copy constructor
 */

//doublyLinkedListType::doublyLinkedListType(const doublyLinkedListType &object)
//{
//	if(object



//}
