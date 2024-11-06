//#include "counteract.h"
#include "fileManager.h"
#include "header.h"
#include "deactivateAccount.h"
#include "tools.h"
#include "userAccount.h"
#include "bankAccountType.h"
#include "doublyLinkedListType.h"
#include "bankEmployee.h"

//print printTransferAccount 
//This prints the UI for transfering money

void printTransferBetweenBankAccount(const string &fromAccountType, const string &fromAccountName, const int &fromAccountBalance,const string &toAccountType, const string &toAccountName, const int &toAccountBalance, const int &amount)
{
		cout << "\033[1;32m";
		cout << "Transfer money between bank accounts" << endl;
		cout << "------------------------------------" << endl;
		cout << "<0> exit  "   << endl;
		cout << "<1> from: "
		<< left
		<< setw(25)
		<< fromAccountType << " : " 
		<< setw(15) 
		<< fromAccountName << "|$ " << fromAccountBalance << " | " << endl;
		cout << "<2> To:   "
		<< setw(25)
		<< toAccountType   << " : " 
		<< setw(15) 
		<< toAccountName   << "|$ " << toAccountBalance << " |" << endl;
		cout << "<3> amount: $" << amount << endl;
		cout << "<4> push" 	  << endl;
		cout << "------------------------------------" << endl;
		cout << "Enter your choice -->:";
		cout << right;
		cout << "\033[0m";
}

/**
 * FUNCTION transferBetweenBankAccounts
 *
 * This function is ment to allow the user to transfer between accounts.
 * It will save the node address of the two bank accounts. The requirements 
 * IS that the user has more than one account and that they can not select the 
 * same account twice. They must also have a balance to transfer.
 */

void transferBetweenBankAccounts(userAccount *initialUser)
{
	bool exitFunction = false;
	int  userChoice = 0;
	int index = 0;
	int totalNodes = 0;
	int amount = 0;
	string fromAccountType  = "";
	string fromAccountName  = "";
	int fromAccountBalance  = 0;
	string toAccountType 	= "";
	string toAccountName    = "";
	int 	 toAccountBalance = 0;
	nodeType *fromNode = nullptr;
	nodeType *toNode   = nullptr;

	totalNodes = doublyLinkedListType::getNodeCount();

	while(!(exitFunction))
	{
		//clear the screen
		cout << "\033c";

 		printTransferBetweenBankAccount(fromAccountType, fromAccountName, fromAccountBalance, toAccountType, toAccountName, toAccountBalance, amount);

		userChoice = checkVaildInteger(5 , 0);

		switch(userChoice)
		{
			case 0:
				exitFunction = true;
				break;
			case 1:
				printAccountList(initialUser);
				index = checkVaildInteger(totalNodes, 0);

					fromNode = initialUser->getLinkList()->getAccountByIndex(index);
					fromAccountType	 = fromNode->data->getAccountType();
					fromAccountName	 = fromNode->data->getName();
					fromAccountBalance = fromNode->data->getBalance();
				break;
			case 2:
				printAccountList(initialUser);
				index = checkVaildInteger(totalNodes, 0);
				toNode = initialUser->getLinkList()->getAccountByIndex(index);
				toAccountType	  = toNode->data->getAccountType();
				toAccountName	  = toNode->data->getName();
				toAccountBalance = toNode->data->getBalance();
				break;
			case 3:
				if(fromAccountBalance > 0)
				{
					amount = checkVaildInteger(fromAccountBalance, 0);
				}
				else
				{
					cout << "Sorry you don't have money to transfer" << endl;
					cin.ignore(10000 , '\n');
				}
				break;
			case 4:
				if(fromNode != toNode)
				{
					if(fromNode !=nullptr && toNode != nullptr)
					{
						fromNode->data->withdraw(amount);
						toNode->data->deposit(amount);
						exitFunction = true;
						updateBankAccountFile(initialUser);

						// log transfer
						string userId = " ";
						string activity = "Transfer of $" + to_string(amount) + " from " + fromAccountName + " to " + toAccountName;
						logActivity(userId, activity);
					}
					else
					{
						cout << "Please enter both accounts" << endl;
						cin.ignore(1000 , '\n');
					}
				}
				else
				{
					cout << "Error. enter anything to contiue -->:" << endl;
					cin.ignore(100000 , '\n');
				}
				break;
			default:
				cerr << "An input error has happened" << endl;
		}//switch(userChoice)
	}//while(!(exitFunction))
}

