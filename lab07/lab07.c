/******************************************************************************
* Assignment:  either Lab # or Homework #
* Lab Section: the day, time, and location of your lab meeting
* Description: verbose description of what the program does
* Programmers: fullname1 login1@purdue.edu
*              fullname2 login2@purdue.edu
*              fullname3 login3@purdue.edu
******************************************************************************/

#include <stdio.h>

void input(int* year, int* day, int* isLeapYear);
void output(int month, int dayOfMonth, int year, int dayOfWeek);
int checkLeapYear(int year);
int calcDayOfWeek(int day, int year, int month);
int calcDayOfMonth(int day, int month, int isLeapYear);
int calcMonth(int day, int isLeapYear);
void printMonth(int month);
void printOccurrence(int occurrence);
void printDayOfWeek(int dayOfWeek);

int main()
{
	int year;
	int day;
	int month;
	int dayOfMonth;
	int dayOfWeek;
	int isLeapYear;

	input(&year, &day, &isLeapYear);
	month = calcMonth(day, isLeapYear);
	dayOfMonth = calcDayOfMonth(day, month, isLeapYear);
	dayOfWeek = calcDayOfWeek(day, year, isLeapYear);
	output(month, dayOfMonth, year, dayOfWeek);

	return 1;
}

/******************************************************************************
* Function:    input
* Description: brief description of what the function does
* Parameters:  variable1 name, data type, and description
*              variable2 name, data type, and description
* Return:      data type and description
******************************************************************************/
void input(int *year, int *day, int *isLeapYear)
{
	printf("Enter the year -> ");
	scanf("%d", year);
	*isLeapYear = checkLeapYear(*year);

	if (*isLeapYear)
	{
		printf("Enter day number of the year (1-366) -> ");
		scanf("%d", day);
	}
	else
	{
		printf("Enter day number of the year (1-365) -> ");
		scanf("%d", day);
	}

	return;
}

/******************************************************************************
* Function:    output
* Description: brief description of what the function does
* Parameters:  variable1 name, data type, and description
*              variable2 name, data type, and description
* Return:      data type and description
******************************************************************************/
void output(int month, int dayOfMonth, int year, int dayOfWeek)
{
	printf("Date: ");
	printMonth(month);
	printf(" %d, %d", dayOfMonth, year);
	printf("\nOccurence: ");
	printOccurrence(dayOfMonth % 7 == 0 ? dayOfMonth / 7 : (dayOfMonth / 7) + 1);
	printDayOfWeek(dayOfWeek);
	printf("\n");

	return;
}

/******************************************************************************
* Function:    checkLeapYear
* Description: brief description of what the function does
* Parameters:  variable1 name, data type, and description
*              variable2 name, data type, and description
* Return:      data type and description
******************************************************************************/
int checkLeapYear(int year)
{
	return (!(year % 4) && (year % 100)) || !(year % 400);
}

