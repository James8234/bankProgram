
#include "nodeType.h" 
#include "nodeType.h"
#include "doublyLinkedListType.h"
#include "bankAccountType.h"
#include <iostream>

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
	deleteNodeType();
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
	newNode->data = objData;
	
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

}

void doublyLinkedListType::deleteNodeType()
{
	nodeType *current;
	nodeType *nextNode;
	current = head;

	while(current != nullptr)
	{
		nextNode = current->next;
		delete current->data; //deletes the account
		delete current; //deletes the node
		current = nextNode;
	}
	
	head = nullptr;
	tail = nullptr; //just in case
}

void doublyLinkedListType::traverseLinkedList()
{
	nodeType *currentPtr;
	currentPtr = head;

	while(head != nullptr && currentPtr != nullptr)
	{
		currentPtr->data->print();
		currentPtr = currentPtr->next;
	}
//	cout << "Here is your head pointer" << head << " " << (head != nullptr) << endl;
//	cout << "Hello" << endl;
	cout << "head:" << (head != nullptr) << endl;
	cin.ignore(10000 , '\n');
}

/**
 * @function deleteAccount
 * @brief
 * This function purpose is to delete a account. It will set the node before and after node linking them together.
 * And then it delete the current pointer 
 */

void doublyLinkedListType::deleteAccount()
{
	//variables
	nodeType *current = nullptr;
	char choice;
	//clear the screen
	system("clear");

//	current = findNode(); //findNode returns a nullptr if no object is found	

	if(current != nullptr)
	{
		cout << "Delete Account" << endl;
		
		cout << "Are you sure you want to delete your account <y/n>" << endl;
		cin.get(choice);
		choice = toupper(choice);

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
		
		delete current;

	}
	else
	{
		cout << "account was not found enter anything to contine" << endl;
		cin.ignore(10000 , '\n');
		cin.ignore(10000 , '\n');
	}

}


//testing function
void doublyLinkedListType::getHead()
{
	if (head != nullptr) 
	{
		cout << "head exists." << endl;
	}
	else
	{
		cout << "Head is nullptr" << endl;
	}
}

bool doublyLinkedListType::lookUpAccount(int acctNum)
{
	nodeType* temp = head;
	while (temp != nullptr)
		{ if (temp->data->getAccountNumber() == acctNum)
		{	return true;
		}
		 temp = temp->next;
		}
	return false;
}
	

