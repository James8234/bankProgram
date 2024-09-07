#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <vector>

//global variables
const int SCREEN_SIZE = 120;

class bankAccountType; //forward declear

using namespace std;

//checking function
int checkVaildInteger(int max, int min);

//Account menu to add/delete/edit accounts
void account(vector<bankAccountType*> & accountsList);

//menu's
void printMainMenu();
void printAcctMenu();
void printAddAcctMenu();

//add delete and edit accounts
void addAccount(vector<bankAccountType*> &);
//void deleteAccount();
//void editAccount();


#endif
