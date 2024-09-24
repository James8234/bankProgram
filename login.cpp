#include "login.h"
#include "header.h"

User::User(const string& usr, const string& pswd, int id, doublyLinkedListType *newLinkList)
{
	username = usr;
	password = pswd;
	id = id;
	linkList = newLinkList;
}

//User::User()
//{
//
//}

string User::getUsername()
{
	return username;
}

string User::getPassword()
{
	return password;
}

doublyLinkedListType* User::getLinkList()
{
	return linkList;
}



bool User::validLogin(const string &usr, const string &pswd, int id)
{
    return (usr == username && pswd == password);

	
}

/**
 * Function findAccountIndex
 */

int User::findAccountIndex(vector<User> users, string username, string password)
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

int User::loginAccount(vector<User> &users)
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

void User::printLoginAccount(string usr, string pass) //prints the ui for login
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



void User::createAccount(vector<User> &users)
{
	//variables
	string usr, pswd;
	int id;
	doublyLinkedListType *newLinkList;

	//get user input
	cout << "Enter a username: ";
	getline(cin, username);
	cout << "Enter a password: ";
	getline(cin, password);
	cout << "Enter an ID: ";
	cin >> id;
	cin.ignore(10000 , '\n'); //clear input buffer
			

			
	//checks if the account already exist. returns a findAccountIndex returns a -1 when it dose not already exist
	if(0 > findAccountIndex(users, usr, password))
	{
		newLinkList = new doublyLinkedListType;
      users.emplace_back(username, password, id, newLinkList);
	}
	else
	{
		cout << "Sorry the account already exist. Enter anything to continue ->" << endl;
	}
}

int User::displayLoginMenu(vector<User> &users)
{
	int index = -1;
    int choice;
	bool exitProgram = false;

	cout << "\033c";

    do 
	{
        std::cout << "Welcome! Choose an option:\n";
			printLine();
        std::cout << "1. Create an account\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";
			printLine();
        std::cout << "Enter your choice: -->: ";

        choice = checkVaildInteger(4 , 0);


        switch (choice) {
            case 1:
                createAccount(users);

						return (users.size() - 1);
                break;
            case 2:
					index = loginAccount(users);
                if(index > -1);
						{
							return index;	
						}
						
                break;
            case 3:
                std::cout << "Exiting...\n";
					exitProgram = true;

                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }

 } while (!(exitProgram));
	
	return -1;

}


void User::print()
{

	cout << "TEST" << endl;

}
