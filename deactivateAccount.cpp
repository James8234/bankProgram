#include "deactivateAccount.h"
#include <iostream>

using namespace std;

void deactivateAccount::deactivateUserAccount(userAccount& account) {
    if (account.isActive) {
        account.isActive = false;
        cout << "The account has been deactivated." << endl;
    }
    else {
        cout << "The account has already been deactivated." << endl;
    }
}