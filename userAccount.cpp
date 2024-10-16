//#include "counteract.h"
#include "userAccount.h"
#include "fileManager.h"
#include "header.h"
#include "deactivateAccount.h"

#include <termios.h>
#include <unistd.h>

/**
 * The purpose of this edit function is to update the user name and password when the user has choicen
 */

void userAccount::editUserAccount(userAccount *initialUser, vector<userAccount*> &userList)
{
	string tempName = initialUser->getUsername();
	string tempPassword = initialUser->getPassword();
	bool exitProgram = false;
	bool unsavedData = false;
	int choice = 0;
	char exit;

	string filepath = "./data/credentials.dat";

	int fd = open(filepath.c_str(), O_RDWR);

	if(fd == -1)
	{
		cout << "Error file could not open" << endl;
		cin.ignore(100000 , '\n');
		return;
	}

	if(!lockFile(fd))
	{
		cout << "The file is locked by another process." << endl;
		close(fd);
		cin.ignore(1000000 , '\n');
		return;
	}


	while(initialUser != nullptr && !(exitProgram))
	{
		cout << "\033c"; //clears the screen
		printEditUserAccount(tempName, tempPassword);

		choice = checkVaildInteger(5, -1);

		switch(choice)
		{
			case 0:
				getline(cin,tempName);
				unsavedData = true;
				break;
			case 1:
				getline(cin, tempPassword);
				unsavedData = true;
				break;
			case 2:
				unsavedData = false;
				exitProgram = true;
				initialUser->setUsername(tempName);
				initialUser->setPassword(tempPassword);
			case 3:
				if(unsavedData == true)
				{
					cout << "Are you sure you want to leave unsaved data? <Y/N> ";
					cin.get(exit);
					exit = toupper(exit);
					cin.ignore(10000 , '\n');
					
					if(exit == 'Y')
					{
						exitProgram = true;
					}
				}
				else
				{
					exitProgram = true;
				}
		} //switch(choice)

	} //while(node != nullptr && !(exitProgram))

	updateCredentialsFile(userList); //update the text file database

} //editAccount

void userAccount::printEditUserAccount(string tempName, string tempPassword)
{
	cout << "\033[1;32m";
	cout << "Edit your user account " << endl;
	printLine();
	cout << "<0> Name    -> " << tempName << endl;
	cout << "<1> Account -> " << tempPassword << endl;
	cout << "<2> SaveData" << endl;
	cout << "<3> Exit" << endl;
	printLine();
	cout << "\033[5;1;32m";
	cout << "Please enter here ->: ";
	cout << "\033[0m";
}


void userAccount::setUsername(string tempUsername)
{
	username = tempUsername;
}

void userAccount::setPassword(string tempPassword)
{
	password = tempPassword;
}


int getch() 
{
    int ch;
    // struct to hold the terminal settings
    struct termios old_settings, new_settings;
    // take default setting in old_settings
    tcgetattr(STDIN_FILENO, &old_settings);
    // make of copy of it (Read my previous blog to know
    // more about how to copy struct)
    new_settings = old_settings;
    // change the settings for by disabling ECHO mode
    // read man page of termios.h for more settings info
    new_settings.c_lflag &= ~(ICANON | ECHO);
    // apply these new settings
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
    // now take the input in this mode
    ch = getchar();
    // reset back to default settings
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
    return ch;
}

// Function to hide the password input and return the entered password
string hidePassword() 
{
    string hiddenPassword;
    int ch;

    cout << "Enter password: ";
    while ((ch = getch()) != '\n') {
        if (ch == 127 || ch == 8) {  // handle backspace
            if (!hiddenPassword.empty()) {
                hiddenPassword.pop_back();
                cout << "\b \b";  // Erase the last character
            }
        } else {
            hiddenPassword += ch;
            cout << "*";  // Print '*' for each character entered
        }
    }
    cout << endl;  // Move to the next line after password input
    return hiddenPassword;
}


userAccount::userAccount(const string& usr, const string& pswd, string userId, doublyLinkedListType *newLinkList, bool active, string userTypes)
{
	username = usr;
	password = pswd;
	id = userId;
	linkList = newLinkList;
	isActive = active;
	userType = userTypes;
}

string userAccount::getUserType()
{
	return userType;
}

//bool userAccount::getIsActive() const {
//	return isActive;
//}

string userAccount::getUsername()
{
	return username;
}

string userAccount::getPassword()
{
	return password;
}

string userAccount::getID() const
{
	return id;
}

doublyLinkedListType* userAccount::getLinkList()
{
	return linkList;
}

/**
 * FUNCTION void deleteAllAccounts
 * 
 * The purpose of this function is to clear the vector memory and the link list along
 * It will also reset the vector so that you can reload the vector with updated info from the database
 */
