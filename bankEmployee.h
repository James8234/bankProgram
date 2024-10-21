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

    void viewAllaccounts(const vector<userAccount*>& users);                                                                                                                                                 
    int loginAccount(vector<userAccount*>& users);                                                                                                                                                           
    void bankEmployeeMenu();                                                                                                                                                                                 
                                                                                                                                                                                                              
    ~bankEmployee() {}                                                                                                                                                                                       
 protected:                                                                                                                                                                                                   
    bool isActive;                                                                                                                                                                                            
};                                                                                                                                                                                                           
                                                                                                                                                                                                              
#endif                                                                                                                                                                                                       
                                                                   
                                                                                                                                                                                
