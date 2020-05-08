/******************************************************************************
 * Assignment:  Homework 6
 * Lab Section: October 15, 1:30
 * Description: This program takes user input for the day of the week, the month, and the year. Then is calculates whether or not there are 5 instances of the day input in the month input. If there are 5 instances, the program lists them and outputs the number of the day that the instance occurs on.
 * Programmers: Ian Flude iflude@purdue.edu
 *              Justin Chen chen3277@purdue.edu
 *              Zachary Williams will2051@purdue.edu
 ******************************************************************************/
#include <stdio.h>

int getInputDay(int); //function to get day input
int getInputYear(int); //function to get year input
int checkLeapYear(int); //function to check for leap year
int calcMonth(int, int); //function to find the month
int calcDayOfWeek(int, int); //function to find the day of the week
int compDates(int, int); //function to find the month start day
void printMonthCalendar(int, int, int); //function to print month calendar
int monthDay(int, int); //function that finds the amount of days in the month input
void printOutput(int, int, int, int, int); //function to print the output
void printWeekDay(int); //function to print the weekday
void printMonth(int); //function to print the month

int main (void)
{
  int day; //day of the week
  int year; //year number
  int month; //month number
  int weekDay; //weekday number
  int monthStart; //day of the week that the month starts on
  int monthDayCalc; //amount of days in the month
  int isLeapYear; //leap year value

  //initializations
  day = 0;
  year = 0;
  month = 0;

  //funtion calls
  year = getInputYear(year);
  isLeapYear = checkLeapYear(year);
  day = getInputDay(isLeapYear);

  weekDay = calcDayOfWeek(day, year);
  month = calcMonth(day, isLeapYear);
  monthStart = compDates(month, year);
  monthDayCalc = monthDay(month, year);

  printOutput(month, year, weekDay, monthDayCalc, monthStart);

  return 0;
}

/******************************************************************************
 * Function:    getInputYear
 * Description: this function gets the user input for the year
 * Parameters:  year, integer, this is the year
 *
 * Return:      integer and this is the year
 ******************************************************************************/

int getInputYear(int year)
{
  int numYear; //This is the year

  printf("Enter the year -> ");
  scanf("%d", &numYear);
  return numYear;
}

/******************************************************************************
 * Function:    getInputDay
 * Description: This function gets the input for the day whether it is a normal year or leap year
 * Parameters:  day, integer, and this is the day value
 *              isLeapYear, integer, and this is the leap year value
 * Return:      integer and this is the day input
 ******************************************************************************/
int getInputDay(int isLeapYear)
{
  int numDay; //day number

  //this if statement checks for a leap year
  if (isLeapYear)
  {
    printf("Enter day number of the year (1-366) -> ");
    scanf("%d", &numDay);
  }
  else
  {
    printf("Enter day number of the year (1-365) -> ");
    scanf("%d", &numDay);
  }

  return numDay;
}

/******************************************************************************
 * Function:    checkLeapYear
 * Description: this function checks for the leap year
 * Parameters:  year, integer, this is the year
 *
 * Return:      integer and this is the leap year value
 ******************************************************************************/
int checkLeapYear(int year)
{
  return (!(year % 4) && (year % 100)) || !(year % 400);
}

/******************************************************************************
 * Function:    calcDayOfWeek
 * Description: this function determines the day of the week
 * Parameters:  day, integer, and this is the day number
 *              year, integer, and this is the year number
 * Return:      integer and this is the day of the week number
 ******************************************************************************/
