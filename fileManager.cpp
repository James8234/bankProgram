#include "fileManager.h"
#include "header.h"
#include "doublyLinkedListType.h"
#include "userAccount.h"
#include "bankAccountType.h"
#include "savingsAccountType.h"
#include "certificationOfDepositType.h"
#include "checkingAccountType.h"
#include "highInterestSavingsType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "noServiceChargeCheckingType.h"
#include <filesystem>

/**
 * Function
 * This function will get the updated linkedList from memory after using edit account and update the text file data base
 * This function will create an copy of the text file and replace it with the updated info
 */

void updateBankAccountFile(userAccount *&initialUser)
{

	//variables
	string username = " ";
	double bankBalance = 0;
	string userBalance = " ";
	string userID = " ";
	string userType = " ";
	string line = " ";
	string filepath = " ";

	nodeType *currentPtr = nullptr;
	string name1 = initialUser->getID();

	filepath = "./data/" + name1 + ".dat";

	//open the files
	ifstream file(filepath.c_str());
	ofstream temp("./data/temp.dat");

	if(!file.is_open())
	{
		cerr << "Error unable to open input file" << filepath << endl;
		cin.ignore(100000 , '\n');
	}

	if(!temp.is_open())
	{
		cerr << "Error unable to open output file for writing" << endl;
		cin.ignore(10000 , '\n');
	}

	currentPtr = initialUser->getLinkList()->getHead();
	
	while(currentPtr != nullptr && currentPtr->data != nullptr)	
	{
		//get the member variables of the class
		userType 	= currentPtr->data->getAccountType();
		username 	= currentPtr->data->getName();
		bankBalance = currentPtr->data->getBalance();
		userBalance = convertDoubleToString(bankBalance);
		userID 		= currentPtr->data->getAccountNumber();

		//create the class in textfile
		line = userType + ":" + username + ":" + userBalance + ":" + userID;

		temp << line << endl;

		currentPtr = currentPtr->next;
	}

	file.close();
	temp.close();
	remove(filepath.c_str());

	if(rename("./data/temp.dat", filepath.c_str()) != 0)
	{
		cerr << "error unable to rename temp file" << endl;
		cin.ignore(10000 , '\n');
	}

}



/**
 * Function voidCreateAccountFile
 * 
 * The function will create an user bank file connected to thier account
 * And then it will login the user into this text file
 */

void createAccountFile(vector<userAccount*> &userList, string username, string userPassword, string userId)
{
	string subdirectory = "./data/credentials.dat";
	string newAccountInfo = username + ":" + userPassword + ":" + userId;
	string newAccountFile = "./data/" + userId + ".dat";

	ofstream outfile(subdirectory.c_str(), ios::app);

	if(outfile)
	{
		outfile << newAccountInfo << endl;
	}

	outfile.close();
	
	//creates the user text file
	ofstream userfile(newAccountFile);
	
	userfile.close();
	//write a function readUserBankInfo which will set the linkedList
}

/**
 * function readAccountFile
 *
 * Purpose is to read in the user data. This function will open the text file username.dat and read the data into a doublyLinkedList 
 * the object will have the head pointer. the doublyLinkedList will be a deep copy as it populates in this function and saves its pointer
 * the the userAccount member function. The function will get the user name using the index and open the file using the user name + .dat 
 * Then it will load the string object, string nane, string balance, string id. and create a node . next it will loop again untill no more
 * text.
 */

void readAccountFile(vector<userAccount*> &userList, int index)
{
	string name = userList[index]->getID();
	string filepath = "./data/" + name + ".dat";	
	string line = " ";
	//variables
	string strObject = " ";
	string username = " ";
	string strBalance = " ";
	string userId = " ";
	//position varibales
	size_t firstPosition = 0;
	size_t secondPosition = 0;
	size_t thiredPosition = 0;
	//temp variable
	bankAccountType *newAccount = nullptr;


	ifstream outfile(filepath.c_str(), ios::app);

	

	if(outfile) //check if the file is open
	{
		while(getline(outfile, line))
		{


			//position returns the position from the start of the line
			firstPosition = line.find(':');
			secondPosition = line.find(':', firstPosition + 1);
			thiredPosition = line.find(':', secondPosition + 1); 

			if(firstPosition != string::npos && secondPosition != string::npos)
			{
				//./substr(start, end)
				strObject = line.substr(0, firstPosition);
				username = line.substr(firstPosition + 1, secondPosition - firstPosition - 1);
				strBalance = line.substr(secondPosition + 1, thiredPosition - secondPosition - firstPosition - 2);
				userId = line.substr(thiredPosition + 1);
			}

			//create a function that gets the object type from strObject
//			newAccount = createAccount();
				//once the object is read in
			newAccount = createAccountObject(strObject, username, strBalance, userId);

			if(newAccount != nullptr)
			{
				if(userList[index]->getLinkList() != nullptr)
				{
					userList[index]->getLinkList()->createNodeType(newAccount);
				}
				else
				{
					userList[index]->setLinkedListType(new doublyLinkedListType);
					userList[index]->getLinkList()->createNodeType(newAccount);
				}
				//clean up the pointer in the loop
				delete newAccount;
			}
		}//while(getline(outfile, line))
	}//if(outfile)
	else
	{
		cout << "error was not able to open file : " << filepath << endl;
		cout << "enter anything to continue ->: " << endl;
		cin.ignore(100000 , '\n');
	}
	outfile.close();
}

