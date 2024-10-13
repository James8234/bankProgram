#include"bankEmployee.h"

void bankEmployee::viewAllaccounts(const vector<userAccount*>& users)
{
    cout << "Displaying all user accounts: " << endl;
    for(const auto& user : users)
    {
        cout << "Username: " << user->getUsername() << ", ID: " << user->getID() << ", Type: "  <<  getUserType() << endl; 
    }
}

int bankEmployee::loginAccount(vector<userAccount*>& users)
{
    string usr, pswd;
    cout << "Enter username: ";
    cin >> usr;
	cin.ignore(100000 , '\n');
    cout << "Enter password: ";
    cin >> pswd;
	cin.ignore(100000 , '\n');

    int index = findAccountIndex(users, usr, pswd);

    if (index >= 0 && users[index]->getUserType() == "bankEmployee")
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

void bankEmployee::bankEmployeeMenu()
{
	cout << "\033[1;32m";
	cout << "Banke Employee menu:\n";
	cout << "1. View all user accounts\n";
	cout << "2. Deactivate a user accounts\n";
	cout << "3. Reactivate a user account\n";
	cout << "4. Logout\n"
	printLine();
	cout << "\033[5;1;32m";
	cout << "Enter your choice: -->: ";
	cout << "\033[0m";
}

