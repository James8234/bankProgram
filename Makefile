#Compiler and flags
CFLAGS = -Wall -Werror -Wpedantic -std=c++20
CC = g++ 

# Object files
OBJECTS = bankAccountType.o certificationOfDepositType.o checkingAccountType.o highInterestSavingsType.o main.o savingsAccountType.o serviceChargeCheckingType.o highInterestCheckingType.o noServiceChargeCheckingType.o checkVaildInteger.o printMainMenu.o doublyLinkedListType.o addAccount.o nodeType.o printAccountList.o printAccountInfo.o accountUI.o printLine.o userAccount.o fileManager.o deactivateAccount.o bankEmployee.o printAccountMenu.o userAccountMenu.o

default: run

run: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp header.h bankAccountType.h certificationOfDepositType.h checkingAccountType.h highInterestSavingsType.h savingsAccountType.h serviceChargeCheckingType.h highInterestCheckingType.h noServiceChargeCheckingType.h nodeType.h doublyLinkedListType.h userAccount.h fileManager.h deactivateAccount.h bankEmployee.o

bankAccountType.o: bankAccountType.cpp bankAccountType.h

certificationOfDepositType.o: certificationOfDepositType.cpp header.h certificationOfDepositType.h

checkingAccountType.o: checkingAccountType.cpp checkingAccountType.h

highInterestSavingsType.o: highInterestSavingsType.cpp header.h highInterestSavingsType.h

savingsAccountType.o: savingsAccountType.cpp header.h savingsAccountType.h

serviceChargeCheckingType.o: serviceChargeCheckingType.cpp header.h serviceChargeCheckingType.h

highInterestCheckingType.o:  highInterestCheckingType.cpp header.h highInterestCheckingType.h

noServiceChargeCheckingType.o: noServiceChargeCheckingType.cpp header.h noServiceChargeCheckingType.h

checkVaildInteger.o: checkVaildInteger.cpp header.h

printMainMenu.o: printMainMenu.cpp header.h

doublyLinkedListType.o: doublyLinkedListType.cpp doublyLinkedListType.h nodeType.h bankAccountType.h userAccount.h fileManager.h

addAccount.o: addAccount.cpp header.h savingsAccountType.h highInterestSavingsType.h noServiceChargeCheckingType.h highInterestCheckingType.h certificationOfDepositType.h doublyLinkedListType.h fileManager.h userAccount.h

nodeType.o: nodeType.cpp nodeType.h

printAccountList.o: printAccountList.cpp header.h nodeType.h doublyLinkedListType.h userAccount.h

printAccountInfo.o: printAccountInfo.cpp header.h nodeType.h doublyLinkedListType.h

accountUI.o: accountUI.cpp header.h nodeType.h doublyLinkedListType.h userAccount.h fileManager.h

printLine.o: printLine.cpp header.h

userAccount.o: userAccount.cpp userAccount.h header.h fileManager.h deactivateAccount.h deactivateAccount.cpp

fileManager.o: fileManager.cpp fileManager.h header.h doublyLinkedListType.h userAccount.h bankAccountType.h certificationOfDepositType.h checkingAccountType.h highInterestSavingsType.h savingsAccountType.h serviceChargeCheckingType.h highInterestCheckingType.h noServiceChargeCheckingType.h nodeType.h doublyLinkedListType.h userAccount.h fileManager.h

deactivateAccount.o: deactivateAccount.cpp deactivateAccount.h userAccount.h header.h

bankEmployee.o: bankEmployee.cpp bankEmployee.h

printAccountMenu.o: printAccountMenu.cpp header.h

userAccountMenu.o: userAccountMenu.cpp header.h doublyLinkedListType.h userAccount.h


# Clean up
clean:
	rm -f $(OBJECTS) $(TARGET)
