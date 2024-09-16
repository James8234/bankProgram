#Compiler and flags
CFLAGS = -Wall -Werror -Wpedantic -std=c++20
CC = g++ 

# Object files
OBJECTS = bankAccountType.o certificationOfDepositType.o checkingAccountType.o highInterestSavingsType.o main.o savingsAccountType.o serviceChargeCheckingType.o highInterestCheckingType.o noServiceChargeCheckingType.o checkVaildInteger.o printMainMenu.o doublyLinkedListType.o addAccount.o nodeType.o printAccountList.o printAccountInfo.o accountUI.o printLine.o

default: run

run: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp header.h bankAccountType.h certificationOfDepositType.h checkingAccountType.h highInterestSavingsType.h savingsAccountType.h serviceChargeCheckingType.h highInterestCheckingType.h noServiceChargeCheckingType.h nodeType.h doublyLinkedListType.h


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

doublyLinkedListType.o: doublyLinkedListType.cpp doublyLinkedListType.h nodeType.h bankAccountType.h 

addAccount.o: addAccount.cpp header.h savingsAccountType.h highInterestSavingsType.h noServiceChargeCheckingType.h highInterestCheckingType.h certificationOfDepositType.h doublyLinkedListType.h

nodeType.o: nodeType.cpp nodeType.h

printAccountList.o: printAccountList.cpp header.h nodeType.h doublyLinkedListType.h

printAccountInfo.o: printAccountInfo.cpp header.h nodeType.h doublyLinkedListType.h

accountUI.o: accountUI.cpp header.h nodeType.h doublyLinkedListType.h

printLine.o: printLine.cpp header.h

# Clean up
clean:
	rm -f $(OBJECTS) $(TARGET)
