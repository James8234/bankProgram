# Compiler and flags
CFLAFS = -Wall -Werror -wpedantic -std=c++20
CC = g++ -MMD -MP

# Object files
OBJECTS = bankAccountType.o certificationOfDepositType.o checkingAccountType.o highInterestSavingsType.o main.o savingAccountType.o serviceChargeCheckingType.o highInterestCheckingType.o noServiceChargeCheckingType.o

default: run

run: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp header.h serviceChargeCheckingType.h  highInterestCheckingType.h bankAccountType.h savingAccountType.h certificationOfDepositType.h checkingAccountType.h highInterestSavingsType.h

bankAccountType.o: bankAccountType.cpp bankAccountType.h

certificatinOfDepositType.o: certificationOfDepositType.cpp certificationOfDepositType.h

checkingAccountType.o: checkingAccountType.cpp checkingAccountType.h

highInterestSavingsType.o: highInterestSavingsType.cpp highInterestSavingsType.h

savingAccountType.o: savingAccountType.cpp savingAccountType.h

serviceChargeCheckingType.o: serviceChargeCheckingType.cpp serviceChargeCheckingType.h

highInterestCheckingType.o:  highInterestCheckingType.cpp  highInterestCheckingType.h

noServiceChargeCheckingType.o: noServiceChargeCheckingType.cpp noServiceChargeCheckingType.h




# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
