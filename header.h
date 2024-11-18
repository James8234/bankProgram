#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

//global variables
const int SCREEN_SIZE = 120;

class bankAccountType; //forward declear
class doublyLinkedListType;
class nodeType;
class userAccount;

using namespace std;



//checking function
int checkVaildInteger(int max, int min);

//Account menu to add/delete/edit accounts
void account(doublyLinkedListType &accountsList);

//main menu
void accountList();

void userAccountMenu(userAccount *initialUser, vector<userAccount*> &userList);

//menu's
//void printMainMenu();
void printAcctMenu();

void printAccountMenu();

void printAddAcctMenu();
void printAccountList(userAccount *initialUser);
void printAccountInfo(nodeType *node);
void printLine();
void accountUI(userAccount *&initialUser, nodeType *&node);
//add delete and edit accounts
void addAccount(userAccount *&initialUser);
//void deleteAccount();
//void editAccount();

void printLogo();

//utils function
string generateRandomAccountNumber();

#endif