void userAccount::deleteAllAccounts(vector<userAccount*> &userList)
{
	//variables
	int element = 0;
	int index = 0;

	element = userList.size();

	while(element > index)
	{
		//a check because linklist pointer should be null unless the uesr login or created a account.
		if(userList[index]->getLinkList() != nullptr)
		{
			delete userList[index]->getLinkList();
		}

		delete userList[index];
		index++;
	}
	//reset the vector back to an empty state
	userList.clear();
}




bool userAccount::validLogin(const string &usr, const string &pswd, string id)
{
    return (usr == username && pswd == password);
}

/**
 * Function findAccountIndex
 */

int userAccount::findAccountIndex(vector<userAccount*> users, string username, string password)
{
	int i = 0;

	while( i < users.size())
	{
		if(users[i]->getUsername() == username && users[i]->getPassword() == password)
		{
			return i; //when accoun is found

		}
		else if(users[i]->getUsername() == username || users[i]->getPassword() == password)
		{
//			cout << "second case" << endl;
//			cin.ignore(10000 , '\n');
			return -2; //this function returns if one is true while the other is false
		}
		i++;
	}
	return -1; //if no account is found
}

/**
 * Function loginAccount
 */

int userAccount::loginAccount(vector<userAccount*> &users)
{
   //variables
	bool exitProgram = false;
	string usr = " ";
	string pass = " ";
   int choice = 0;
	int index = -1;

	//gets memory up to date
	deleteAllAccounts(users);
	readCredatialsFile(users);


   while(!(exitProgram))
   {
		//clears the screen
		cout << "\033c";

		//prints the UI
		printLoginAccount(usr, pass);
		
		//gets the user input
		choice = checkVaildInteger(4, -1);

		switch(choice)
		{
			case 0:
				cout << "Enter user name here ->: ";
				getline(cin,usr);
         	break;
			case 1:
				cout << "Enter password here ->: ";
         	pass = hidePassword();
            break;
         case 2:
				index = findAccountIndex(users, usr , pass);
									
				if(index >= 0)
				{
					users[index]->setLinkedListType(new doublyLinkedListType);
					return index; //returns the index of the uesr account
					exitProgram = true;
				}
				else
				{
					cout << "The username or password is Incorrect enter anything to continue" << endl;
					cin.ignore(10000 , '\n');
				}
									
				break;
			case 3:
         	exitProgram = true;
      }//switch(choice)

	}// while
	return -1; //used to end the program if no account is selected
}

void userAccount::printLoginAccount(string usr, string pass) //prints the ui for login
{

		cout << "\033[1;32m"; // for green light

		string str;
      int length = pass.length();
      str = string(length, '*');
	
		cout << "Login page" << endl;
		printLine();
		cout << "<0> Enter User: " << usr << endl;
		cout << "<1> Enter Password: " << pass << endl;
		cout << "<2> Push User/Password " << endl;
		cout << "<3> Exit " << endl;
		printLine();
		cout << "\033[5;1;32m";
		cout << "Please Enter a Number -->:" << endl;
		cout << "\033[0m";
}



int userAccount::createAccount(vector<userAccount*> &users)
{
	//variables
	string usr;
	string pswd;
	string id;
	int index = 0;

	//get user input
	cout << "Enter a username: ";
	getline(cin, usr);
	pswd = hidePassword();
	id = generateRandomAccountNumber();

	//gets memory up to date
	deleteAllAccounts(users);
	readCredatialsFile(users);
                
	index = findAccountIndex(users, usr, pswd);

//	cout << "in create account function ->: " << index << endl;
//	cin.ignore(10000 , '\n');
				
	//checks if the account already exist. returns a findAccountIndex returns a -1 when it dose not already exist
	if(0 > index && index != -2)
	{
      users.emplace_back(new userAccount(usr, pswd, id, new doublyLinkedListType));
		createAccountFile(users, usr, pswd, id);
		index = findAccountIndex(users, usr, pswd); // to make sure it returns the index of the created account and brings the user to the bank account page
	}
	else
	{
		cout << "Sorry, the account already exists. Enter anything to continue ->" << endl;
		index = -1; //to make sure it dosn't pick an account 
		cin.ignore(10000 , '\n');
	}

	return index;
}

/**
 * Function DisplayLoginMenu
 */
