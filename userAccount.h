#ifndef USERACCOUNT_H_
#define USERACCOUNT_H_

#include<string>
#include<iostream>
#include<vector>
#include "doublyLinkedListType.h"

using namespace std;

class userAccount
{


	protected:
		string username;
	   string password;
	   string id;

		doublyLinkedListType *linkList;
		bool isActive; // deactivateAccount function

	public:

		userAccount();


		//constructors
		//	User();
   	 userAccount(const string& usr = " ", const string& pswd = " ", string userId = " ", doublyLinkedListType *newLinkList = nullptr, bool active = true);
	
		//setters
		void setUsername(string tempUsername);
		void setPassword(string tempPassword);

		//geters
		virtual string getClassName(); //The purpose of this function is to update the text file and prints its userType
		string getUsername();
		// bool  getIsActive();
		string getPassword();
		string getID() const;
		doublyLinkedListType* getLinkList();
		void setLinkedListType(doublyLinkedListType* newList);

		string getUserId(); // getter for userid

		bool getIsActive() const { return isActive; } // getter for isActive
		void setIsActive(bool active) { isActive = active; } // setter for isActive

		//print functions
		void print();
		void printLoginAccount(string usr, string pass);
		void printMainMenu();
		void printEditUserAccount(string tempName, string tempPassword);


		void deactivateAccountMenu(vector<userAccount*>& users);
	
		int loginAccount(vector<userAccount*> &users);
	
	   int displayLoginMenu(vector<userAccount*>& users, vector <userAccount*>& employees);
	
	   int createAccount(vector<userAccount*>& users);
	
		int findAccountIndex(vector<userAccount*> users, string username, string password);

	   bool validLogin(const string& usr, const string& pswd, string id);

	   void bankEmployeeMenu(vector<userAccount*>& users);

	   void viewAllUserAccounts(const vector<userAccount*>& users) const;

	   int getUserChoice(int min, int max) const;
				
				int employeeLoginAccount(vector<userAccount*>& users);

		
		/**
		 *	FUNCTION editUserAccount
		 *
  		 * The purpose of this function is to allow the user to edit their userAccount info
		 */

		void editUserAccount(userAccount *initialUser, vector<userAccount*> &userList);

/**
 * FUNCTION void deleteAllAccounts
 * clean functino
 */
void deleteAllAccounts(vector<userAccount*> &userList);


		//deconstructor
	virtual ~userAccount() {}
	
	private:
		string userId;

};


#endif
