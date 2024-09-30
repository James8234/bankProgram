#ifndef MANAGERACCOUNT_H
#define MANAGERACCOUNT_H



#include <iostream>
#include <fstream> // for file handling
#include <sys/stat.h> // for mkdir
#include <sys/types.h> // for mode_t
#include <cstring> // for strerror
#include "header.h"
//#include "userAccount.h"
using namespace std;

//forward declear
//#include "userAccount.h"
class userAccount;

//void create the subdirectory if it doesn't exist
void createSubdirectory();

/**
 * FUNCTION void readCredateialsFile
 * 
 * this function reads the data from the credatials file into a vector
 * note to check if the account exist should alread exist under userAccount.h once credatials is read into memory
 * example of text file
 * colin,password,23469
 */
void readCredatialsFile(vector<userAccount*> &userList);

/**
 * FUNCTION void createAccountFile 
 *
 * This function will be called when the user choices to create an account
 * the function will ask the user to enter a username and userpassword. Next the function will
 * add the information to the data base and into memory. This function must all readCredatialsFile to
 * update the memory and check if the account being created already exist. The function will output an updated vector
 * and database
 */
void createAccountFile(vector<userAccount*> &userList, string username, string userPassword, string userId);

/**
 * FUNCTION void readAccountFile
 *
 * This function will read in the data from the readAccountFile to a linkList
 * The purpose of this function is to load in the users data once they have login and if they created an account load it anyways.
 * This function will read the data formated like this below
 * savingsAccount
 * name
 * balance
 * id
 */

void readAccountFile(vector<userAccount*> &userList);

//void createAccountFile();

//this function reads the data from namedat into the linkedList which is a member of userAccount
//void readNamedatFile();

#endif


