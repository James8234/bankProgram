#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
using namespace std;

// ncurses development libary
#include <ncurses.h>

#include "header.h"

//WINDOW *win;

/**
 * FUNCTION printMainMenu
 * 	The purpsoe of this function is to print a UI hwne starting the program.
 * This UI create a menu for the user to select to login or exit the program.
 *
 * @return int
 */
int printMainMenu();

#endif