/**
 * FUNCTION lockBankAccounts
 *
 * The purpose of this function is to lock the bank accounts file so that only one computer can edit it at a time
 */

bool userAccount::lockBankAccounts(const userAccount *initialUser)
{
	string userID = initialUser->getID();

	string filepath = "./data/" + userID + "_bankAccountInfo.dat";

	int fd = open(filepath.c_str(), O_RDWR);

	if(fd == -1)
	{
//		cout << "Error file could not open" << endl;
//		cin.ignore(1000 , '\n');
		return 0;
	}

	if(!lockFile(fd)) //should return true when it locks the file
	{
		cout << "The file is locked by another process." << endl;
		close(fd);
		cin.ignore(1000000 , '\n');
		return 0;
	}

	return 1; //file is unlocked
}

/**
 * FUNCTION unlockBankAccounts
 *
 * The purpose of this function is to unlock the bank accounts file so that a second person can open the file
 */

void userAccount::unlockBankAccounts(const userAccount *initialUser)
{
	string userID = initialUser->getID();

	string filepath = "./data/" + userID + "_bankAccountInfo.dat";

	int fd = open(filepath.c_str(), O_RDWR);

	if(fd == -1)
	{
		cerr << "Error file could not open" << filepath << endl;
		cin.ignore(10000 , '\n');
		return;
	}

	unlockFile(fd);

	close(fd);
}



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
			case 1:
				getline(cin,tempName);
				unsavedData = true;
				break;
			case 2:
				getline(cin, tempPassword);
				unsavedData = true;
				break;
			case 3:
				unsavedData = false;
				exitProgram = true;
				initialUser->setUsername(tempName);
				initialUser->setPassword(tempPassword);
			case 0:
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
	cout << "<0> Exit" << endl;
	cout << "<1> Name    -> " << tempName << endl;
	cout << "<2> Account -> " << tempPassword << endl;
	cout << "<3> SaveData" << endl;
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

//constructor
userAccount::userAccount(const string& usr, const string& pswd, string userId, doublyLinkedListType *newLinkList, bool active)
{
	username = usr;
	password = pswd;
	id = userId;
	linkList = newLinkList;
	isActive = active;
}

/**
 * The purpose of this function is to get the class type to construct when reading in a text file. Or updating a text file and need to input the class type
 */
string userAccount::getClassName()
{
	return "userAccount";
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
	string pass = "";
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
			case 1:
				cout << "Enter user name here ->: ";
				getline(cin,usr);
         	break;
			case 2:
				cout << "Enter password here ->: ";
         	pass = hidePassword();
            break;
         case 3:
				//hash the password to find it in the data base
				pass = hasher(pass);
				index = findAccountIndex(users, usr , pass);

				if(index >= 0)
				{
					if(users[index]->getIsActive())
					{
						string activity = "Logged in";
						logActivity(users[index]->getID(), activity);
						users[index]->setLinkedListType(new doublyLinkedListType);
						return index; //exit loop
					}
					else
					{
						string activity = "Login Failed. Account deactivated.";
						logActivity(users[index]->getID(), activity);
						cout << "Your account is deactivated. Please reactivate it to login." << endl;
						cin.ignore(10000, '\n');
					}
				}
				else
				{
					//checks if the account name exists for the purpose of logging
					bool accountNameExists = false;
					for(size_t i = 0; i < users.size(); ++i)
					{
						accountNameExists = true;
						index = i;
						break;
					}
					if(!accountNameExists)
					{
						cout << "The username or password is Incorrect enter anything to continue" << endl;
						cin.ignore(10000 , '\n');
					}
					else if(accountNameExists)
					{
						//logs if user is correct but password is incorrect
						string activity = "Login attempt failed. Incorrect password";
						logActivity(users[index]->getID(), activity);
						cout << "The username or password is Incorrect enter anything to continue" << endl;
						cin.ignore(10000, '\n');
					}
				}
				break;
			case 0:
         	exitProgram = true;
      }//switch(choice)

	}// while
	return -1; //used to end the program if no account is selected
}

