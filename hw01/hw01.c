/******************************************************************************
* Assignment:  Homework 01
* Lab Section: Friday, 11:30 AM, LILY G428
* Description: Given inputs of hours and minutes in 24 hour format, the program
*              calculates and outputs the equivalent time in metric format
* Programmers: Zachary Williams will2051@purdue.edu
******************************************************************************/

#include <stdio.h>

#define MIN_DAY 1440 //Number of Minutes in a day in 24 hour format

int main()
{
  int stndHr;        //Standard 24 hr hour value
  int stndMin;       //Standard 24 hr minute value
  int totalStndMin;  //Total minutes in 24 hour format, used to calculate metric time
  int metHr;         //Metric hour value
  int metMin;        //Metric minute value
  int totalMetMin;   //Total minutes in metric format, used to calculate metric hours and minutes

  //Prompt user to enter hour and minute and store values in variables
  printf("Enter hour [0-23] -> ");
  scanf("%d",&stndHr);
  printf("Enter minute [0-59] -> ");
  scanf("%d",&stndMin);

  //Calculate the total number of minutes that have passed in standard time
  totalStndMin = stndHr * 60 + stndMin;

  //Calculate the total number of minutes that have passed in metric time
  totalMetMin = totalStndMin * 1000 / MIN_DAY;

  //Calculate metric hours and minutes using totalMetMin 
  metHr = totalMetMin / 100;
  metMin = totalMetMin % 100;

  //Prints out the Standard Time using leading 0 depending on hr and min value
  printf("\n-=-=-=-=-=-=-=-=-=-");
  printf("\nGiven Time: %d%d-%d%d",stndHr/10,stndMin%10,stndMin);

  //Prints Metric Time using leading 0 depending on minutes
  printf("\nMetric Time: 0%d-%02d",metHr,metMin);
  printf("\n-=-=-=-=-=-=-=-=-=-\n");

  return 0;
}
