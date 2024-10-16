#include "header.h"

/**
 * @file checkVaildInteger.cpp 
 * @beief 
 * the purpose of these function is to check the input of integers
 * and output a intended integer.
 */

/**
 * @beief
 * The function requires a max and min integer. The function then
 * checks if the input is a integer and next it checks the range
 * of the input if false the function will repomt
 *
 * @code
 * checekVaildInteger(10 , 0);
 * @endCode
 *
 * @return int
 */

int checkVaildInteger(int max, int min)
{
	//variables
	int num;
	bool vaildInput = false;
	
	do
	{
	
		if(!(cin >> num))
		{
			
			cin.clear();
			cin.ignore(10000 , '\n');
			cout << "Error: please enter a integer" << endl;
		}
		else if(min > num || num > max)
		{
			cout << "Error: input is out of range. Please enter between: " << max << "/" << min << endl;
		}		
		else	
		{
			vaildInput = true;
		}

	cin.ignore(1000 , '\n');

	}while(!(vaildInput));	

	return num;
}
