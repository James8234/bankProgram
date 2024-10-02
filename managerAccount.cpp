#include "managerAccount.h"
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

/**
 * Function
 * This function will get the updated linkedList from memory after using edit account and update the text file data base
 */

void updateBankAccount(userAccount *initialUser)
{









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
	string newAccountFile = "./data/" + username + ".dat";

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
	string name = userList[index]->getUsername();
	string filepath = "./data/" + name + ".dat";	
	string line = " ";
	//variables
	string strObject = " ";
	string username = "";
	string strBalance = "";
	string userId = "";
	//position varibales
	size_t firstPosition = 0;
	size_t secondPosition = 0;
	size_t thiredPosition = 0;
//	bankAccountType *newAccount = nullptr;


	ifstream outfile(filepath.c_str(), ios::app);

	if(outfile)
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
			if(createAccountObject(strObject, username, strBalance, userId) != nullptr)
			{
				userList[index]->getLinkList()->createNodeType(createAccountObject(strObject, username, strBalance, userId));
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
		num = stod(strBalance);
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
	string accountFile = "./data/" + initialUser->getUsername() + ".dat";

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
	
	//creates the subdirectory if it doesn't exist
	if(mkdir(subdirectory.c_str(), 0777) == -1)
	{
		if(errno != EEXIST)
		{
			cerr << "Error creating dirtory " << strerror(errno) << endl;
			//return 1; ends program
		}
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
	//opens the file
	ifstream infile(filepath.c_str(), ios::app);
	
	if(!(infile.is_open()))
	{
		cout << "file did not open" ;	
	}

	while(getline(infile, line))
	{
		firstPosition = line.find(':');
		secondPosition = line.find(':', firstPosition + 1);

		if(firstPosition != string::npos && secondPosition != string::npos)
		{
			//./substr(start, end)
			userName = line.substr(0, firstPosition);
			userPassword = line.substr(firstPosition + 1, secondPosition - firstPosition - 1);
			userId = line.substr(secondPosition + 1);
			//creates the elements of the vector
   		accountList.emplace_back(new userAccount(userName,userPassword,userId,new doublyLinkedListType));
		}

	}
//	int elementCount = accountList.size();
//	int index = 0;

//	while(index < elementCount)
//	{
//		cout << "name: " <<	accountList[index].getUsername() << endl;
//		cout << "password: " << accountList[index].getPassword() << endl;
//		index++;
//	} 
}
