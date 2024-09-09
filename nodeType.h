#ifndef NODETYPE_H
#define NODETYPE_H

#include <iostream>
#include "bankAccountType.h"

class nodeType
{
	public:

	nodeType *next;
	bankAccountType *data;
	nodeType *prev;

 	~nodeType() {};
	
	private:

};

#endif
