#include "UI.h"

int printMainMenu()
{
	raw();
	noecho(); // removes the user input from being visable
	cbreak();

	int ymax, xmax;
	int position = 0;
	int copy;

	//gets the screen size
	getmaxyx(stdscr, ymax, xmax);

	WINDOW *win = newwin(ymax, xmax, 0, 0); // makes the window
	refresh(); // refreash the screen so it knows we made a window

	box(win, 0 ,0);

	const string s1 = "Welcome! Choose an option";
	const string s2 = "0. Exit Program";
	const string s3 = "1. Login";
	const string s4 = "Enter your choice -->:";

	//checks if the computer supports colors
	if(!has_colors())
	{
		printw("terminal dose not support color");
		getch();
		endwin();
		exit(0);
	}

	//starts the color
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);

	// enable arrows
	keypad(win, true);

	while(true)
	{
		// checks if the screen has changed
		copy = xmax;
		getmaxyx(stdscr, ymax, xmax);

		if(xmax != copy)
		{
			delwin(win); // cleans the memroy for the old window
			win = newwin(ymax, xmax, 0, 0);
			box(win, 0 ,0);
			keypad(win, true); //changes the size may lose keypad so it needs to be called again
		}

		// prints the UI
		mvwprintw(win, 1, xmax/2 - s1.size(), s1.c_str()); //.c_str() converts string to const *char

		if(position == 0)
		{
			wattron(win, COLOR_PAIR(1));
			mvwprintw(win, 3, xmax/3, s2.c_str());
			wattroff(win, COLOR_PAIR(1)); // turns off the color pair after use
		}
		else
		{
			mvwprintw(win, 3, xmax/3, s2.c_str());
		}

		if(position == 1)
		{
			wattron(win, COLOR_PAIR(1));
			mvwprintw(win, 4, xmax/3, s3.c_str());
			wattroff(win, COLOR_PAIR(1)); // turns off the color pair after use
		}
		else
		{
			mvwprintw(win, 4, xmax/3, s3.c_str());
		}

		mvwprintw(win, 6, xmax/3, s4.c_str());
		wrefresh(win); //updates the information

		int c = wgetch(win);

		// this is ture when the user enters enter
		if(c == KEY_ENTER || c == '\r' || c == '\n')
		{
			endwin();
			return position;
		}

		// This decrements the position
		if(c == KEY_UP && position > 0)
		{
			position--;
		}

		// This increments the position
		if(c == KEY_DOWN && position < 1)
		{
			position++;
		}

	}

}
