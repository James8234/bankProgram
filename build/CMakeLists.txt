cmake_minimum_required(VERSION 3.28)

project(run)

#Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

#Add common compiler flags for all targets
#add_compile_options(-Wall -Werror -Wpedantic)

#Add include directories
#target_include_directories(${PROJECT_NAME} PUBLIC
#	${CMAKE_SOURCE_DIR}/bankAccounts
#)


#add the executables
add_executable(${PROJECT_NAME}
 ../src/main.cpp
 ../dataStructures/nodeType.cpp
 ../bankAccounts/noServiceChargeCheckingType.cpp
 ../UI/printAccountInfo.cpp
 ../UI/printAccountList.cpp
 ../UI/printAccountMenu.cpp
 ../UI/printLine.cpp
 ../bankAccounts/savingsAccountType.cpp
 ../bankAccounts/serviceChargeCheckingType.cpp
 ../ultils/tools.cpp
 ../logs/transactionHistory.cpp
 ../UI/UI.cpp
 ../user/userAccount.cpp
 ../user/userAccountMenu.cpp
 ../user/accountUI.cpp
 ../user/addAccount.cpp
 ../bankAccounts/bankAccountType.cpp
 ../bankEmployee/bankEmployee.cpp
 ../bankAccounts/certificationOfDepositType.cpp
 ../bankAccounts/checkingAccountType.cpp
 ../ultils/checkVaildInteger.cpp
 ../bankEmployee/deactivateAccount.cpp
 ../UI/displayAccountDetails.cpp
 ../dataStructures/doublyLinkedListType.cpp 
 ../ultils/fileManager.cpp
 ../bankAccounts/highInterestCheckingType.cpp
 ../bankAccounts/highInterestSavingsType.cpp
)

#link the header files to the executable files
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/..)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/../bankAccounts)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/../user)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/../ultils)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/../bankEmployee)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/../UI)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/../dataStructures)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/../logs)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/../src)

#link ncurses
find_package(Curses REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES})

