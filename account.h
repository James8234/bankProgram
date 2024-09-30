#ifndef ACCOUNT_H
#define ACCOUNT_H

//#include "header.h"
#include<string>
#include<iostream>
#include<vector>

using namespace std;

class account
{
public:
    string username;
    string password;
    int id;

    account(const string& usr, const string& pswd, int id);

    void displayLoginMenu(vector<account>& users);

//    void createAccount(vector<account>& users);

//    bool validLogin(const string& usr, const string& pswd, int id);
};


#endif
