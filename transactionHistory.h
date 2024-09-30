#ifndef TRANSACTION_HISTORY_H
#define TRANSACTION_HISTORY_H

#include <string>
#include <vector>

using namespace std;

class transaction {
public:
	string type;
	int amount;
	int transactionID;
	transaction(string t, int amt, int id);
};

void displayTransactionHistory(const vector<transaction> & transactionHistory);

#endif
