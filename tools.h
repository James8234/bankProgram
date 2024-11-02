#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include <iostream>
#include <string>
//for hide password
#include <termios.h>
#include <unistd.h>
using namespace std;

string hasher(string input);

double totalPrimeNumbers(int num);

vector<int> generatePrimes(int n, int maxPrimes);

//This function goes with hidepassword
int getch();

// Function to hide the password input and return the entered password
string hidePassword();



#endif
