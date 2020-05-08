/******************************************************************************
 * Assignment:  Lab 10
 * Lab Section: Friday, 11:30, LILY G428
 * Description: Program takes 35 integer values and prints out the prime values
 *			   and nonprime values within the array
 * Programmers: Zachary Williams will2051@purdue.edu
 *              Naomi Frank frank73@purdue.edu
 *              Mehmet Karatoprak mkaratop@purdue.edu
 ******************************************************************************/

#include <stdio.h>
#define SIZE 35

void inputVals(int input[]);
void determinePrimes(int input[], int primes[], int nonprimes[]);
int isPrime(int num);
void output(int primes[], int nonprimes[]);

int main()
{
  int input[SIZE] = {0}; // Array of input values
  int primes[SIZE] = {0}; // Array of prime values
  int nonprimes[SIZE] = {0}; // Array of nonprime values

  // Calling input,calculation, and output functions
  inputVals(input);
  determinePrimes(input,primes,nonprimes);
  output(primes,nonprimes);

  return 0;
}

/******************************************************************************
 * Function:    isPrime
 * Description: Takes number and determines if it is prime
 * Parameters:  num, Int, Number to see if prime
 * Return:      Boolean, 0 if not prime 1 if prime
 ******************************************************************************/
void inputVals(int input[])
{
  int i; // Iterating value for for loop

  // Takes 35 integer inputs and places them in input[]
  printf("Enter 35 integers -> ");
  for(i = 0; i < SIZE; i++)
  {
    scanf("%d", &input[i]);
  }
  printf("\n");
}

/******************************************************************************
 * Function:    isPrime
 * Description: Takes array and iterates through values placing prime values in 
 *			   primes array and nonprime values in nonprimes array
 * Parameters:  input, int[], Array of input values
 *			   primes, Int[], Array of prime values
 *			   nonprimes, int[], Array of nonprime values
 * Return:      Void
 ******************************************************************************/
void determinePrimes(int input[],int primes[], int nonprimes[])
{
  int primeCounter; // Used for index of primes[]
  int nonPrimeCounter; // Used for index of nonprimes[]
  int i; // Iterating value for for loops

  //Initialization
  primeCounter = 0;
  nonPrimeCounter = 0;

  //Iterates through array and sets prime values into primes[]
  for(i = 0; i < SIZE; i++)
  {
    if(isPrime(input[i]))
    {
      primes[primeCounter] = input[i];
      primeCounter++;
    }
  }

  //Iterates through array backwards and sets nonprime values into nonprimes[]
  for (i = SIZE - 1; i >= 0; i--)
  {
    if (!isPrime(input[i]))
    {
      nonprimes[nonPrimeCounter] = input[i];
      nonPrimeCounter++;
    }
  }
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
 * Description: Takes prime and nonprime arrays and prints out all of the values
 * Parameters:  primes, Int[], Array of prime values
 *			   nonprimes, int[], Array of nonprime values
 * Return:      void
 ******************************************************************************/
void output(int primes[],int nonprimes[])
{
  int printCounter; // Counts how many times values have been printed from the array
  printCounter = 0; // Initialization

  // Prints out values in prime array stopping when there are no more prime values
  if(primes[0] != 0)
  {
    printf("\nPrime Data: ");
    while(primes[printCounter] != 0 && printCounter < SIZE)
    {
      printf("%d", primes[printCounter]);
      if(printCounter < SIZE - 1 && primes[printCounter + 1] != 0)
        printf(",");
      printf(" ");
      printCounter++;
    }
    printf("\n");
  }

  printCounter = 0; // Set value to 0 to use for nonprime

  // Prints out values in nonprime array stopping when there are no more nonprime values
  if(nonprimes[0] != 0)
  {
    printf("Non-prime Data: ");
    while(nonprimes[printCounter] != 0 && printCounter < SIZE)
    {
      printf("%d", nonprimes[printCounter]);
      if(printCounter < SIZE - 1 && nonprimes[printCounter + 1] != 0)
        printf(",");
      printf(" ");
      printCounter++;
    }
    printf("\n");
  }
}
