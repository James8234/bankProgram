#include "bankEmployee.h"
#include "userAccount.h"
#include "doublyLinkedListType.h"
#include "fileManager.h"
#include "tools.h"
#include "header.h"

string bankEmployee::getClassName() 
{
	return "bankEmployee";
}


void userAccount::bankEmployeeMenus()
{
	cout << "\033[1;32m";
	cout << "Banke Employee menu:\n";
	cout << "1. View all user accounts\n";
	cout << "2. Deactivate a user accounts\n";
	cout << "3. Reactivate a user account\n";
	cout << "4. Create an user account\n";
	cout << "0. Logout\n";
	printLine();
	cout << "\033[5;1;32m";
	cout << "Enter your choice: -->: ";
	cout << "\033[0m";
}


void userAccount::bankEmployeeMenu(vector<userAccount*>& users)
{
    bool exitMenu = false;
    int choice = 0;
    int index = -1;
	int elements = users.size();

	while (!exitMenu)
	{
    	cout << "\033c";
    	cout << "\033[1;32m"; // Green color
    	cout << "Bank Employee Menu: hello\n";
    	printLine();
    	cout << "1. View All User Accounts\n";
      cout << "2. Deposit to User Account\n";
        cout << "3. Withdraw from User Account\n";
        cout << "4. Transfer from User Accounts\n";
        cout << "5. Deactivate/Reactivate a User Account\n";
        cout << "6. Create a User Account\n";
        cout << "0. Logout\n";
        printLine();
        cout << "\033[5;1;32m"; // Blink and green color
        cout << "Enter your choice: -->: ";
        cout << "\033[0m"; // Reset color

        choice = checkVaildInteger(6, 0); // Updated max to 6 to include all options

       switch (choice)
		 {
            case 0:
                exitMenu = true;
                break;
            case 1:
                cout << "\033c";
                viewAllUserAccounts(users);
                break;
       	   case 2:// Deposit from User Account
            	cout << "\033c";

				viewAllUserAccounts(users);
				cout << "please select an account -->: ";
				index = checkVaildInteger(elements, 0);



//            	index = loginAccount(users);

            	if (index >= 0 && index < users.size()) 
					{
             	   depositToUserAccount(users, index); // Call the deposit function
           	 	}
				  	else
					{
                cout << "Invalid user index." << endl;
           		}
               break;
            case 3:  // Withdraw from User Account
              cout << "\033c";
              index = loginAccount(users); // Get the index of the user
              if (index != -1) 
				  { // Check if login was successful
              		withdraw(users, index); // Call the withdraw method
              }
				  else 
				  {
						cout << "Login failed. Please try again.\n";
              }
              break;
            case 4: // Transfer from User Accounts
                cout << "\033c";
                // Transfer logic here
                break;
            case 5:
                cout << "\033c";
                deactivateAccountMenu(users);
                break;
            case 6:
                cout << "\033c";
					 createAccount(users);
                // Logic for creating a new user account
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }

        // This will ensure you can see the result before continuing
        cout << "Press Enter to continue...";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear lingering input
        cin.get();  // Wait for Enter
    }
}


int userAccount::getUserChoice(int min, int max) const
 {
    int choice;
    while (true)
	 {
        cin >> choice;
        if (cin.fail() || choice < min || choice > max) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        } else {
            cin.ignore(10000, '\n');
            break;
        }
    }
    return choice;
}

void userAccount::viewAllUserAccounts(const vector<userAccount*>& users) const 
{
    cout << "\033[1;34m"; // Blue color
	int row = 0;
    cout << "List of User Accounts:\n";
    printLine();
    cout << "ID\tUsername\tStatus\n";
    printLine();
    for (const auto& user : users) 
	{
		cout << "<" << row << "> "
        	  << user->getID() << "\t"
           << user->getUsername() << "\t\t"
           << (user->getIsActive() ? "ACTIVE" : "INACTIVE") << "\n";
		row++;
    }
    cout << "\033[0m"; // Reset color
}


vector<nodeType*>& userAccount::getAccounts() { return accounts; }

void userAccount::addAccount(nodeType* account)
{
        accounts.push_back(account);
}

void userAccount::depositToAccount(int accountIndex, double amount)
{
        if (accountIndex >= 0 && accountIndex < accounts.size()) 
		  {
            accounts[accountIndex]->deposit(amount);
        } else {
            cout << "Invalid account selection." << endl;
        }
}

void userAccount::depositToUserAccount(vector<userAccount*>& users, int userIndex)
{
	int index = 0;
	int totalNodes = doublyLinkedListType::getNodeCount();
	nodeType *bankAccount = nullptr;
	double amount = 0;
    if (userIndex < 0 || userIndex >= users.size())
	{
        cout << "Invalid user index." << endl;
        return;
    }

    userAccount* initialUser = users[userIndex];
	cout << "The account you have selected is " << initialUser->getUsername() << endl;


    vector<nodeType*>& userAccounts = initialUser->getAccounts();


	//this function loads the user bank info in
	readBankAccountFile(users, userIndex);

	



    if (totalNodes < 0)
	 {
        cout << "No accounts available for this user." << endl;
        return;
    }

	printAccountList(initialUser);
	index = checkVaildInteger(totalNodes, 0);


//	findAccountByIndex(index);
	bankAccount = initialUser->getLinkList()->getAccountByIndex(index);

	cout << "Enter the ammount to deposit -->";
	amount = checkVaildInteger(bankAccount->data->getBalance(), 0);

	bankAccount->data->deposit(amount);
	cout << "your new balance is " << bankAccount->data->getBalance() << endl;
	cin.ignore(10000 , '\n');

	updateBankAccountFile(initialUser);

/*

    // Display available accounts
    cout << "Select an account to deposit into:\n";
    for (size_t i = 0; i < userAccounts.size(); ++i)
	 {
        cout << i << ". " << userAccounts[i]->accountType << " (Balance: $" << userAccounts[i]->balance << ")\n";
    }

    int accountChoice = -1;
    cout << "Enter the account number to deposit into: ";
    cin >> accountChoice;

    if (cin.fail() || accountChoice < 0 || accountChoice >= userAccounts.size()) 
	{
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
        cout << "Invalid selection. Please try again." << endl;
        return;
    }
    // Get deposit amount
    double depositAmount;
    cout << "Enter the amount to deposit: $";
    cin >> depositAmount;

    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Deposit to the selected account
    user->depositToAccount(accountChoice, depositAmount);
*/
}

