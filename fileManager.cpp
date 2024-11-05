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
#include "bankEmployee.h"
#include <filesystem>
#include <fstream>
#include <ctime>
//#include <unistd.h>
//#include <sys/file.h>


bool lockFile(int &fd)
{
	if(flock(fd, LOCK_EX | LOCK_NB) == -1)
	{ 
		return false; // meaning the file is locked
	}

//	cout << "The file has been locked" << endl;
//	cin.ignore(10000 , '\n');
	return true; //Acquire an exclusive lock
}	

bool unlockFile(int &fd)
{
	return flock(fd, LOCK_UN); //Release the lock
}

/**
 * FUNCTION lockBankAccounts
 *
 * The purpose of this function is to lock the bank accounts file so that only one computer can edit it at a time
 */
/*
bool lockBankAccounts(const userAccount *initialUser)
{
        string userID = initialUser->getID();

        string filepath = "./data/" + userID + "_bankAccountInfo.dat";

        int fd = open(filepath.c_str(), O_RDWR);

        if(fd == -1)
        {
//              cout << "Error file could not open" << endl;
//              cin.ignore(1000 , '\n');
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
*/
/**
 * FUNCTION unlockBankAccounts
 *
 * The purpose of this function is to unlock the bank accounts file so that a second person can open the file
 */
/*
void unlockBankAccounts(const userAccount *initialUser)
{
        string userID = initialUser->getID();

        string filepath = "./data/" + userID + ".dat";

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
*/

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
	string bankAccountType = " ";
	string line = " ";
	string filepath = " ";

	nodeType *currentPtr = nullptr;
	string id1 = initialUser->getID();

	filepath = "./data/" + id1 + "_bankAccountInfo.dat";

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
		bankAccountType 	= currentPtr->data->getAccountType();
		username 			= currentPtr->data->getName();
		bankBalance 		= currentPtr->data->getBalance();
		userBalance 		= convertDoubleToString(bankBalance);
		userID 				= currentPtr->data->getAccountNumber();

		//create the class in textfile
		line = bankAccountType + ":" + username + ":" + userBalance + ":" + userID;

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
 * Function
 * This function will update the vector from memory after using edit useraccount and update the text file data base
 * This function will create an copy of the text file and replace it with the updated info
 */

