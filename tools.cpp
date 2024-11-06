//#include <iostream>
//using namespace std;
#include "tools.h"
//#include "header.h"
//#include <cassert>
//#include <fstream> // for file handling
//#include <sys/stat.h> // for mkdir 
//#include <sys/types.h> // for mode_t
//#include <cstring> // for strerror
//#include <bcrypt/BCrypt.hpp>
//hashing header files
//#include <openssl/sha.h>
//#include <sstream>
//#include <iomanip>
//salt
#include <random>
#include <fstream>
//string to acII to bits
//#include <bitset>

void printErrorMessage(string problem)
{
	cout << problem + " enter anything to continue -->";
	cin.clear();
	cin.ignore(100000 , '\n');
}


string generateSalt(int length)
{
	string salt;
	static const char alphanum[] = "0123456789" 
											 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
											 "abcdefghijklmnopqrstuvwxyz"
											 "!@#$%^&*()`~{}?.>,<";
	//This is a generate random number from hardware based entropy source 
	random_device rd; // Seed for the random number generator
	std::mt19937 gen(rd()); // random number engine
	uniform_int_distribution<> dis(0, sizeof(alphanum) -2); //Distribtion range

	for(int i = 0; i < length; i++)
	{
		salt += alphanum[dis(gen)];
	}

	return salt;

}

//This function is 
vector<int> generatePrimes(int n, int maxPrimes)
{
	vector<bool> isPrime(n + 1, true);
	vector<int> primes;

	isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

	for(int i = 2; i * i <= n; i++)
	{
		if(isPrime[i])
		{
			//Marking multiples of i as false
			for( int j = i * i; j <= n; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	// Collecting prime numbers, limiting by maxPrimes
	for(int i =2; i <= n && primes.size() < maxPrimes; i++)
	{
		if(isPrime[i])
		{
			primes.push_back(i);
		}
	}

	return primes; //return the list of prime numbers
}

/**
 * FUNCTION getPrimeNumbers
 * INPUT integer of total ASCII --> means you get the ascii values from a string and totals them
 	prime number of each integer store it into a int vector.
 * The funcion will get his result by checking if the number is even and if so divid it by 2 and store 2 into the vector
 * If the result is odd then it will check if its divid able by all the prime numbers and as a result of zero
 * I want to check the prime numbers one by one. The loop exits when the number that divides the num is equal to zero. that means there is no more left to do.
 */ 
double totalPrimeNumbers(int num)
{
	vector<int> passwordPrime;
	vector<int> neededPrime;
	int index = 0;
	int elements = 0;
	double total = 0;
	int maxPrimes = num / 2;

	//This function gets the prime numbers a odd number will need to divide into prime numbers
	neededPrime = generatePrimes(num , maxPrimes);
	//elements gets the number of prime numbers so that when it loops through the vector it can reset back to the start
	elements = neededPrime.size();

	//ICV is when the number has reached zero
	while(num > 1)
	{
//cout << "IS loop stuck here" << endl;
//cout << "This is the number" << num << endl;
//cout << "THis is the current prime numner" << neededPrime[index] << endl;
//cin.ignore(1000 , '\n');


		if(elements <= index)
		{
			index = 0;
		}

		//makes sure we don't go out of scope of the neededPrimes vector
		if(elements > index)
		{
			//checks if the number is even
			if(num % 2 == 0)
			{
				while(num % 2 == 0)
				{
					num = num / 2;
					passwordPrime.push_back(2);
				}
			}

			//checks if the number is odd and is a prime numbers
			if(num % neededPrime[index] == 0)
			{
				while(num % neededPrime[index] == 0)
				{
					num = num / neededPrime[index];
					passwordPrime.push_back(neededPrime[index]);
				}
			}

		}

		index++;
	} //while(num > 1)

	// gets the number of prime numbers from the password ASCII values
	elements = passwordPrime.size();

	index = 0;
	total = 0;

	//takes the square root of the prime numbers to hash it
	while(elements > index)
	{
		total = total + sqrt(passwordPrime[index]);
		index++;
	}


//	cout << "Get the prime:" << endl;
	return total;
}

/**
 * FUNCTION HASHER
 *
 * The purpose of this function is to convert a string into hash integers
 * these hash intgers are from taking the sqaure root of prime numbers which can't go back
 */

string hasher(string input)
{
	int totalASCII = 0;
	int saltASCII = 0;
	char originalChar;
	string hashStr;
	int number = 0;

	for(char& c : input)
	{
		totalASCII = totalASCII + static_cast<int>(c);
	}


//	cout << "hasher has ran" << endl;
	//this number gets the hash value + the salt and add them together
	double hashPass = totalPrimeNumbers(totalASCII); // + getPrimeNumbers(25);
	//convets the double to a string
	string numberStr = to_string(hashPass);

	//This for statment converts a string of 10.42132 into the ASCII value 
	for(char c : numberStr)
	{
		// from a string of numbers to ASCII int
		number = static_cast<int>(c);
		// ASCOO int to char from the ASCII value
		originalChar = static_cast<char>(number + 48);
		// Adds up the char values
	   hashStr = hashStr + originalChar;
	}

	return hashStr;
}

/**
 *  displayLogo()
 */

void printLogo()
{
	cout << "\033c";
	ifstream logoFile("logoFile.txt");
	string line;
	
	if(logoFile.is_open())
	{
		while(getline(logoFile, line))
		{
			cout << line << endl;
		}

		logoFile.close();
	}
	else
	{
		cout << "error file logoFile.txt was not able to open" << endl;
	}

	cin.ignore(100000 , '\n');
}

int getch()
{
    int ch;
    // struct to hold the terminal settings
    struct termios old_settings, new_settings;
    // take default setting in old_settings
    tcgetattr(STDIN_FILENO, &old_settings);
    // make of copy of it (Read my previous blog to know
    // more about how to copy struct)
    new_settings = old_settings;
    // change the settings for by disabling ECHO mode
    // read man page of termios.h for more settings info
    new_settings.c_lflag &= ~(ICANON | ECHO);
    // apply these new settings
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
    // now take the input in this mode
    ch = getchar();
    // reset back to default settings
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
    return ch;
}

// Function to hide the password input and return the entered password
string hidePassword()
{
    string hiddenPassword;
    int ch;

    cout << "Enter password: ";
    while ((ch = getch()) != '\n') {
        if (ch == 127 || ch == 8) {  // handle backspace
            if (!hiddenPassword.empty()) {
                hiddenPassword.pop_back();
                cout << "\b \b";  // Erase the last character
            }
        } else {
            hiddenPassword += ch;
            cout << "*";  // Print '*' for each character entered
        }
    }
    cout << endl;  // Move to the next line after password input
    return hiddenPassword;
}
