#Compiler and flags
CFLAGS = -Wall -Werror -Wpedantic -std=c++20
CC = g++ 

# Object files
OBJECTS = bankAccountType.o testFunction.o certificationOfDepositType.o checkingAccountType.o highInterestSavingsType.o main.o savingsAccountType.o serviceChargeCheckingType.o highInterestCheckingType.o noServiceChargeCheckingType.o 

default: run

run: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp header.h testFunction.h serviceChargeCheckingType.h  highInterestCheckingType.h bankAccountType.h savingsAccountType.h certificationOfDepositType.h checkingAccountType.h highInterestSavingsType.h 

bankAccountType.o: bankAccountType.cpp header.h bankAccountType.h

certificationOfDepositType.o: certificationOfDepositType.cpp certificationOfDepositType.h

checkingAccountType.o: checkingAccountType.cpp checkingAccountType.h

highInterestSavingsType.o: highInterestSavingsType.cpp header.h highInterestSavingsType.h

savingsAccountType.o: savingsAccountType.cpp header.h savingsAccountType.h

serviceChargeCheckingType.o: serviceChargeCheckingType.cpp serviceChargeCheckingType.h

highInterestCheckingType.o:  highInterestCheckingType.cpp  highInterestCheckingType.h

noServiceChargeCheckingType.o: noServiceChargeCheckingType.cpp noServiceChargeCheckingType.h

testFunction.o: testFunction.cpp testFunction.h header.h

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
