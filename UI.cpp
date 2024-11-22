#include "UI.h"

void screenResize(WINDOW *&win, int &ymax, int &xmax)
{
		// checks if the screen has changed
		int copy = xmax;
		getmaxyx(stdscr, ymax, xmax);

		if(xmax != copy)
		{
			delwin(win); // cleans the memroy for the old window
			win = newwin(ymax, xmax, 0, 0);
			box(win, 0 ,0);
			keypad(win, true); //changes the size may lose keypad so it needs to be called again
		}
}

void createWindow(WINDOW *&win, int &ymax, int &xmax)
{
	//gets the screen size
	getmaxyx(stdscr, ymax, xmax);
	win = newwin(ymax, xmax, 0, 0); // makes the window
	refresh(); // refreash the screen so it knows we made a window
	box(win, 0 ,0);
}

void startColor(WINDOW *&win)
{
	//checks if the computer supports colors
	if(!has_colors())
	{
		printw("terminal dose not support color");
		getch();
		werase(win);
		delwin(win); //clean up
		endwin();
		exit(0);
	}

	//starts the color
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_GREEN, COLOR_BLUE);
}


template<size_t N>
void highlightPosition(WINDOW *&win, int position, array<string, N> choices, int xmax, int starty)
{

	for(int i = 0; i < choices.size(); i++)
	{
		if(i == position)
			wattron(win, COLOR_PAIR(1));
		mvwprintw(win, i+starty, (( xmax - choices[i].size())/2), choices[i].c_str());
		wattroff(win, COLOR_PAIR(1));
	}
}

int printMainMenu()
{
	//starts ncurses
	initscr();
	raw(); // makes input raw
	noecho(); // removes the user input from being visable
	cbreak();

	// variables
	int ymax, xmax; //screen size
	int position = 0;
	WINDOW *win; //window
	int choice;
	int starty = 3; //this is the row where the text start

	createWindow(win, ymax, xmax);

	const string s1 = "Welcome! Choose an option";
	array<string, 2> choices = { "0. Exit Program", "1. Login"};
	const string s4 = "Enter Up arrow or down arrow and enter -->:";

	startColor(win); //provides the colors

	// enable arrows
	keypad(win, true);

	while(true)
	{

		screenResize(win, ymax, xmax);

		// prints the UI
		mvwprintw(win, 1, ((xmax - s1.size())/2) , s1.c_str()); //.c_str() converts string to const *char

		highlightPosition(win, position, choices, xmax, starty);

		mvwprintw(win, 6, ((xmax - s4.size())/2), s4.c_str());
		wrefresh(win); //updates the information


		// this is ture when the user enters enter
		if(choice == KEY_ENTER || choice == '\r' || choice == '\n')
		{
			werase(win); // clear the contents of the window
			delwin(win); //delete the window
			endwin();
			return position;
		}

		choice = wgetch(win);

		switch(choice)
		{
			case KEY_UP:
				if(position > 0)
				{
					position--;
				}
				break;
			case KEY_DOWN:
				if(position < 1)
				{
					position++;
				}
				break;
			default:
			break;
		}//switch
	}//while
}//printmainmenu

