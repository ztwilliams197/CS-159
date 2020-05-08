/******************************************************************************
* Assignment:  Lab 3
* Lab Section: Friday, 11:30 am, Lily G428
* Description: Calculates the most effecient bill breakdown given two sets of 
               quantities and denominations from the user.
* Programmers: Zachary Williams will2051@purdue.edu
*              Alex Rogers roger299@purdue.edu
*              Soomin Kim kim2914@purdue.edu
******************************************************************************/
#include <stdio.h>

int main()
{
  int quant1;   // First bill quantity
  char denom1;  // Type of first bill
  int quant2;   // Second bill quantity
  char denom2;  // Type of second bill
  int totDollars;   // Total number of dollars
  int tempDollars;  // Temporary value used for calculations
  int totTwenty;    // Total number of twenties
  int totTen;       // Total number of tens
  int totFive;      // Total number of fives
  int totOne;       // Total number of Ones

  // Takes user input for dollar amounts and types
  printf("Insert first quantity and denomination -> ");
  scanf("%d %c",&quant1,&denom1);
  printf("Insert second quantity and denomination -> ");
  scanf("%d %c",&quant2,&denom2);
  
  // Converts first entry into total dollars
  totDollars = 20 * quant1 * (denom1 / 84) * (84 / denom1);
  totDollars += 10 * quant1 * (denom1 / 116) * (116 / denom1);
  totDollars += 5 * quant1 * (denom1 / 102) * (102 / denom1);
  totDollars += quant1 * (denom1 / 111) * (111 / denom1);

  // Converts second entry into total dollars
  totDollars += 20 * quant2 * (denom2 / 84) * (84 / denom2);
  totDollars += 10 * quant2 * (denom2 / 116) * (116 / denom2);
  totDollars += 5 * quant2 * (denom2 / 102) * (102 / denom2);
  totDollars += quant2 * (denom2 / 111) * (111 / denom2);

  // Calculates the number of each type of bill
  tempDollars = totDollars;
  totTwenty = tempDollars / 20;
  tempDollars %= 20;
  totTen = tempDollars / 10;
  tempDollars %= 10;
  totFive = tempDollars / 5;
  tempDollars %= 5;
  totOne = tempDollars;

  // Outputs all total values
  printf("\n-=-=-=-=-=-=-=-");
  printf("\n   Total:%6d", totDollars);
  printf("\nTwenties:%6d", totTwenty);
  printf("\n    Tens:%6d", totTen);
  printf("\n   Fives:%6d", totFive);
  printf("\n    Ones:%6d\n", totOne);

  return 0;
}
