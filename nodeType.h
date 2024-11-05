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

	std::string accountType;
    double balance;

	nodeType() : accountType(""), balance(0.0) {}

    // Parameterized constructor
    nodeType(std::string type, double initialBalance) : accountType(type), balance(initialBalance) {}
    
    void deposit(double amount) {
        balance += amount;
    }

	    // Withdraw method to decrease the balance
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient balance or invalid amount.\n";
        }
    }

 	~nodeType() 
	{
//		if(data)
//		{
//			delete data;
//			data = nullptr;
//		}
	}

	//static variable functions
	static int getNodeCount();
	static void incNodeCount();
	static void decNodeCount();	

	private:

	static int nodeCount;


};

#endif
