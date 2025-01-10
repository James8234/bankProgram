#include "header.h"



void printAccountMenu()
{

	cout << "\033[1;32m";
	cout << "Saucy Banking " << endl;
	printLine();
	cout << "Select an Account!" << endl;
	printLine();
	cout << "<0> Logout " << endl;
	cout << "<1> Create a Bank Account " << endl;
	cout << "<2> Select Bank Account " << endl;
	cout << "<3> Edit User Account " << endl;
	cout << "<4> Transfer Money: " << endl;
	printLine();
	cout << "\033[5;1;32m";
	cout << "Enter your choice -->: ";
	cout << "\033[0m"; //sets back to white

	
}
