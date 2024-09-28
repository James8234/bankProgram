#include "managerAccount.h"
#include "header.h"
#include "doublyLinkedListType.h"
#include "userAccount.h"


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

void readCredatialsFile(vector<userAccount> &accountList)
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
   		accountList.emplace_back(userAccount(userName,userPassword,userId,new doublyLinkedListType));
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
