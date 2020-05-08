/******************************************************************************
 * Assignment:  Homework 04
 * Lab Section: Friday, 11:30, LILY G428
 * Description: Takes input of the year, month, and day of week, and determines
 *			   if there are 5 occurrences of the day of the week in the month
 *			   in that year
 * Programmers: Zachary Williams will2051@purdue.edu
 ******************************************************************************/

#include <stdio.h>

int input(int* year, int* month, int* dayOfWeek);
void output(int dayOfWeek, int month, int year, int fiveOccurrences, int firstDayOfMonth);
int checkLeapYear(int year);
int calcFirstDayOfMonth(int year, int month, int isLeapYear);
int calcDaysInMonth(int month, int isLeapYear);
int checkFiveOccurrences(int firstDayOfMonth, int dayOfWeek, int daysInMonth);
void printMonth(int month);
void printDayOfWeek(int dayOfWeek);
void printOccurrences(int dayOfWeek, int firstDayOfMonth);

int main()
{
  int year; // Value for year
  int month; // Value for month
  int dayOfWeek; // Value for day of week
  int daysInMonth; // Number of days in the month
  int firstDayOfMonth; // Value for day of the week of first day of month
  int isLeapYear; // 0 or 1 Depending on whether the year is a leap year or not
  int fiveOccurrences; // 0 or 1 Depending on whether there are 5 occurences of the day of week

  isLeapYear = input(&year, &month, &dayOfWeek);
  firstDayOfMonth = calcFirstDayOfMonth(year, month, isLeapYear);
  daysInMonth = calcDaysInMonth(month, isLeapYear);
  fiveOccurrences = checkFiveOccurrences(firstDayOfMonth, dayOfWeek, daysInMonth);
  output(dayOfWeek, month, year, fiveOccurrences, firstDayOfMonth);

  return 1;
}

/******************************************************************************
 * Function:    input
 * Description: Take input for the year, month, and day of the week
 * Parameters:  *year, int, value for year
 *              *month, int, value for month
 *			   *dayOfWeek, int, value for year
 * Return:      Boolean value corresponding to if the year is a leap year or not
 ******************************************************************************/
int input(int *year, int *month, int *dayOfWeek)
{
  printf("Enter day of week (1-7) -> ");
  scanf("%d", dayOfWeek);
  printf("Enter month of the year -> ");
  scanf("%d", month);
  printf("Enter the year -> ");
  scanf("%d", year);

  return checkLeapYear(*year);
}

/******************************************************************************
 * Function:    output
 * Description: Outputs findings of all calculations
 * Parameters:  dayOfWeek, int, Value for day of week
 *              month, int, Value for month
 *			   year, int, Value for year
 *			   fiveOccurences, int, Boolean corresponding to if there are five occurences
 *              firstDayOfMonth, int, value for first day of month
 * Return:      void
 ******************************************************************************/
void output(int dayOfWeek, int month, int year, int fiveOccurrences, int firstDayOfMonth)
{
  printf("\nFinding: ");

  // Prints different ouput depending on if there are five occurences or not
  if (fiveOccurrences)
  {
    printf("There exists five ");
    printDayOfWeek(dayOfWeek);
    printf(" dates in ");
    printMonth(month);
    printf(" of %d", year);
    printOccurrences(dayOfWeek, firstDayOfMonth);
  }
  else
  {
    printf("There are not five ");
    printDayOfWeek(dayOfWeek);
    printf(" dates in ");
    printMonth(month);
    printf(" of %d\n", year);
  }

  return;
}

/******************************************************************************
 * Function:    checkLeapYear
 * Description: Determines if the year is a leap year
 * Parameters:  year, int, value for year
 * Return:      boolean value corresponding to whether it is a leap year or not
 ******************************************************************************/
int checkLeapYear(int year)
{
  return (!(year % 4) && (year % 100)) || !(year % 400);
}

/******************************************************************************
 * Function:    firstDayOfMonth
 * Description: Determines what day of the week the first day of the month is
 * Parameters:  year, int, value for year
 *			   month, int, value for month
 *			   isLeapYear, int, value corresponding to if the year is a leap year
 * Return:      Integer, value corresponding to the day of the week of the first
 *			   day of the month
 ******************************************************************************/
