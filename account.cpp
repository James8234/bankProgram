#include "account.h"
#include "header.h"

account::account(const string& usr, const string& pswd, int id)
{


}

//bool account::validLogin(const string &usr, const string &pswd, int id)
//{
 //   return (usr == username && pswd == password);
//}


void account::displayLoginMenu(vector<account> &users)
{
    int choice;

    do {
        std::cout << "Welcome! Choose an option:\n";
        std::cout << "1. Create an account\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
      //          createAccount(users);
                break;
            case 2:
   //             if (validLogin(" ", " ", 24)) {
     //               std::cout << "Login successful!\n";
       //         } else {
         //           std::cout << "Invalid credentials. Try again.\n";
           //     }
                break;
            case 3:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);
}
