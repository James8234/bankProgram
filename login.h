#ifndef LOGIN_H
#define LOGIN_H

#include<string>
#include<iostream>
#include<vector>

#include "doublyLinkedListType.h"

using namespace std;

class User
{
public:
    string username;
    string password;
    int id;

	doublyLinkedListType *linkList;


	//constructors
//	User();
    User(const string& usr = " ", const string& pswd = " ", int id = 0, doublyLinkedListType *newLinkList = nullptr);

	//geters
	string getUsername();
	string getPassword();
	doublyLinkedListType* getLinkList();

	//print functions
	void print();
	void printLoginAccount(string usr, string pass);

	int loginAccount(vector<User> &users);

    int displayLoginMenu(vector<User>& users);

    void createAccount(vector<User>& users);

	int findAccountIndex(vector<User> users, string username, string password);

    bool validLogin(const string& usr, const string& pswd, int id);

	~User() {}
private:


};


#endif
