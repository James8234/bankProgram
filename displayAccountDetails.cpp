#include <iostream>
#include <iomanip>
#include "nodeType.h"
#include "doublyLinkedListType.h"
#include "bankAccountType.h"
#include "header.h"

void displayAccountDetails(nodeType* node) {
	if (!node || !node->data) {
	cout << "Invalid Account" << endl;
	return;
	}

	cout << "Account Details:" << endl;
	cout << setfill('=') << setw(50) << "" << setfill(' ') << endl;
	cout << "<Account Type>: " << node->data->getAccountType() << endl;
	cout << "<Account Number>: " << node->data->getAccountNumber() << endl;
	cout << "<Name>: " << node->data->getName() << endl;
	cout << "<Balance>: $" << fixed << setprecision(2) << node->data->getBalance() << endl;
	cout << setfill('=') << setw(50) << "" << setfill(' ') << endl;
}
