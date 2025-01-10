#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include <iostream>
#include <string>
//for hide password
#include <termios.h>
#include <unistd.h>
using namespace std;

/*
 * FUNCTION printErrorMessage
 * The purpose of this function is to provide an reuseable error message. That promts the user to enter anything and clear the cin error state
 */
void printErrorMessage(string problem);

// this function hashes the given password
string hasher(string input);

// this function converts the password into prime numbers and addes them together
double totalPrimeNumbers(int num);

// this function produces the needed prime numbers and stores them in a vector
vector<int> generatePrimes(int n, int maxPrimes);

//This function goes with hidepassword
int hider();

// Function to hide the password input and return the entered password
string hidePassword();



#endif
