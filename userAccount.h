#ifndef USERACCOUNT_H_
#define USERACCOUNT_H_

#include<string>
#include<iostream>
#include<vector>
#include "doublyLinkedListType.h"
#include "nodeType.h"
#include <limits>

using namespace std;

class userAccount
{
	protected:
		string username;
	   string password;
	   string id;
		doublyLinkedListType *linkList;
		bool isActive; // deactivateAccount function
    	vector<nodeType*> accounts;
		string userId;

	public:

		userAccount();

		//This function allows the user to trasfer balance between bank accounts.
		friend void transferBetweenBankAccounts(userAccount *initialUser);

		//dead lock functions -- this function locks on both user accounts
		virtual bool lockBankAccounts(const userAccount *initialUser);
		virtual void unlockBankAccounts(const userAccount *initialUser);

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

		vector<nodeType*>& getAccounts();

	    void addAccount(nodeType* account);

		void depositToAccount(int accountIndex, double amount);

		void depositToUserAccount(vector<userAccount*>& users, int userIndex);

		void withdraw(std::vector<userAccount*>& users, int userIndex);

		    double balance; // Assuming this is public, or create a getter

   	 	// Getter method if balance is private
   		 double getBalance() const {
        	return balance;
    	}

    // Method for withdrawal
    	void withdraw(double amount) {
        	if (amount <= balance) {
            balance -= amount;
        	}
    	}

		void transferFunds(std::vector<userAccount*>& users);

		void printAccountList();
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

};


#endif
