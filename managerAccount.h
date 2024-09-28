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
class userAccount;

//void create the subdirectory if it doesn't exist
void createSubdirectory();

/**
 * readCredateialsFile
 * 
 * example of text file
 * colin,password,23469
 */

//this function reads the data from the credatials file into a vector
//note to check if the account exist should alread exist under userAccount.h once credatials is read into memory
void readCredatialsFile(vector<userAccount> &userList);

/**
 * createAccountFile 
 * This function will be called when the user choices to create an account
 */

//void createAccountFile();

//this function reads the data from namedat into the linkedList which is a member of userAccount
//void readNamedatFile();

#endif