// this function will print the login UI 
int printLoginAccount(string& usr, string& pass) //prints the ui
{
	initscr();

	raw();
	noecho(); // removes the user input from being visable
	cbreak();

	// position variables
	int ymax, xmax;
	int position = 0;
	string hidepass = "";
	WINDOW *win;

	char ch;
	int c;

	// UI variables
	const string s1 = "Login page";
	array<string, 4> choices = {"0. Exit Program", "1. Enter Username: ", "2. Enter Password: ", "3. Enter "};
	const string s3 = "1. Enter Username: ";
	const string s4 = "2. Enter Password: ";
	const string s6 = "Press enter to push data -->:";

	/* This functions create the screen and box */
	createWindow(win, ymax, xmax);

	startColor(win);

	// enable arrows
	keypad(win, true);

	while(true)
	{
		// checks if the screen has changed
		screenResize(win, ymax, xmax);

		// prints the UI
		mvwprintw(win, 1, ((xmax - s1.size())/2) , s1.c_str()); //.c_str() converts string to const *char

		highlightPosition(win, position, choices, xmax, 3);

		mvwprintw(win, 8, ((xmax - s6.size())/2), s6.c_str());
		wrefresh(win); //updates the information


		// this is ture when the user enters enter
		if(c == KEY_ENTER || c == '\r' || c == '\n')
		{
			//exits
			if(position == 0 || position == 3)
			{
				werase(win); // clear the contents of the window
				delwin(win); //delete the window
				endwin();
				return position;
			}


			//this statment gets the username
			if(position == 1 && (c == KEY_ENTER || c == '\r' || c == '\n'))
			{
				//let the uesr know they selected the line
				wattron(win, COLOR_PAIR(2));
				mvwprintw(win, 4, ((xmax - s3.size())/2) , s3.c_str());
				mvwprintw(win, 4, (((xmax - s3.size())/2) + s3.size()), usr.c_str());
				wattroff(win, COLOR_PAIR(2));
				wrefresh(win);

				while((ch = getch()) != '\n')
				{
					// update the UI

					if(ch == 127) //127 is for back /
					{
						if(!usr.empty())
						{
							usr.pop_back(); //removes the letter
						}
					}
					else
					{
						usr.push_back(ch);
					}//else

					//updates the screen as the user inputs
					wattron(win, COLOR_PAIR(2));
					mvwprintw(win, 4, ((xmax - s3.size())/2) , s3.c_str());
					mvwprintw(win, 4, (((xmax - s3.size())/2) + s3.size()), usr.c_str());
					wattroff(win, COLOR_PAIR(2));
					wrefresh(win);

					//needs to refefesh everything
					screenResize(win, ymax, xmax);

				}//while

				//update feedback when the user clicks enter
				wattron(win, COLOR_PAIR(1));
				mvwprintw(win, 4, ((xmax - s3.size())/2) , s3.c_str());
				mvwprintw(win, 4, (((xmax - s3.size())/2) + s3.size()), usr.c_str());
				wattroff(win, COLOR_PAIR(1)); // turns off the color pair after use
				wrefresh(win);

			} //if(position = 1 && (c == KEY_ENTER || c == '\r' || c == '\n'))

			mvwprintw(win, 4, (((xmax - s3.size())/2) + s3.size()), usr.c_str());
			wrefresh(win);

			//this statment gets the password
			if(position == 2 && (c == KEY_ENTER || c == '\r' || c == '\n'))
			{
				//let the use know they have selected the line
				wattron(win, COLOR_PAIR(2));
				mvwprintw(win, 5, ((xmax - s4.size())/2) , s4.c_str());
				mvwprintw(win, 5, (((xmax - s4.size())/2) + s4.size()), hidepass.c_str());
				wattroff(win, COLOR_PAIR(2));
				wrefresh(win);

				while((ch = getch()) != '\n')
				{

					if(ch == 127) //127 is for back /
					{
						if(!pass.empty())
						{
							pass.pop_back(); //removes the letter
							hidepass.pop_back();
						}
					}
					else
					{
						pass.push_back(ch);
						hidepass.push_back('*');
					}
					wattron(win, COLOR_PAIR(2));
					mvwprintw(win, 5, ((xmax - s4.size())/2) , s4.c_str());
					mvwprintw(win, 5, (((xmax - s4.size())/2) + s4.size()), hidepass.c_str());
					wattroff(win, COLOR_PAIR(2));
					wrefresh(win);
				}//while

				//set text back
				wattron(win, COLOR_PAIR(1));
				mvwprintw(win, 5, ((xmax - s4.size())/2) , s4.c_str());
				mvwprintw(win, 5, (((xmax - s4.size())/2) + s4.size()), hidepass.c_str());
				wattroff(win, COLOR_PAIR(1)); //turns off the color pair afer use
				wrefresh(win);

			} //if(position = 1 && (c == KEY_ENTER || c == '\r' || c == '\n'))

			mvwprintw(win, 5, (((xmax - s4.size())/2) + s4.size()), hidepass.c_str());
			wrefresh(win);

		} //if(c == KEY_ENTER || c == '\r' || c == '\n')

		c = wgetch(win);


		switch(c)
		{
			case KEY_UP:
				if(position > 0)
				{
					position--;
				}
				break;
			case KEY_DOWN:
				if(position < 3)
				{
					position++;
				}
				break;
			default:
			break;
		}//switch


	} //while

}