//the purpose of this function is to return a pointer to the objcet provided a string
bankAccountType *createAccountObject(string strObject, string username, string strBalance, string userId)
{
	double num = 0;

	try
	{
		num = stod(strBalance); //convert from string to double
	}
	catch(const std::invalid_argument& e)
	{
		cout << "error can not convert balance to int" << endl;
		num = 0;
	}

//	c0out << " the strObject is " << strObject << endl;

	if(strObject == "savingsAccountType")
	{
		return new savingsAccountType(username, userId, num);
	}
	else if(strObject == "certificationOfDepositType")
	{
		return new certificationOfDepositType(username, userId, num);
	}
	else if(strObject == "highInterestSavingsType")
	{
		return new highInterestSavingsType(username, userId, num);
	}
	else if(strObject == "serviceChargeCheckingType")
	{
		return new serviceChargeCheckingType(username, userId, num);
	}
	else if(strObject == "highInterestCheckingType")
	{
		return new highInterestCheckingType(username, userId, num);
	}
	else if(strObject == "noServiceChargeCheckingType")
	{
		return new noServiceChargeCheckingType(username, userId, num);
	}
	else
	{
		cout << "error" << endl;
	}

	//if no account was found
	return nullptr;

}

/**
 * Function createBankAccount
 * The purpose of this function is to add the created account to the text file
 * the user will add a object string, string username, string userPassword, double balance
 * the balance will be converted to balance and object string will be connected to the object
 */
void createBankAccount(userAccount *initialUser, string strObject, string username, string userId, int bal)
{
	string newBankAccountInfo = " ";
	string accountFile = "./data/" + initialUser->getID() + ".dat";

	//set the doublyLinkedList when the user has created an account

	string balance = std::to_string(bal);

	newBankAccountInfo = strObject + ":" + username + ":" + balance + ":" + userId;

	ofstream outfile(accountFile.c_str(), ios::app);

	if(outfile)
	{
		outfile << newBankAccountInfo << endl;
	}

	outfile.close();
}


/**
 * function createSubdirtory
 *
 * purpose is to exnsure that the required subdirectory and file exist
 * when the program starts. By creating the subdirectory data and the
 * file data.
 * it also should handles file corruption 
 */

void createSubdirectory()
{
	//Specify the subdirectory and flie name
	string subdirectory = "./data/";
	string filename     = "credentials.dat";
	string secondFileName = "./data/bankEmployeeCredentials.dat";
	
	//creates the subdirectory if it doesn't exist
	if(mkdir(subdirectory.c_str(), 0777) == -1)
	{
		if(errno != EEXIST)
		{
			cerr << "Error creating dirtory " << strerror(errno) << endl;
			//return 1; ends program
		}
	}

	
	//This if statment creates the text file if it doesn't exist
	if(!(filesystem::exists(secondFileName)))
	{
		ofstream temp(secondFileName.c_str());

		temp.close();
	}


}


/**
 * function readCredentialsFile
 * 
 * The purpose of this function is to read in the text file credntials.dat
 * into the memeory. When the program starts it read all accounts from
 * credentials into the vector
 */

void readCredatialsFile(vector<userAccount*> &accountList)
{
	//sets the dirtory
//"./data/credentials.dat"
	string filepath = "./data/credentials.dat";
	string line = " ";
	//account temp member variables
	string userName = " ";
	string userPassword = " ";
	string userId = " ";
	//position variables
	size_t firstPosition = 0;
	size_t secondPosition = 0;
	size_t thirdPosition = 0;
	//opens the file
	//ifstream infile(filepath.c_str(), ios::app);

	ifstream infile(filepath.c_str());
	
	if(!(infile.is_open()))
	{
		cout << "file did not open";	
	}

	while(getline(infile, line))
	{
		firstPosition = line.find(':');
		secondPosition = line.find(':', firstPosition + 1);
		thirdPosition = line.find(':', secondPosition + 1);
		// gets the username, password, and userid based on the positions
		if (firstPosition != string::npos && secondPosition != string::npos) {
            userName = line.substr(0, firstPosition);
            userPassword = line.substr(firstPosition + 1, secondPosition - firstPosition - 1);
            userId = line.substr(secondPosition + 1, (thirdPosition != string::npos) ? thirdPosition - secondPosition - 1 : string::npos);

            bool isActive = true; // the account is active by default

            // if a third position exists check if the account is active/inactive
            if (thirdPosition != string::npos) {
                string status = line.substr(thirdPosition + 1);
                isActive = (status == "active");
            }
				// adds the user account to the account list
            accountList.emplace_back(new userAccount(userName, userPassword, userId, nullptr, isActive));
        }

	}
	infile.close();
}


//the purpose of this function is to return a double from a string and if a expection happens its made zero
string convertDoubleToString(double bankBalance)
{
	string strNum = "0";

	try
	{
		strNum = to_string(bankBalance);
	}
	catch(const std::invalid_argument& e)
	{
		cout << "error can not convert balance to int" << endl;
		cin.ignore(10000 , '\n');
		strNum = "0";
	}

	return strNum;

}

// updates the credentials file with deactiavte/activated status
void updateAccountFile(const vector<userAccount*>& accountList) {
    string filepath = "./data/credentials.dat";
    ofstream outfile(filepath.c_str());

    if (!outfile.is_open()) {
        cout << "file did not open" << endl;
        return;
    }

    for (const auto& account : accountList) {
        string status = account->getIsActive() ? "active" : "inactive";
        outfile << account->getUsername() << ":" << account->getPassword() << ":" << account->getUserId() << ":" << status << endl;
    }

    outfile.close();
}
