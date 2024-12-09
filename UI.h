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


/*
 * FUNCTION: highLightChoice
 *
 * Varables:
 * WINDOW *&win this is the window created using ncurses, it updates the terminal data but not the terminal screen
 * int position: This is the position of the seleected text
 * array<string, Type> choices: Outputs text coralated to the position selected. string is data type and Type is number of elemenets
 * array<string, Type> variabels: Stores the address of variables so that it can contain multiple data type, this stores the variables
 */

template<size_t Type, size_t Type1>
void highLightChoice(WINDOW *&win, int position, array<string, Type> choices, array<string, Type1> input, int xmax, int starty, int startRow, int endRow)
{

	for(int i = 0; i < choices.size(); i++)
	{
			if(position >= startRow && position <= endRow)
			{
				wattron(win, COLOR_PAIR(2));
			}
			mvwprintw(win, i + starty, ((xmax - choices[i].size())/2) , choices[i].c_str());
			mvwprintw(win, i + starty, (((xmax - choices[i].size())/2) + choices[i].size()), input[i].c_str());
			wattroff(win, COLOR_PAIR(2));
	}
}

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
