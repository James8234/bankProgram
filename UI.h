#ifndef UI_H
#define UI_H

#include <array>
#include <iostream>
#include <string>
using namespace std;

// ncurses development libary
#include <ncurses.h>
#include "header.h"

// starts the color
void startColor(WINDOW *&win);

// This function purpose is to create the screen and box
void createWindow(WINDOW *&win, int &ymax, int &xmax);

// This funtion purpose is to resize the screen and box when the terminal screen changes
void screenResize(WINDOW *&win, int &ymax, int &xmax);

// This function purpose is to print the text and highlight it when selected
void highlightPosition(WINDOW *&win, int position, string choices[], int xmax, int starty);

/**
 * FUNCTION printMainMenu
 * 	The purpsoe of this function is to print a UI hwne starting the program.
 * This UI create a menu for the user to select to login or exit the program.
 *
 * @return int
 */
int printMainMenu();

/**
 * FUNCTION printLoginAccount
 * 	The purpose of this functon is to have the enter a value using yhe UI
 * to navagate the program.
 *
 * @prerec
 * string usr, string pass
 *
 * @return int
 */
int printLoginAccount(string& usr, string& pass);

#endif
