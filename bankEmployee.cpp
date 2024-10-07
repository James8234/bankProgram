#include"bankEmployee.h"

void bankEmployee::viewAllaccounts(const vector<userAccount*>& users)
{
    cout << "Displaying all user accounts: " << endl;
    for(const auto& user : users)
    {
        cout << "Username: " << user->getUsername() << ", ID: " << user->id << ", Type: " << user->userType << endl;
    }
}

int bankEmployee::loginAccount(vector<userAccount*>& users)
{
    string usr, pswd;
    cout << "Enter username: ";
    cin >> usr;
    cout << "Enter password: ";
    cin >> pswd;

    int index = findAccountIndex(users, usr, pswd);
    if (index >= 0 && users[index]->userType == "bankEmployee")
    {
        cout << "Bank Employee login successful!" << endl;
        return index;
    }
    else
    {
        cout << "Invalid crendentials!" << endl;
        return -1;
    }
}