void userAccount::withdraw(std::vector<userAccount*>& users, int userIndex)
 {
    if (userIndex < 0 || userIndex >= users.size()) {
        std::cout << "Invalid user index.\n";
        return;
    }

    userAccount* currentUser = users[userIndex]; // Get the user account
    nodeType* accountNode = nullptr;
    double withdrawalAmount = 0.0;
    size_t totalAccounts = currentUser->getLinkList()->getNodeCount(); // Get the count of accounts

    if (totalAccounts == 0) {
        std::cout << "No accounts available for withdrawal.\n";
        return;
    }

    // Display the user's accounts
    printAccountList(currentUser); // Print the list of accounts

    // Get the account index to withdraw from
    int accountIndex = checkVaildInteger(totalAccounts, 0); // Your function to validate integer input
    accountNode = currentUser->getLinkList()->getAccountByIndex(accountIndex);

    if (accountNode == nullptr) {
        std::cout << "Selected account not found.\n";
        return;
    }

    // Ask for withdrawal amount
    std::cout << "Enter amount to withdraw: ";
    std::cin >> withdrawalAmount;

    // Validate withdrawal amount
    if (withdrawalAmount <= 0 || withdrawalAmount > accountNode->balance) { // Use balance directly
        std::cout << "Invalid withdrawal amount.\n";
        return;
    }

    // Perform withdrawal
    accountNode->withdraw(withdrawalAmount); // Directly call withdraw method
    std::cout << "Withdrawal successful! New balance: " << accountNode->balance << "\n"; // Use balance directly

    // Log the withdrawal activity if needed
    std::string activity = "Withdrawn: " + std::to_string(withdrawalAmount);
    logActivity(currentUser->getUserId(), activity); // Assuming a method to log activities

}

/*
void userAccount::printAccountList() {
    nodeType* current = linkList->getHead(); // Assuming you have access to the head of the linked list
    int index = 0;

    std::cout << "Available Accounts:\n";
    while (current != nullptr) {
        std::cout << "[" << index++ << "] " << current->accountType << " - Balance: " << current->balance << std::endl; // Adjust based on your node structure
        current = current->next; // Move to the next node
    }
}
*/
void userAccount::transferFunds(std::vector<userAccount*>& users) {
    int sourceIndex = -1;
    int destinationIndex = -1;
    double transferAmount = 0.0;

    // Step 1: Get Source User and Account
    std::cout << "\033c";
    std::cout << "Select source user for transfer:\n";
    sourceIndex = loginAccount(users);

    if (sourceIndex < 0 || sourceIndex >= users.size()) {
        std::cout << "Invalid source user. Exiting transfer.\n";
        return;
    }

    userAccount* sourceUser = users[sourceIndex];
    size_t totalAccountsSource = sourceUser->getLinkList()->getNodeCount();

    if (totalAccountsSource == 0) {
        std::cout << "No accounts available for the source user. Exiting transfer.\n";
        return;
    }

    // Display source user's accounts
    printAccountList(sourceUser);
    int sourceAccountIndex = checkVaildInteger(totalAccountsSource - 1, 0);
    nodeType* sourceAccount = sourceUser->getLinkList()->getAccountByIndex(sourceAccountIndex);

    if (!sourceAccount) {
        std::cout << "Source account not found. Exiting transfer.\n";
        return;
    }

    // Step 2: Get Destination User and Account
    std::cout << "\033c";
    std::cout << "Select destination user for transfer:\n";
    destinationIndex = loginAccount(users);

    if (destinationIndex < 0 || destinationIndex >= users.size()) {
        std::cout << "Invalid destination user. Exiting transfer.\n";
        return;
    }

    userAccount* destinationUser = users[destinationIndex];
    size_t totalAccountsDestination = destinationUser->getLinkList()->getNodeCount();

    if (totalAccountsDestination == 0) {
        std::cout << "No accounts available for the destination user. Exiting transfer.\n";
        return;
    }

    // Display destination user's accounts
    printAccountList(destinationUser);
    int destinationAccountIndex = checkVaildInteger(totalAccountsDestination - 1, 0);
    nodeType* destinationAccount = destinationUser->getLinkList()->getAccountByIndex(destinationAccountIndex);

    if (!destinationAccount) {
        std::cout << "Destination account not found. Exiting transfer.\n";
        return;
    }

    // Step 3: Prompt for Transfer Amount
    std::cout << "Enter the amount to transfer: ";
    std::cin >> transferAmount;

    if (transferAmount <= 0 || transferAmount > sourceAccount->balance) {
        std::cout << "Invalid amount. Exiting transfer.\n";
        return;
    }

    // Step 4: Execute Transfer
    sourceAccount->balance -= transferAmount;
    destinationAccount->balance += transferAmount;

    // Display Transfer Success
    std::cout << "Transfer successful!\n";
    std::cout << "New balance of source account: " << sourceAccount->balance << "\n";
    std::cout << "New balance of destination account: " << destinationAccount->balance << "\n";
}
