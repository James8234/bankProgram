#ifndef DOUBLYLINKEDLISTTYPE_H
#define DOUBLYLINKEDLISTTYPE_H

#include "header.h"
#include "nodeType.h"
#include "bankAccountType.h"

class doublyLinkedListType
{
	public:
	//functions
	void createNodeType(bankAccountType *objData);
	void traverseLinkedList();
	void editAccount(nodeType *&node);
	void deleteAccount(nodeType *&node);
	nodeType *getAccountByIndex(int accountIndex);

	//print Functions
	void printDeleteAccount(nodeType *&node);
	void printEditAccount(string tempName, string tempID);

	//testingFunction
	nodeType *getHead();
	bool lookUpAccount();

	//clean function
	doublyLinkedListType();
	~doublyLinkedListType();
	void deleteNodeType();

	private:
		nodeType *head;
		nodeType *tail;

	bool lookUpAccount(string acctNum);

};



#endif
