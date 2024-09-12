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
	void deleteAccount();
	nodeType *getAccountByIndex(int accountIndex);

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

	bool lookUpAccount(int acctNum);

};



#endif