int calcFirstDayOfMonth(int year, int month, int isLeapYear)
{
  int dayOfYear = 1; // Day of year of first day in month
  int dayOfWeek; // Day of the week of first day of month
  int firstDay; // Day of the week of current year

  // Calculates the first day of the current year
  firstDay = ((year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7 + 1;

  // Calculates the days in the year that have passed prior to current month
  switch (month)
  {
    case 12:
      dayOfYear += 30;
    case 11:
      dayOfYear += 31;
    case 10:
      dayOfYear += 30;
    case 9:
      dayOfYear += 31;
    case 8:
      dayOfYear += 31;
    case 7:
      dayOfYear += 30;
    case 6:
      dayOfYear += 31;
    case 5:
      dayOfYear += 30;
    case 4:
      dayOfYear += 31;
    case 3:
      dayOfYear += isLeapYear ? 29 : 28;
    case 2:
      dayOfYear += 31;
    case 1:
      break;
  }

  // Calculates the day of the week depending on dayOfYear and firstDay
  if ((dayOfYear % 7 + firstDay) <= 7)
    dayOfWeek = dayOfYear % 7 + firstDay;
  else
    dayOfWeek = dayOfYear % 7 + firstDay - 7;

  return dayOfWeek;
}

/******************************************************************************
 * Function:    calcDaysInMonth
 * Description: Calculates the number of days in the month
 * Parameters:  month, int, value for month
 *              isLeapYear, int, boolean value depending on if the year is a leap year
 * Return:      Integer, value of the number of days in the month
 ******************************************************************************/
int calcDaysInMonth(int month, int isLeapYear)
{
  int daysInMonth; // Value for number of days in month

  // Defines daysInMonth depending on the month and if it is a leap year
  switch (month)
  {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      daysInMonth = 31;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      daysInMonth = 30;
      break;
    case 2:
      daysInMonth = isLeapYear ? 29 : 28;
      break;
  }

  return daysInMonth;
}

/******************************************************************************
 * Function:    checkFiveOccurrences
 * Description: Determines if the day of the week occurrs 5 times in the month
 * Parameters:  firstDayOfMonth, int, value for first day of the month
 *			   dayOfWeek, int, given value for day of the week
 *			   daysInMonth, int, value for number of days in the month
 * Return:      Boolean, value corresponding to whether there are 5 occurrences or not
 ******************************************************************************/
int checkFiveOccurrences(int firstDayOfMonth, int dayOfWeek, int daysInMonth)
{
  int isFiveOccurrences; // Value of 0 or 1 depending on if there are 5 occurrences

  // Defines isFiveOccurences depending on whether there could be five occurences in the month
  if ((28 + dayOfWeek - firstDayOfMonth) < daysInMonth && dayOfWeek - firstDayOfMonth >= 0)
    isFiveOccurrences = 1;
  else
    isFiveOccurrences = 0;

  return isFiveOccurrences;
}

/******************************************************************************
 * Function:    printMonth
 * Description: Prints name of month depending on month value given
 * Parameters:  month, int, Value for month
 * Return:      void
 ******************************************************************************/
void printMonth(int month)
{
  // Prints the month name depending on the month value
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
 * Function:    printDayOfWeek
 * Description: Prints the day of the week depending on the integer value given
 * Parameters:  dayOfWeek, int, value for day of the week
 * Return:      void
 ******************************************************************************/
void printDayOfWeek(int dayOfWeek)
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
 * Function:    printOccurrences
 * Description: Prints all occurrences of the day of the week in the month
 * Parameters:  dayofweek, int, value for day of week
 *              firstDayOfMonth, int, value for first day of month
 * Return:      void
 ******************************************************************************/
void printOccurrences(int dayOfWeek, int firstDayOfMonth)
{
  int firstDate; // Value for first date the day of the week occurrs in the month
  firstDate = dayOfWeek - firstDayOfMonth + 1;

  printf("\nDates: %d %d %d %d %d\n", firstDate, firstDate + 7, firstDate + 14, firstDate + 21, firstDate + 28);
  return;
}
