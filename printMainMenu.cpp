/**
 * @file printMainMenu.cpp
 * @brief this function contains the text related to the mainmenu
 * 
 * This file include the implementation and handles the display
 * and interactoin of main menu.
 */

/**
 * @brief print the manmenu to console
 *
 * @code
 * printMainMenu();
 * @endCode
 *
 * @return void
 */
#include "header.h"

void printMainMenu() 
{
	string s1 = "Saucy Banking";
	string s2 = "<1> Account";
	string s3 = "<2> Receipt";
	string s4 = "<3> Exit";


	cout << left;
	cout << setw((SCREEN_SIZE - s1.size())/2) << " " << s1 << endl;
	cout << setw((SCREEN_SIZE - s2.size())/2) << " " << s2 << endl;
	cout << setw((SCREEN_SIZE - s3.size())/2) << " " << s3 << endl;
	cout << setw((SCREEN_SIZE - s4.size())/2) << " " << s4 << endl;
	cout << right;
}
