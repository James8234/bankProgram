#include "header.h"

void printAccountMenu()
{
	cout << "\033[1;32m";
	cout << "Saucy Banking " << endl;
	printLine();
	cout << "Select an Account!" << endl;
	printLine();
	cout << "<0> Exit account: " << endl;
	cout << "<1> Create an Bank account: " << endl;
	cout << "<2> Select Bank Account: " << endl;
	cout << "<3> Edit user account: " << endl;
//	cout << "<4> Delete user Account: " << endl;
	printLine();
	cout << "\033[5;1;32m";
	cout << "Please enter a number here -->: ";
	cout << "\033[0m"; //sets back to white
	
}
