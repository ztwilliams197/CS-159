/******************************************************************************
 * Assignment:  HW 06
 * Lab Section: Friday, 11:30, LILY G428
 * Description: Takes in seed value and generates 10000 random numbers then 
 *              calculates and outputs the average and number of primes above
 *              the average
 * Programmers: Zachary Williams will2051@purdue.edu
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000

int input();
int calcMax(int seedValue);
float generate(int values[], int max);
int isPrime(int num);
int numPrimes(int values[], float avg);
int scale(int from, int to);
void output(int max, float avg, int primes);

int main()
{
  int seed; // User input seed value
  int max; // Upper range of value generation
  int genValues[SIZE]; // Array of generated values
  float avg; // Average of values
  int primes; // Number of primes within range

  // Function calls for initialization
  seed = input();
  srand(seed);
  max = calcMax(seed);

  // Only calculates and outputs average and primes if max is not 0
  if(max != 0)
  {
    avg = generate(genValues, max);
    primes = numPrimes(genValues,avg);
    output(max,avg,primes);
  }
  else
  {
    printf("\nRange for problem: 1 - 0");
    printf("\nData set with a maximum of zero cannot be analyzed.");
  }

  return 0;
}

/******************************************************************************
 * Function:    input
 * Description: Prompts user for seed value
 * Parameters:  Void
 * Return:      int, Seed value
 ******************************************************************************/
int input()
{
  int numIn; // User input

  // Input validation
  do
  {
    printf("Enter Seed Value -> ");
    scanf("%d", &numIn);

    if(numIn < 10)
      printf("\nError! Minimum seed is ten!!\n\n");
  } while (numIn < 10);

  return numIn;
}

/******************************************************************************
 * Function:    calcMax
 * Description: Calculates upper limit of generated values
 * Parameters:  seedValue, Int, Seed value
 * Return:      Int, Upper limit of generated values
 ******************************************************************************/
int calcMax(int seedValue)
{
  return rand() % seedValue;
}

/******************************************************************************
 * Function:    generate
 * Description: Generates values using limits
 * Parameters:  values, Int[], Values generated using seed
 *              max, int, upper limit of values
 * Return:      float, average of generated values
 ******************************************************************************/
float generate(int values[], int max)
{
  int i; // iterating variable
  int sum; // sum of generated values

  // Initialization
  sum = 0;

  // Generates and sums values
  for(i = 0; i < SIZE; i++)
  {
    values[i] = scale(1,max);
    sum += values[i];
  }

  return (float)sum / SIZE;
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
 * Function:    numPrimes
 * Description: Iterates through values and finds how many primes are above avg
 * Parameters:  values, Int[], Randomly generated values
 *              avg, float, Average of generated values
 * Return:      int, Number of primes above avg
 ******************************************************************************/
int numPrimes(int values[], float avg)
{
  int i; // Iterating variable
  int count; // Number of primes

  // Initialization
  count = 0;

  // Finds prime values
  for(i = 0; i < SIZE; i++)
  {
    if(isPrime(values[i]) && values[i] > avg)
      count++;
  }

  return count;
}

/******************************************************************************
 * Function:    scale
 * Description: Generates random number within range
 * Parameters:  from, Int, lower bound of range
 *              to, int, upper bound of range
 * Return:      int, Generated value
 ******************************************************************************/
int scale(int from, int to)
{
  int range; // size of range

  // calculate range
  range = to - from + 1;

  // return number within range
  return rand() % range + from;
}

/******************************************************************************
 * Function:    output
 * Description: Outputs values for range, avg, and primes
 * Parameters:  max, Int, Upper bound of range
 *              avg, float, Average value of range
 *              primes, int, number of primes above average value
 * Return:      Void
 ******************************************************************************/
void output(int max, float avg, int primes)
{
  printf("\nRange for problem: 1 - %d", max);
  printf("\nNumber of primes larger than data set average [%.1f]: %d\n", avg, primes);
}
