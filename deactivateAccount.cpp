#include "deactivateAccount.h"
#include "userAccount.h"
#include "header.h"
#include <iostream>
#include <fstream>

using namespace std;

void deactivateAccount::deactivateUserAccount(userAccount& account)
 {
 		if (account.getIsActive()) 
		{
		account.setIsActive(false);
		cout << "The account has been deactivated." << endl;

		string filepath = "./data/credentials.dat";
		ifstream infile(filepath.c_str());		// writes changes back to the file
		ofstream tempFile("./data/temp.dat");

		string line;
        while (getline(infile, line)) {
          	size_t firstPos = line.find(':');
            size_t secondPos = line.find(':', firstPos + 1);
            size_t thirdPos = line.find(':', secondPos + 1);

            string username = line.substr(0, firstPos);
            string password = line.substr(firstPos + 1, secondPos - firstPos - 1);
            string userId = line.substr(secondPos + 1, thirdPos - secondPos - 1);
            string activeStatus = (account.getIsActive() ? "active" : "inactive");

			if (username == account.getUsername()) {
                // write updated status for this account
                tempFile << username << ":" << password << ":" << userId << ":" << activeStatus << endl;
            } else {
                // write the line as is for other accounts
                tempFile << line << endl;
            }

		}

		infile.close();
		tempFile.close();

		remove(filepath.c_str()); // replaces the original file with temp file
		rename("./data/temp.dat", filepath.c_str());

		} else {
			cout << "The account has already been deactivated." << endl;

	}
}
