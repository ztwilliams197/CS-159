
/******************************************************************************
* Assignment:  either Lab # or Homework #
* Lab Section: the day, time, and location of your lab meeting
* Description: verbose description of what the program does
* Programmers: fullname1 login1@purdue.edu
*              fullname2 login2@purdue.edu
*              fullname3 login3@purdue.edu
******************************************************************************/

#include <stdio.h>

int initSearch(long long int searchNum, int countVal);
int adjustSearch(long long int searchNum, int countVal);
void output(int initCount, int adjustCount);

int main()
{
	long long int searchNum; // Number to be searched through
	int countVal; // Number searched for in searchNum
	int initCount; // Number of times countVal occurs in searchNum
	int adjustCount; // Number of times countVal occurs after adjustment
	
	// Calls functions for input, calculations, and output
	initCount = initSearch(searchNum, countVal);
	adjustCount = adjustSearch(searchNum, countVal);
	output(initCount, adjustCount);

	return 0;

}

/******************************************************************************
* Function:    initSearch
* Description: Takes a number to be searched and a two digit number to search for
			   and determines how many times the two digit number occurs in the large number
* Parameters:  searchNum, long long int, Number to be searched
*              countVal, int, Number being searched for
* Return:      int, Number of times countVal occurs in searchNum
******************************************************************************/
int initSearch(long long int searchNum, int countVal)
{
	int occurences; // Number of times countVal occurs in searchNum

	occurences = 0; // Initialization

	// Iterates through number and adds 1 to occurences when countVal occurs in searchNum
	while (searchNum > 0)
	{
		if (searchNum % 10 == countVal % 10 && (searchNum / 10) % 10 == countVal / 10)
		{
			occurences++;
			searchNum /= 100;
		}
		else
			searchNum /= 10;
	}

	return occurences;
}

/******************************************************************************
* Function:    adjustSearch
* Description: Takes a number to be searched and a two digit number to search for
			   and determines how many times the two digit number could occur in the large number
* Parameters:  searchNum, long long int, Number to be searched
*              countVal, int, Number being searched for
* Return:      int, Number of times countVal could occur in searchNum
******************************************************************************/
int adjustSearch(long long int searchNum, int countVal)
{
	int occurences; // Number of times countVal occurs in searchNum
	
	occurences = 0; // Initialization

	// Iterates through number and adds 1 to occurences when countVal could occur in searchNum
	while (searchNum > 10)
	{
		if (searchNum % 10 == countVal % 10 || (searchNum / 10) % 10 == countVal / 10)
		{
			occurences++;
			searchNum /= 100;
		}
		else
			searchNum /= 10;
	}

	return occurences;
}

/******************************************************************************
* Function:    initSearch
* Description: Takes a number to be searched and a two digit number to search for
			   and determines how many times the two digit number could occur in the large number
* Parameters:  searchNum, long long int, Number to be searched
*              countVal, int, Number being searched for
* Return:      int, Number of times countVal occurs in searchNum
******************************************************************************/
/*
int validInput(int input)
{
	int valid;
	int temp;
	int zero = 0;
	
	valid = 1;
	temp = input;

	do
	{
		if (temp % 10 == 0)
			zero = 1;

		temp /= 10;
		else if (temp < 10 && temp > 0)
			printf;
		else if (temp < 0)
			printf;
		else
			temp = temp

	} while (temp % 10 != 0);

	if (input < 10)
	{
		print("Error! Data must be >= 10");
		valid = 0;
	}
	else if (zero)
	{
		print("Error!! Data value cannot contain a zero digit!");
		valid = 0;
	}

	return valid;
}*/

/******************************************************************************
* Function:    output
* Description: Outputs occurence values found in number
* Parameters:  initCount, int, Number of occurences in number initially
*              adjustCount, int, Number of occurences after adjustment
* Return:      void
******************************************************************************/
void output(int initCount, int adjustCount)
{
	printf("Exact Count: %d\n", initCount);
	printf("Adjusted Count: %d\n", adjustCount);

	return;
}