/******************************************************************************
* Function:    calcMonth
* Description: brief description of what the function does
* Parameters:  variable1 name, data type, and description
*              variable2 name, data type, and description
* Return:      data type and description
******************************************************************************/
int calcDayOfWeek(int day, int year, int month)
{
	int dayOfWeek;
	int lastDay;

	lastDay = ((year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;

	if ((day % 7 + lastDay) <= 7)
		dayOfWeek = day % 7 + lastDay;
	else
		dayOfWeek = day % 7 + lastDay - 7;

	return dayOfWeek;
}

/******************************************************************************
* Function:    calcDayOfMonth
* Description: brief description of what the function does
* Parameters:  variable1 name, data type, and description
*              variable2 name, data type, and description
* Return:      data type and description
******************************************************************************/
int calcDayOfMonth(int day, int month, int isLeapYear)
{
	int dayOfMonth = day;

	switch (month)
	{
	case 12:
		dayOfMonth -= 30;
	case 11:
		dayOfMonth -= 31;
	case 10:
		dayOfMonth -= 30;
	case 9:
		dayOfMonth -= 31;
	case 8:
		dayOfMonth -= 31;
	case 7:
		dayOfMonth -= 30;
	case 6:
		dayOfMonth -= 31;
	case 5:
		dayOfMonth -= 30;
	case 4:
		dayOfMonth -= 31;
	case 3:
		dayOfMonth -= isLeapYear ? 29 : 28;
	case 2:
		dayOfMonth -= 31;
	case 1:
		break;
	}

	return dayOfMonth;
}

/******************************************************************************
* Function:    calcMonth
* Description: this function makes use of if statements and some small calculations to determine which month the date input falls in. It also checks for the case of a leap year and adjusts the calculations accordingly.
* Parameters:  day, integer, this is the given day
*              isLeapYear, integer, this is whether it is a year or not
* Return:      integer and this is the number of the month
******************************************************************************/

int calcMonth(int day, int isLeapYear)
{
	int month; //month number (1-12)

	// case for not a leap year
	if (isLeapYear == 0)
	{
		// cases determining month number
		if (day <= 31)
			month = 1;
		else if ((day - 31) <= 28)
			month = 2;
		else if ((day - 59) <= 31)
			month = 3;
		else if ((day - 90) <= 30)
			month = 4;
		else if ((day - 120) <= 31)
			month = 5;
		else if ((day - 151) <= 30)
			month = 6;
		else if ((day - 181) <= 31)
			month = 7;
		else if ((day - 212) <= 31)
			month = 8;
		else if ((day - 243) <= 30)
			month = 9;
		else if ((day - 273) <= 31)
			month = 10;
		else if ((day - 304) <= 30)
			month = 11;
		else
			month = 12;
	}
	// case for a leap year
	else
	{
		// cases determining month number
		if (day <= 31)
			month = 1;
		else if ((day - 31) <= 29)
			month = 2;
		else if ((day - 60) <= 31)
			month = 3;
		else if ((day - 91) <= 30)
			month = 4;
		else if ((day - 121) <= 31)
			month = 5;
		else if ((day - 152) <= 30)
			month = 6;
		else if ((day - 182) <= 31)
			month = 7;
		else if ((day - 213) <= 31)
			month = 8;
		else if ((day - 244) <= 30)
			month = 9;
		else if ((day - 274) <= 31)
			month = 10;
		else if ((day - 305) <= 30)
			month = 11;
		else
			month = 12;
	}

	return month;
}

/******************************************************************************
* Function:    printMonth
* Description: brief description of what the function does
* Parameters:  variable1 name, data type, and description
*              variable2 name, data type, and description
* Return:      data type and description
******************************************************************************/
void printMonth(int month)
{
	switch (month)
	{
	case 12:
		printf("December");
		break;
	case 11:
		printf("November");
		break;
	case 10:
		printf("October");
		break;
	case 9:
		printf("September");
		break;
	case 8:
		printf("August");
		break;
	case 7:
		printf("July");
		break;
	case 6:
		printf("June");
		break;
	case 5:
		printf("May");
		break;
	case 4:
		printf("April");
		break;
	case 3:
		printf("March");
		break;
	case 2:
		printf("February");
		break;
	case 1:
		printf("January");
		break;
	}

	return;
}

/******************************************************************************
* Function:    printoccurrence
* Description: this function [rints the occurence of the particular day of week
*              that has happened in the month by the date.
* Parameters:  occurrence, int, the number of times the day of week occured
*              in the month on the date calculated by inputs of users.
* Return:      void
******************************************************************************/
void printOccurrence(int occurrence)
{
	//switch statements to determine output
	switch (occurrence)
	{
	case 1:
		printf("1st ");
		break;
	case 2:
		printf("2nd ");
		break;
	case 3:
		printf("3rd ");
	case 4:
	case 5:
		printf("%dth ", occurrence);
	}
	return;
}

/******************************************************************************
* Function:    printdayofweek
* Description: This function takes the resulting value for day of the week
*              and prints it out.
* Parameters:  dayofweek, int, the day of the week of the day number in the year
*              the user inputted.
* Return:      void
******************************************************************************/
void printDayOfWeek(int dayOfWeek)
{
	//switch statements to determine output
	switch (dayOfWeek)
	{
	case 1:
		printf("Monday");
		break;
	case 2:
		printf("Tuesday");
		break;
	case 3:
		printf("Wednesday");
		break;
	case 4:
		printf("Thursday");
		break;
	case 5:
		printf("Friday");
		break;
	case 6:
		printf("Saturday");
		break;
	case 7:
		printf("Sunday");
	}
	return;
}