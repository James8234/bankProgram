#ifndef FILEMANAGER_H
#define FILEMANAGER_H

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

void readAccountFile(vector<userAccount*> &userList, int index);

/**
 * FUNCTION createBankAccount
 *
 * The purpose of this functino is to add your bank account info to the text file data base.
 */

void createBankAccount(userAccount *initialUser, string strObject, string username, string userId, int bal);

/**
 * Function bankAccountType *createAccounts
 * The purpose of this function is to create the bank account reading it in from the file data base. then It creats an node with its at a member.
 */

bankAccountType *createAccountObject(string strObject, string username, string strBalance, string userId);

/**
 * Function updateBankAccount
 * The purpose of this function is to update the text file data base using the linkedList in memory to create an
 * copy and replace the text file with updated information. There should be some type of lock to this system so
 * one person can update at a time.
 */

void updateBankAccountFile(userAccount *&initialUser);


//void createAccountFile();

//this function reads the data from namedat into the linkedList which is a member of userAccount
//void readNamedatFile();
string convertDoubleToString(double bankBalance);

void updateAccountFile(const vector<userAccount*>& accountList);


#endif


