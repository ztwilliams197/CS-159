/******************************************************************************
 * Assignment:  Homework 05
 * Lab Section: Friday, 11:30, LILY G428
 * Description: Takes a number, prints the first 10 factors and how many prime
 *			   factors the number has
 * Programmers: Zachary Williams will2051@purdue.edu
 ******************************************************************************/

#include <stdio.h>
#define SIZE 10

int input();
int calcFactors(int num);
int isPrime(int num);
void output();
void printFactor(int factor, int numFactor);

int main()
{
  int numIn; // Number entered by user

  // Function calls for input and output
  numIn = input();
  output(numIn);

  return 0;
}

/******************************************************************************
 * Function:    input
 * Description: Takes user input for a positive integer with input validation
 * Parameters:  None
 * Return:      Integer to be used for factor calculations
 ******************************************************************************/
int input()
{
  int numIn; //Used for user input

  // Takes user input and returns error if the value is less than 1
  do
  {
    printf("Enter a positive integer value -> ");
    scanf("%d", &numIn);

    if (numIn <= 0)
      printf("\nError! Positive values only!!\n\n");
  } while (numIn <= 0);

  return numIn;
}

/******************************************************************************
 * Function:    calcFactors
 * Description: Takes number and calculates and prints the first 10 factors
 * Parameters:  num, Int, Number to calculate factors of
 * Return:      Integer number of prime factors
 ******************************************************************************/
int calcFactors(int num)
{
  int factorRange; // Iterating variable to find factors
  int primeFactors; // Number of prime factors
  int printCounter; // Counter used for number of printed factors

  // Initialization
  primeFactors = 0;
  printCounter = 0;

  // Iterates from num/2 to 1 printing factors and determining if they are prime
  for (factorRange = num / 2; factorRange > 0; factorRange--)
  {
    if (num % factorRange == 0)
    {
      if (printCounter < SIZE)
      {
        printFactor(factorRange,printCounter);
        printCounter++;
      }

      if (isPrime(factorRange))
        primeFactors++;
    }
  }

  return primeFactors;
}

/******************************************************************************
 * Function:    isPrime
 * Description: Takes number and determines if it is prime
 * Parameters:  num, Int, Number to see if prime
 * Return:      Boolean, 0 if not prime 1 if prime
 ******************************************************************************/
int isPrime(int num)
{
  int prime; // Boolean value depending on if num is prime or not
  int count; // Iterating variable to find factor

  // Initialization
  count = 2;
  prime = 1;

  // Iterates through and determines if the number is prime
  while(count < num && prime)
  {
    if (num % count == 0)
      prime = 0;

    count++;
  }

  // If number is 2 or 3, number is prime and if num is 1 it is not prime
  if (num <= 3 && num > 1)
    prime = 1;

  if (num == 1)
    prime = 0;

  return prime;
}

/******************************************************************************
 * Function:    output
 * Description: Outputs first 10 factors and number of prime factors
 * Parameters:  num, int, Value input by user
 * Return:      Void
 ******************************************************************************/
void output(num)
{
  int primeFactors; // Number of prime factors

  // Only prints factors if num does not equal 1
  if(num != 1)
    printf("\nFactors Identified: ");

  primeFactors = calcFactors(num);
  printf("\nNumber of Prime Factors: %d\n", primeFactors);
}

/******************************************************************************
 * Function:    printFactor
 * Description: Prints the factor and prints a "," if necessary
 * Parameters:  factor, Int, Factor to print
 *              numFactor, Int, Number of factors that have been printed
 * Return:      Void
 ******************************************************************************/
void printFactor(int factor, int numFactor)
{
  printf("%d", factor);
  if (numFactor < SIZE - 1 && factor != 1)
    printf(", ");
}
