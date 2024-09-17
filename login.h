#ifndef LOGIN_H
#define LOGIN_H

#include<string>
#include<iostream>
#include<vector>

using namespace std;

class User
{
public:
    string username;
    string password;
    int id;

    User(const string& usr, const string& pswd, int id);

    void displayLoginMenu(vector<User>& users);

    void createAccount(vector<User>& users);

    bool validLogin(const string& usr, const string& pswd, int id);
};


#endif
