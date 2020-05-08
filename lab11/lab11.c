/******************************************************************************
 * Assignment:  Lab 11
 * Lab Section: Friday, 11:30, Lily G428
 * Description: This program will create a data set of 5000 values, sort them according to value of digit sum, and print the indicated number of values. 
 * Programmers: Naomi Frank frank73@purdue.edu
 *              Zachary Williams will2051@purdue.edu
 *              Mehmet Karatoprak mkaratop@purdue.edu
 ******************************************************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5000

//Function Declarations
int seedval(void);
int printnum(void);
void generateVals(int nums[]);
void sort(int nums[]);
int sumDigits(int num);
void swap(int* num1, int* num2);
void prints(int, int array[]);

int main()
{
  //Local Declarations
  int seeds; //the seed value
  int print; //the number of values to print
  int nums[SIZE]; //Array of randomly generated values

  //Statements
  seeds = seedval();
  print = printnum();
  srand(seeds);
  generateVals(nums);
  sort(nums);
  prints(print, nums);

  return 0;

}

/******************************************************************************
 * Function:    seedval
 * Description: accepts input for the seed value and validates the number
 * Parameters:  
 * Return:      seed, int, the seed value 
 ******************************************************************************/
int seedval(void)
{
  //Local Declarations
  int seed; //the seed value

  //Statements
  do
  {
    printf("Enter desired seed value -> ");
    scanf("%d", &seed);
    if (seed < 1)
      printf("\nError! Minimum seed value is one!!\n\n");
  }while(seed < 1);

  return seed;
}

/******************************************************************************
 * Function:    printnum
 * Description: accepts and validates input containing the print number
 * Parameters:  
 * Return:      int, prints, the number of numbers to print
 ******************************************************************************/
int printnum(void)
{
  //Local Declarations
  int prints; //the number of values to print

  //Statements
  do
  {
    printf("Enter number of smallest and largest values to print -> ");
    scanf("%d", &prints);
    if (prints > 100)
      printf("\nError! Maximum number to print is one hundred!!\n\n");
    else if (prints < 1)
      printf("\nError! Minimum number to print is one!!\n\n");
  }while(prints > 100 || prints < 1);

  return prints;
}

/******************************************************************************
 * Function:    generateVals
 * Description: Generates 5000 random values between the range 1 - 5000 and stores
 *              them in an array
 * Parameters:  nums, int[], Holds 5000 randomly generated values
 * Return:      Void
 ******************************************************************************/
void generateVals(int nums[])
{
  int i; // Iterating variable

  // Generates 5000 values and stores them in nums
  for (i = 0; i < SIZE; i++)
  {
    nums[i] = rand() % SIZE + 1;
  }

  return;
}

/******************************************************************************
 * Function:    sort
 * Description: Sorts the array depending on the sum of digits and the magnitude
 * Parameters:  nums, int[], Holds 5000 randomly generated values
 * Return:      Void
 ******************************************************************************/
void sort(int nums[])
{
  int i; //Iterating variable
  int j; //Iterating variable

  //Iterates values and swaps them if it is required
  for (i = 0; i < SIZE; i++)
  {
    for (j = SIZE - 1; j > i; j--)
    {
      if (sumDigits(nums[j]) < sumDigits(nums[j - 1]))
        swap(&nums[j], &nums[j - 1]);
      else if (sumDigits(nums[j]) == sumDigits(nums[j - 1]) && nums[j] < nums[j - 1])
        swap(&nums[j], &nums[j - 1]);
    }
  }

  return;
}

/******************************************************************************
 * Function:    sumDigits
 * Description: Finds sum of the digits of the number
 * Parameters:  num, int, number from array
 * Return:      int, sum of digits
 ******************************************************************************/
int sumDigits(int num)
{
  int sum; // Sum of digits

  //Variable initialization
  sum = 0;

  //Iterates through and adds up digits
  while (num > 0)
  {
    sum += num % 10;
    num /= 10;
  }

  return sum;
}

/******************************************************************************
 * Function:    swap
 * Description: Swaps two numbers
 * Parameters:  num1, int*, first value address
 *              num2, int*, second value address
 * Return:      void
 ******************************************************************************/
void swap(int* num1, int* num2)
{
  int temp; //Holds value to use later

  //Swaps values of num1 and num2
  temp = *num1;
  *num1 = *num2;
  *num2 = temp;

  return;
}
/******************************************************************************
 * Function:    prints
 * Description: accepts and validates input containing the print number
 * Parameters:
 * Return:     void 
 ******************************************************************************/
void prints(int MaxElement, int array[])
{
  int ElementNumber; //iterating variable

  //Prints out the number specified of the first values of the array
  printf("\nSmallest sum of digits: ");
  for (ElementNumber = 0; ElementNumber < MaxElement; ElementNumber++)
  {
    if(ElementNumber < MaxElement - 1)
      printf("%d, ", array[ElementNumber]);
    else
      printf("%d", array[ElementNumber]);
  }

  //Prints out the number specified of the last values of the array
  printf("\nLargest sum of digits: ");
  for (ElementNumber = SIZE - MaxElement - 1; ElementNumber < SIZE; ElementNumber++)
  {
    if(ElementNumber < SIZE - 1)
      printf("%d, ", array[ElementNumber]);
    else
      printf("%d", array[ElementNumber]);
  }
  printf("\n");

  return;
}
