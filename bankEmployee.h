#ifndef BANKEMPLOYEE_H
#define BANKEMPLOYEE_H

#include "userAccount.h"
#include <iostream>
using namespace std;

class bankEmployee : public userAccount
{
	public:

		bankEmployee(const string& usr = " ", const string& pswd = " ", string userId = " ", doublyLinkedListType *newLinkList = nullptr, bool isActive = true) : userAccount(usr, pswd, userId, newLinkList, isActive){}
		virtual string getClassName() override;

//		void viewAllaccounts(const vector<userAccount*>& users);
//		int loginAccount(vector<userAccount*>& users);
//		void bankEmployeeMenus();

		~bankEmployee() {}



		/*
		 * FUNCTION bankEmployeeMenus
		 */
//		void bankEmployeeMenus();

		/*
		 * FUNCTION bankEmployeeMenu
		 */
//		void bankEmployeeMenu(vector<userAccount*>& users);

		/*
		 * FUNCTION getUserChoice
		 */
//		int getUserChoice(int min, int max) const;
//
		/*
		 * FUNCTION viewAllUserAccounts
		 */
//		void viewAllUserAccounts(const vector<userAccount*>& users) const;

		/*
		 * FUNCTION getAccounts
		 */
//		vector<nodeType*>& getAccounts();

		/*
		 * FUNCTION depositToUserAccount
		 */
//		void depositToUserAccount(vector<userAccount*>& users, int userIndex);

		/*
		 * FUNCTION withdraw
		 */
//		void withdraw(std::vector<userAccount*>& users, int userIndex);

		/*
		 * FUNCTION transferFunds
		 */
//		void transferFunds(std::vector<userAccount*>& users);

		/*
		 * FUNCTION bankEmployeeMenu
		 */
//		void depositToAccount(int accountIndex, double amount);
//		void bankEmployeeMenu(vector<userAccount*>& users);

//		void printAccountList();

	protected:
		bool isActive;
};

#endif
