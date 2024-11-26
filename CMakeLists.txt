cmake_minimum_required(VERSION 3.28)

project(run)

#Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

#Add common compiler flags for all targets
#add_compile_options(-Wall -Werror -Wpedantic)

#add the executables
add_executable(${PROJECT_NAME} main.cpp nodeType.cpp noServiceChargeCheckingType.cpp printAccountInfo.cpp printAccountList.cpp printAccountMenu.cpp printLine.cpp savingsAccountType.cpp serviceChargeCheckingType.cpp tools.cpp transactionHistory.cpp UI.cpp userAccount.cpp userAccountMenu.cpp accountUI.cpp addAccount.cpp bankAccountType.cpp bankEmployee.cpp certificationOfDepositType.cpp checkingAccountType.cpp checkVaildInteger.cpp deactivateAccount.cpp displayAccountDetails.cpp doublyLinkedListType.cpp fileManager.cpp highInterestCheckingType.cpp highInterestSavingsType.cpp)

#link the header files to the executable files
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})

#link ncurses
find_package(Curses REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES})