int calcDayOfWeek(int day, int year)
{
  int dayOfWeek; //day of week number
  int lastDay; //last day of the previous year

  //initializations
  dayOfWeek = 0;

  //calculations
  lastDay = ((year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
  lastDay++;

  //if statements to determine the day of the week
  if ((day % 7 + lastDay) <= 7)
    dayOfWeek = day % 7 + lastDay;
  else
    dayOfWeek = day % 7 + lastDay - 7;

  return dayOfWeek;
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

  // cases determining month number
  if (day <= 31)
    month = 1;
  else if ((day - 31) <= (isLeapYear ? 29 : 28))
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

  return month;
}

/******************************************************************************
 * Function:    compDates
 * Description: this function computes the first day of the month by using the formulas in the book along with some siple calculations and if statements. It also account for if there is a leap year.
 * Parameters:  month, integer, this is the month
 *              year, integer, this is the year
 * Return:      integer and this is the day that the month starts on
 ******************************************************************************/
int compDates(int month, int year)
{
  int dayCount; //last day of the year
  int dayCountStart; //month start day

  //calculations for first day of the year
  dayCount = ((year - 1) * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7;
  dayCount += 2;

  //if statement accounting for leap year
  if (((!(year % 4) && (year % 100)) || !(year % 400)) && month > 2)
    dayCount += 1;

  //if statement determining the start day of each month
  if (month == 1)
    dayCountStart = dayCount;
  else if (month == 2)
    dayCountStart = (dayCount + 31) % 7;
  else if (month == 3)
    dayCountStart = (dayCount + 59) % 7;
  else if (month == 4)
    dayCountStart = (dayCount + 90) % 7;
  else if (month == 5)
    dayCountStart = (dayCount + 120) % 7;
  else if (month == 6)
    dayCountStart = (dayCount + 151) % 7;
  else if (month == 7)
    dayCountStart = (dayCount + 181) % 7;
  else if (month == 8)
    dayCountStart = (dayCount + 212) % 7;
  else if (month == 9)
    dayCountStart = (dayCount + 243) % 7;
  else if (month == 10)
    dayCountStart = (dayCount + 273) % 7;
  else if (month == 11)
    dayCountStart = (dayCount + 304) % 7;
  else if (month == 12)
    dayCountStart = (dayCount + 334) % 7;

  //if statement to account for the start of the month being a saturday
  if (dayCountStart == 0)
    dayCountStart += 7;
  else
    dayCountStart += 0;

  return dayCountStart;
}

/******************************************************************************
 * Function:    monthDay
 * Description: This function uses if statements to get the number of how many days are in the month input, and it also checks for 29 days in february if there is a leap year
 checks for 29 days in february if there is a leap year
 * Parameters:  month, integer, and this is the month
 *              year, integer, and this is the year
 * Return:      integer and this is the number of days in the specified month
 ******************************************************************************/
int monthDay(int month, int year)
{
  int monthDay; //how many days in the month

  //if statement to determine the number of days in each month
  if (month == 1)
    monthDay = 31;
  else if ((month == 2) && ((!(year % 4) && (year % 100)) || !(year % 400)))
    monthDay = 29;
  else if (month == 2)
    monthDay = 28;
  else if (month == 3)
    monthDay = 31;
  else if (month == 4)
    monthDay = 30;
  else if (month == 5)
    monthDay = 31;
  else if (month == 6)
    monthDay = 30;
  else if (month == 7)
    monthDay = 31;
  else if (month == 8)
    monthDay = 31;
  else if (month == 9)
    monthDay = 30;
  else if (month == 10)
    monthDay = 31;
  else if (month == 11)
    monthDay = 30;
  else if (month == 12)
    monthDay = 31;

  return monthDay;
}

/******************************************************************************
 * Function:    printMonthCalendar
 * Description: Prints out the month in calendar form
 * Parameters:  startDay, int, Day of the week of first day of month
 *              days, int, Number of days in the month
 *              dayOfWeek, int, Day of the week of day entered
 * Return:      Void
 ******************************************************************************/
void printMonthCalendar(int startDay, int days, int dayOfWeek)
{
  int week; // Counter variable for week number
  int dayCount; // Counter variable for printing days
  int weekDay; // Counter variable for printing white space

  week = 1; // Initialize counter

  // Prints calendar header
  printf("            S   M   T   W   R   F   S\n");
  printf("           -=- -=- -=- -=- -=- -=- -=- \n");
  printf("Week #%d:  ", week);

  // Prints empty spaces at the beginning of the month
  for (weekDay = 1; weekDay < startDay; weekDay++)
  {
    printf("    ");
  }

  // Prints dashes and day numbers depending on the day
  for (dayCount = 1; dayCount <= days; dayCount++)
  {
    if ((dayCount + startDay - 1) % 7 == dayOfWeek || (dayCount + startDay - 1) % 7 + 7 == dayOfWeek)
    {
      printf("%3d ", dayCount);
    }
    else
    {
      printf("  - ");
    }

    if ((dayCount + startDay - 1) % 7 == 0 && dayCount < days)
    {
      printf("\n");
      week++;
      printf("Week #%d:  ", week);
    }
  }

  return;
}

/******************************************************************************
 * Function:    printWeekDay
 * Description: This function takes the resulting value for day of the week
 *              and prints it out.
 * Parameters:  dayofweek, int, the day of the week of the day number in the year
 *              the user inputted.
 * Return:      void
 ******************************************************************************/
void printWeekDay(int dayOfWeek)
{
  //switch statements to determine output
  switch (dayOfWeek)
  {
    case 1:
      printf("Sunday");
      break;
    case 2:
      printf("Monday");
      break;
    case 3:
      printf("Tuesday");
      break;
    case 4:
      printf("Wednesday");
      break;
    case 5:
      printf("Thursday");
      break;
    case 6:
      printf("Friday");
      break;
    case 7:
      printf("Saturday");
  }
  return;
}

/******************************************************************************
 * Function:    printMonth
 * Description: this function prints out the month from the month input
 * Parameters:  month, integer, and this is the month input
 *
 * Return:      void
 ******************************************************************************/
void printMonth(int month)
{
  //switch determining the month
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
 * Function:    printOutput
 * Description: this function prints the output and calls necessary output functions
 * Parameters:  month, integer, and this is the month input
 *              year, integer, and this is the year input
 *              weekDay, integer, and this is the week day number
 *              daysInMonth, integer, and this is the number of days in the month
 *              startDay, integer, and this is the day the month starts on
 * Return:      void
 ******************************************************************************/
void printOutput(int month, int year, int weekDay, int daysInMonth, int startDay)
{
  //Outputs
  printf("\nMonth: ");
  printMonth(month);
  printf(" %d\nWeekday: ", year);
  printWeekDay(weekDay);
  printf("\n\n");
  printMonthCalendar(startDay, daysInMonth, weekDay);
  printf("\n");

  return;
}
