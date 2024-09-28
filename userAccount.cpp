#include "userAccount.h"
#include "header.h"

userAccount::userAccount(const string& usr, const string& pswd, string userId, doublyLinkedListType *newLinkList)
{
	username = usr;
	password = pswd;
	id = userId;
	linkList = newLinkList;
}

string userAccount::getUsername()
{
	return username;
}

string userAccount::getPassword()
{
	return password;
}

doublyLinkedListType* userAccount::getLinkList()
{
	return linkList;
}

bool userAccount::validLogin(const string &usr, const string &pswd, string id)
{
    return (usr == username && pswd == password);
}

/**
 * Function findAccountIndex
 */

int userAccount::findAccountIndex(vector<userAccount> users, string username, string password)
{
	int i = 0;
	while( i < users.size())
	{
		if(users[i].getUsername() == username && users[i].getPassword() == password)
		{
			return i; //when accoun is found
		}

		i++;
	}

	return -1; //if no account is found
}

/**
 * Function loginAccount
 */

int userAccount::loginAccount(vector<userAccount> &users)
{
   //variables
	bool exitProgram = false;
	string usr = " ";
	string pass = " ";
   int choice = 0;
	int index = -1;

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
				getline(cin,usr);
         	break;
			case 1:
         	getline(cin, pass);
            break;
         case 2:
				index = findAccountIndex(users, usr , pass);
									
				if(index >= 0)
				{
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
		cout << "Login page" << endl;
		printLine();
		cout << "<0> enter user: " << usr << endl;
		cout << "<1> enter a password: " << pass << endl;
		cout << "<2> push user/password " << endl;
		cout << "<3> exit login " << endl;
		printLine();
		cout << "please enter a number -->:" << endl;
}



void userAccount::createAccount(vector<userAccount> &users)
{
	//variables
	string usr, pswd;
	string id;
	doublyLinkedListType *newLinkList;

	//get user input
	cout << "Enter a username: ";
	getline(cin, usr);
	cout << "Enter a password: ";
	getline(cin, pswd);
	cout << "Enter an ID: ";
	getline(cin, id);
	cin.ignore(10000 , '\n'); //clear input buffer
				
	//checks if the account already exist. returns a findAccountIndex returns a -1 when it dose not already exist
	if(0 > findAccountIndex(users, usr, pswd))
	{
		newLinkList = new doublyLinkedListType;
      users.emplace_back(usr, pswd, id, newLinkList);
	}
	else
	{
		cout << "Sorry the account already exist. Enter anything to continue ->" << endl;
	}
}

int userAccount::displayLoginMenu(vector<userAccount> &users)
{
	int index = -1;
   int choice;
	bool exitProgram = false;

	cout << "\033c";

	do 
	{
		cout << "Welcome! Choose an option:\n";
		printLine();
		cout << "1. Create an account\n";
      cout << "2. Login\n";
      cout << "3. Exit\n";
		printLine();
      cout << "Enter your choice: -->: ";

     	choice = checkVaildInteger(4 , 0);

		switch (choice) 
		{      
			case 1:               
				createAccount(users);
				return (users.size() - 1);
            break;
         case 2:
				index = loginAccount(users);
            if(index > -1)
				{
					return index;	
				}	
            break;
			case 3:	               
				cout << "Exiting...\n";						
				exitProgram = true;                
				break;           
			default:
				cout << "Invalid choice! Please try again.\n";	
		}//switch(chioce)

 } while (!(exitProgram));
	
	return -1;

}


void userAccount::print()
{

	cout << "The username" << username << endl;
	cout << "The password" << password << endl;
	cout << "The id " << id << endl;
}