void userAccount::printLoginAccount(string usr, string pass) //prints the ui for login
{

		cout << "\033[1;32m"; // for green light

		string str;
      int length = pass.length(); //the password has one length before entering
      str = string(length, '*');
	
		cout << "Login page" << endl;
		printLine();
		cout << "<0> Exit " << endl;
		cout << "<1> Enter User: " << usr << endl;
		cout << "<2> Enter Password: " << str << endl;
		cout << "<3> Push User/Password " << endl;
		printLine();
		cout << "\033[5;1;32m";
		cout << "Please Enter a Number -->:" << endl;
		cout << "\033[0m";
}

// createAccount creates the userAccount object during account creation

int userAccount::createAccount(vector<userAccount*> &users)
{
	//variables
	string usr 		  = "";
	string pswd 	  = "";
	string id 		  = "";
	string userType  = "userAccount";
	string strActive = "1";
	int index 		  = 0;

	//get user input
	cout << "Enter a username: ";
	getline(cin, usr);

	pswd = hidePassword();

	// hash the password for storage
	pswd = hasher(pswd);

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
		createAccountFile(users, usr, pswd, id, userType, strActive);
		index = findAccountIndex(users, usr, pswd); // to make sure it returns the index of the created account and brings the user to the bank account page
		
		// log acc creation
		string activity = "Account created for user: " + usr + " ID: " + id;
		logActivity(userId, activity);
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

     	choice = checkVaildInteger(2 , 0);

		switch (choice)
		{
			case 0:
				exitProgram = true;
				break;
         case 1:
				index = loginAccount(users);
				if(index > -1 && users[index]->getClassName() == "userAccount")
				{
					readBankAccountFile(users, index);
					return index;	
				}
				else
				{
					cout  << "invalid" << endl;
					//bankEmployeeMenu(users);
				}
				break;
			case 2:
				index = loginAccount(users);
				if (index > -1 && users[index]->getClassName() == "bankEmployee")
				{
					bankEmployeeMenu(users, index);
				}
				else
				{
					cout << "invalid" << endl;
				}
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
	cout << "0. Exit Program\n";
   cout << "1. User Login\n";
	cout << "2. Employee Login\n";
	printLine();
	cout << "\033[5;1;32m";
   cout << "Enter your choice -->: ";
	cout << "\033[0m";
}


void userAccount::print()
{
	cout << "\033[1;32m";
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

void userAccount::deactivateAccountMenu(vector<userAccount*>& users)
{
    int choice;
	string userId = "";

	// displays list of accounts that shows their active/inactive status
    cout << "List of accounts:\n";
    for (size_t i = 0; i < users.size(); i++) 
	 {
        cout << i + 1 << ". " << users[i]->getUsername() 
             << " (Status: " << (users[i]->getIsActive() ? "ACTIVE" : "INACTIVE") << ")\n";
    }

    cout << "Select an account to deactivate/reactivate (0 to cancel): ";
    choice = checkVaildInteger(users.size(), 0);

    if (choice <= 0 || choice > users.size()) 
	 {
        cout << "Invalid or cancelled.\n";
        return;
    }

    userAccount* selectedAccount = users[choice - 1]; // get the account selected by the user

	userId = selectedAccount->getID();

	// if the selected account is active, deactivate it
	// if not, reactivate the account
   if(selectedAccount->getIsActive())
	{
        selectedAccount->setIsActive(0);
        cout << "Account " << selectedAccount->getUsername() << " has been deactivated.\n";

		// log acc deactivation


		string activity = "Account deactivated for user: " + selectedAccount->getUsername();
//cout << "before log activity" << endl;
//cin.ignore(10000 , '\n');
		logActivity(userId, activity);

    }
	 else 
	 {
        selectedAccount->setIsActive(1);
        cout << "Account " << selectedAccount->getUsername() << " has been reactivated.\n";

		// log acc reactivation
		string activity = "Account reactivated for user: " + selectedAccount->getUsername();
		logActivity(userId, activity);
    }

//	 cin.get();
//cout << "before update account file" << endl;
//cin.ignore(1000 ,'\n');


    //updates the credentials file with new account status
	updateCredentialsFile(users);
 //   updateAccountFile(users);
}

// getter
string userAccount::getUserId() {
	return userId;
}
