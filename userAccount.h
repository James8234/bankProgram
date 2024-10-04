#ifndef USEREACCOUNT_H_
#define USERACCOUNT_H_

#include<string>
#include<iostream>
#include<vector>
#include "doublyLinkedListType.h"

using namespace std;

class userAccount
{
	public:
		string username;
	   string password;
	   string id;
		string userType;

		doublyLinkedListType *linkList;


		//constructors
		//	User();
   	 userAccount(const string& usr = " ", const string& pswd = " ", string userId = " ", doublyLinkedListType *newLinkList = nullptr);
	
		//geters
		string getUsername();
		string getPassword();
		doublyLinkedListType* getLinkList();
		void setLinkedListType(doublyLinkedListType* newList);

		//print functions
		void print();
		void printLoginAccount(string usr, string pass);
		void printMainMenu();
	
		int loginAccount(vector<userAccount*> &users);
	
	   int displayLoginMenu(vector<userAccount*>& users);
	
	   int createAccount(vector<userAccount*>& users);
	
		int findAccountIndex(vector<userAccount*> users, string username, string password);

	   bool validLogin(const string& usr, const string& pswd, string id);

/**
 * FUNCTION void deleteAllAccounts
 * clean functino
 */
void deleteAllAccounts(vector<userAccount*> &userList);


		//deconstructor
		~userAccount() {}
	private:


};


#endif