int userAccount::displayLoginMenu(vector<userAccount*> &users)
{
	int index = -1;
   int choice;
	bool exitProgram = false;
	deactivateAccount deactivateService;

	do 
	{
		//clear the screen
		cout << "\033c";

		printMainMenu();

     	choice = checkVaildInteger(5 , 0);

		switch (choice) 
		{      
			case 0:
				exitProgram = true;
				break;
			case 1:               
				index = createAccount(users);
				if(index > -1)
				{
					readAccountFile(users, index);
					return index;
				}
            break;
         case 2:
//cout << "check" << endl;
//cin.ignore(10000 , '\n');
				index = loginAccount(users);
//cout << "index is " << index << endl;
//cin.ignore(10000 , '\n');
            if(index > -1)
				{
					readAccountFile(users, index);
					return index;	
				}	
            break;
			case 3:
				cout << "\033c";
				bankEmployeeMenu(users);
				break;
			default:
				cout << "Invalid choice! Please try again.\n";	
		}//switch(chioce)
	
	} while (!(exitProgram));
	
	return -1;

}

void userAccount::printMainMenu()
{
	cout << "\033[1;32m";
	cout << "Welcome! Choose an option:\n";
	printLine();
	cout << "1. Create an account\n";
   cout << "2. Login\n";
   cout << "3. Bank Employee\n";
	cout << "0. Exit\n";
	printLine();
	cout << "\033[5;1;32m";
   cout << "Enter your choice -->: ";
	cout << "\033[0m";
}


void userAccount::print()
{
	cout << "\033[1;32m";
//	cout << "\033[1;32m";
	cout << "The username" << username << endl;
	cout << "The password" << password << endl;
	cout << "The id " << id << endl;
	cout << "\033[0m";
}

void userAccount::setLinkedListType(doublyLinkedListType *newList)
{
	if(linkList != nullptr)
	{
		delete linkList;
	}

	linkList = newList;

}


userAccount::userAccount() 
{
	isActive = true;  // set account as active when a user is created
}

void userAccount::deactivateAccountMenu(vector<userAccount*>& users) {
    int choice;
	
	// displays list of accounts that shows their active/inactive status
    cout << "List of accounts:\n";
    for (size_t i = 0; i < users.size(); i++) {
        cout << i + 1 << ". " << users[i]->getUsername() 
             << " (Status: " << (users[i]->getIsActive() ? "ACTIVE" : "INACTIVE") << ")\n";
    }

    cout << "Select an account to deactivate/reactivate (0 to cancel): ";
    cin >> choice;

    if (choice <= 0 || choice > users.size()) {
        cout << "Invalid or cancelled.\n";
        return;
    }

    userAccount* selectedAccount = users[choice - 1]; // get the account selected by the user


	// if the selected account is active, deactivate it
	// if not, reactivate the account
    if (selectedAccount->getIsActive()) {
        selectedAccount->setIsActive(false);
        cout << "Account " << selectedAccount->getUsername() << " has been deactivated.\n";
    } else {
        selectedAccount->setIsActive(true);
        cout << "Account " << selectedAccount->getUsername() << " has been reactivated.\n";
    }

	 cin.get();

    //updates the credentials file with new account status
    updateAccountFile(users);
}

// getter
string userAccount::getUserId() {
	return userId;
}

void userAccount::bankEmployeeMenu(vector<userAccount*>& users) {
    bool exitMenu = false;
    int choice = 0;

    while (!exitMenu) {
        cout << "\033[1;32m"; // Green color
        cout << "Bank Employee Menu:\n";
        cout << "1. View All User Accounts\n";
        cout << "2. Deactivate/Reactivate a User Account\n";
        cout << "3. Logout\n";
        printLine();
        cout << "\033[5;1;32m"; // Blink and green color
        cout << "Enter your choice: -->: ";
        cout << "\033[0m"; // Reset color

        choice = getUserChoice(1, 4);

        switch (choice) {
            case 1:
					 cout << "\033c";
                viewAllUserAccounts(users);
                break;
            case 2:
					 cout << "\033c";
                deactivateAccountMenu(users);
					 break;
            case 3:
                exitMenu = true;
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }

        if (!exitMenu) {
            cout << "Press Enter to continue...";
            cin.get(); // Wait for user to press Enter
        }
    }
}

int userAccount::getUserChoice(int min, int max) const {
    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail() || choice < min || choice > max) {
            cin.clear();
            cin.ignore(10000, '\n'); 
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        } else {
            cin.ignore(10000, '\n'); 
            break;
        }
    }
    return choice;
}

void userAccount::viewAllUserAccounts(const vector<userAccount*>& users) const {
    cout << "\033[1;34m"; // Blue color
    cout << "List of User Accounts:\n";
    printLine();
    cout << "ID\tUsername\tStatus\n";
    printLine();
    for (const auto& user : users) {
        cout << user->getID() << "\t" 
             << user->getUsername() << "\t\t" 
             << (user->getIsActive() ? "ACTIVE" : "INACTIVE") << "\n";
    }
    cout << "\033[0m"; // Reset color
}
