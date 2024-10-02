#include "transactionHistory.h"
#include "nodeType.h"
#include "bankAccountType.h"
#include "doublyLinkedListType.h"

#include <iostream>
#include <string>
#include <vector>

transaction::transaction(string t, int amt, int id)
	: type(t), amount(amt), transactionID(id) {
}

void displayTransactionHistory(const vector<transaction>& transactionHistory) {
	// const vector<transaction>& transactionHistory = node->data->getTransactionHistory();

	if (transactionHistory.empty()) {
		cout << "No transactions to display." << endl;
	} 
	else {
		cout << setfill('=') << setw(50) << "" << setfill(' ') << endl;
		cout << "Transaction History:" << endl;
		for (const auto& t : transactionHistory) {
			cout << "Transaction #" << t.transactionID + 1 << ": " << t.type << " of amount $" << t.amount << endl;
		}
	}
}