void updateCredentialsFile(vector<userAccount*> &userList)
{
	//variables
	string userType 		= " ";
	string userName 		= " ";
	string userPassword  = " ";
	string userId 			= " ";
	string strActive		= " ";
	bool	 userActive 	= 0;

	//temp variables
	string line = " ";
	string filepath = "./data/credentials.dat";
	int index = 0;
	size_t elements = 0;

	elements = userList.size();
	//open the files
	ifstream file(filepath.c_str());

	ofstream temp("./data/temp.dat");

	if(!file.is_open())
	{
		cerr << "Error unable to open input file" << filepath << endl;
		cin.ignore(100000 , '\n');
		return;
	}

	if(!temp.is_open())
	{
		cerr << "Error unable to open output file for writing" << endl;
		cin.ignore(10000 , '\n');
		return;
	}
	
	//this try statment handles exceptions like file corruption
	while(elements > index)	
	{
		//get the member variables of the class
		userType		 = userList[index]->getClassName();
		userName 	 = userList[index]->getUsername();
		userPassword = userList[index]->getPassword();
		userId 		 = userList[index]->getID();
		userActive	 = userList[index]->getIsActive();
		strActive	 = userActive ? "1" : "0"; // true or false

		//create the class in textfile
		line = userType + ":" + userName + ":" + userPassword + ":" + userId + ":" + strActive;

		temp << line << endl;

		index++;
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
 * When the user creates an account they will need to select an account
 */

void createAccountFile(vector<userAccount*> &userList, string username, string userPassword, string userId, string userType, string strActive)
{
	string subdirectory = "./data/credentials.dat";
	string newAccountInfo = userType + ":" + username + ":" + userPassword + ":" + userId + ":" + strActive;
	string newAccountFile = "./data/" + userId + "_bankAccountInfo.dat";

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

void readBankAccountFile(vector<userAccount*> &userList, int index)
{
	string userID = userList[index]->getID();
	string filepath = "./data/" + userID + "_bankAccountInfo.dat";	
	string line = "";
	//variables
	string strObject = " ";
	string username = " ";
	string strBalance = " ";
	string userId = " ";
	//position varibales
	size_t firstPosition  = 0;
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
	string accountFile = "./data/" + initialUser->getID() + "_bankAccountInfo.dat";

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
	string secondSubdirectory = "./logs/";
	string filename     = "credentials.dat";
//	string secondFileName = "./data/bankEmployeeCredentials.dat";

	//creates the subdirectory if it doesn't exist
	if(mkdir(subdirectory.c_str(), 0777) == -1)
	{
		if(errno != EEXIST)
		{
			cerr << "Error creating dirtory " << strerror(errno) << endl;
			//return 1; ends program
		}
	}

	if(mkdir(secondSubdirectory.c_str(), 0777) == -1)
	{
		if(errno != EEXIST)
		{
			cerr << "Error creating dirtory" << strerror(errno) << endl;
		}
	}

	//This if statment creates the text file if it doesn't exist
//	if(!(filesystem::exists(secondFileName)))
//	{
//		ofstream temp(secondFileName.c_str());

//		temp.close();
//	}
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
	string line     = " ";
	//account temp member variables
	string userType 		= " ";
	string userName 		= " ";
	string userPassword  = " ";
	string userId 			= " ";
	string strActive		= " ";
	bool	 userActive 	= 0;
	//position variables
	size_t firstPosition  = 0;  // userType
	size_t secondPosition = 0; //userName
	size_t thirdPosition  = 0;  // userpassword
	size_t fourthPosition = 0; // user id
	size_t fifthPosition	 = 0; // user Active
	//opens the file
	//ifstream infile(filepath.c_str(), ios::app);

	ifstream infile(filepath.c_str());
	
	if(!(infile.is_open()))
	{
		cout << "file did not open";	
	}

	while(getline(infile, line))
	{
		firstPosition  = line.find(':');
		secondPosition = line.find(':', firstPosition  + 1);
		thirdPosition  = line.find(':', secondPosition + 1);
		fourthPosition = line.find(':', thirdPosition  + 1);
		fifthPosition  = line.find(':', fourthPosition   + 1);

		// gets the username, password, and userid based on the positions
		if (firstPosition != string::npos && secondPosition != string::npos)
		{							// line.substr(totalLength + ':' , totalLength - length - ':' )
            userType 	 = line.substr(0, firstPosition);
            userName 	 = line.substr(firstPosition  + 1, secondPosition - firstPosition  - 1);
            userPassword = line.substr(secondPosition + 1, thirdPosition  - secondPosition - 1);
				userId       = line.substr(thirdPosition  + 1, fourthPosition - thirdPosition  - 1);
				strActive	 = line.substr(fourthPosition + 1, fifthPosition  - fourthPosition - 1);

            bool isActive = (strActive == "1"); // 1 returns true while other is false

            // if a third position exists check if the account is active/inactive
  //          if (thirdPosition != string::npos) 
//				{
  //              string status = line.substr(thirdPosition + 1);
 //               isActive = (status == "active");
//            }

				// depending if they are a cient or bank employee
				if(userType == "userAccount")
				{
//					cout << "The object " << userName << "is a userAccount" << endl;
//					cin.ignore(100000 , '\n');
	           	accountList.emplace_back(new userAccount(userName, userPassword, userId, nullptr, isActive));
				}
				else if(userType == "bankEmployee")
				{
					accountList.emplace_back(new bankEmployee(userName, userPassword, userId, nullptr, isActive));
				}
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


void deleteUserCredential(vector<userAccount*> &userList, const string &userIdToDelete)
{
    // File path for credentials
    string filepath = "./data/credentials.dat";
    ifstream file(filepath.c_str());
    ofstream temp("./data/temp.dat");

    // Error handling if the file cannot be opened
    if (!file.is_open())
    {
        cerr << "Error: Unable to open input file " << filepath << endl;
        return;
    }

    if (!temp.is_open())
    {
        cerr << "Error: Unable to open output file for writing" << endl;
        return;
    }

    bool userFound = false;  // Track if the user was found and deleted
    string line;

    // Loop through the credentials file
    while (getline(file, line))
    {
        // Split the line into parts
        size_t firstColon = line.find(':');
        size_t secondColon = line.find(':', firstColon + 1);

        // If there are less than 2 colons, skip this line
        if (firstColon == string::npos || secondColon == string::npos) {
            continue;  // skip malformed line
        }

        // Extract user ID
        string userID = line.substr(secondColon + 1);

        // Check if the user ID matches the one to delete
        if (userID == userIdToDelete)
        {
            userFound = true;  // Mark that the user was found
            cout << "User with ID " << userIdToDelete << " has been deleted." << endl;
            continue;  // Skip writing this line to temp file
        }

        // Write the line to the temp file if it's not the user to delete
        temp << line << endl;
    }

    // Close both files
    file.close();
    temp.close();

    // If the user was not found, notify
    if (!userFound) {
        cout << "User with ID " << userIdToDelete << " was not found." << endl;
    }

    // Remove the original credentials file
    remove(filepath.c_str());

    // Rename the temporary file to the original credentials file
    if (rename("./data/temp.dat", filepath.c_str()) != 0)
    {
        cerr << "Error: Unable to rename temp file" << endl;
    }

    // Wait for user input before continuing
    cout << "Press any key to continue...";
    cin.clear(); // Clear any error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover characters in the input buffer
    cin.get(); // Wait for user input
}

void createEmployeeObject(const string& accountType, const string& username, const string& password, const string& userId, userAccount* user){

}

void readEmployeeCredentialsFile(vector<userAccount*> &userList, int index)
{
	string name = "employee";
	string filepath = "./data/" + name + "_bankEmployeeCredentials.dat";	
	string line = " ";
	//position varibales
	size_t firstPosition = 0;
	size_t secondPosition = 0;
	size_t thirdPosition = 0;
	//temp variable


	ifstream infile(filepath.c_str());

	

	if(infile) //check if the file is open
	{
		while(getline(infile, line))
		{
			//position returns the position from the start of the line
			firstPosition = line.find(':');
			secondPosition = line.find(':', firstPosition + 1);
			thirdPosition = line.find(':', secondPosition + 1); 

			if(firstPosition != string::npos && secondPosition != string::npos && thirdPosition != string::npos)
			{
					string accountType = line.substr(0, firstPosition);
					string username = line.substr(firstPosition + 1, secondPosition - firstPosition - 1);
					string password = line.substr(secondPosition + 1, thirdPosition - secondPosition - 1);
					string userId = line.substr(thirdPosition + 1);

					createEmployeeObject(accountType, username, password, userId, nullptr);
			} else {
							cout << "Invalid line format: " << line << endl;
					}
		}
	} else {
					cout << "Error: Unable to open file: " << filepath << endl;
			}
	
	infile.close();
}
/*
void readEmployeeCredatialsFile(vector<userAccount*> &accountList)
{
	//sets the dirtory
//"./data/credentials.dat"
	string filepath = "./data/bankEmployeeCredentials.dat";
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
            accountList.emplace_back(new bankEmployee(userName, userPassword, userId, nullptr, isActive));
        }

	}

	infile.close();

}
*/


/**
 * Function isFileLocked
 */


//bool isFileLocked(const string& filename)
//{
//	int fd = open(filename.c_str(), O_RDWR); 
//	if(fd == -1)
//	{
//		cout << "Error file could not open" << endl;
//		return false;
//	}

	//try to lock the file for writing
	//Note that the person who locks the file uses LOCK_EX
	//and the person who is locked out uses LOCK_NB
//	if(flock(fd, LOCK_EX | LOCK_NB) == -1)
//	{
//		cout << "File is locked by ____:" << endl;
//		close(fd);
//		return true;
//	}

//	cout << "file is not locked" << endl;

	//unlock the file when done
//	flock(fd, LOCK_UN);
//	close(fd);
//	return false;
//}

void createLogDirectory(const string& userID) {
	string userLogDir = "./logs/" + userID;	// define the path for users log directory

	if (!filesystem::exists(userLogDir)) {		// checks if the directory exists
		filesystem::create_directories(userLogDir);
		cout << "Created directory for: " << userLogDir << endl;
	}
}

    //logActivity("Withdrawal of $" + to_string(amount) + " from account " + node->data->getAccountType() + " [" + node->data->getName() + "]");
// function to log activity
void logActivity(const string& userID, const string& activity) {
	createLogDirectory(userID);

	string filepath = "./logs/" + userID + "/" + userID + "_bankLog.dat";	// define the path to the log file using the user id

	ofstream logFile(filepath, ios::app);
	if (logFile.is_open()) {
		time_t now = time(nullptr); // this gets the current time
		logFile << ctime(&now) << " - " << activity << endl; // writes the current time and the activity to the file
		logFile.close();
	} else {
		cerr << "Could not open file for " << userID << endl;
	}
}
