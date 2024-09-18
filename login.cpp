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

int User::findAccountIndex(vector<User> users, string username, string password)
{
	int i = 0;
	while( i < users.size())
	{
		if(users[i].getUsername() == username && users[i].getPassword() == password)
		{
			return i;
		}

		i++;
	}

	return -1;

}



int User::loginAccount(vector<User> &users)
{
        //variables
        bool exitProgram = false;
			string usr = " ";
			string pass = " ";
  //      bool unsavedData = false;
        int choice = 0;
			int index = -1;
 //       char exit;

        while(!(exitProgram))
        {
                //clears the screen
                cout << "\033c";
                //prints the UI
					
             	cout << "Login page" << endl;
					printLine();
					cout << "<0> enter user: " << usr << endl;
					cout << "<1> enter a password: " << pass << endl;
					cout << "<2> push user/password " << endl;
					cout << "<3> exit login " << endl;
					printLine();
					cout << "please enter a number -->:" << endl;

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
										return index;
										exitProgram = true;
									}
									else
									{
										cout << "Incorrect username or password enter anything to continue" << endl;
										cin.ignore(10000 , '\n');
									}
									
									break;
								case 3:
                            exitProgram = true;
                }
				//findAccountIndex(user , username, password)
				

        }// while
		return -1;

}



void User::createAccount(vector<User> &users)
{
        string usr, pswd;
        int id;

			doublyLinkedListType *newLinkList;


        cout << "Enter a username: ";
        cin >> username;
        cout << "Enter a password: ";
        cin >> password;
        cout << "Enter an ID: ";
        cin >> id;


			

		if(0 > findAccountIndex(users, usr, password))
		{
			newLinkList = new doublyLinkedListType;
        users.emplace_back(username, password, id, newLinkList);
			        
        std::cout << "Account created successfully!\n";
		}
		else
		{
			cout << "Sorry the account already exist" << endl;
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
