/******************************************************************************
 * Assignment:  Lab 12
 * Lab Section: Friday, 11:30, Lily G428
 * Description: This program will accept a data set size, search within a smaller
 *              data set, and ouput the values.
 * Programmers: Naomi Frank frank73@purdue.edu
 *              Zachary Williams will2051@purdue.edu
 *              Mehmet Karatoprak mkaratop@purdue.edu
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

// Function declarations
int datainput();
int maxval();
void generate(int* smallSet, int* largeSet, int max, int size);
void sort(int* dataSet, int size);
void swap(int* num1, int* num2);
void output(int* smallSet, int* largeSet, int size);
int search(int* data, int target, int size);

int main()
{
  int* largeSet; // Large number set
  int* smallSet; // Small number set
  int size; // Size of large number set (10x Small set size)
  int max; // Max int value generated

  // Gathers user input and allocates memory for the number sets
  size = datainput();
  max = maxval();
  srand(max);
  largeSet = (int*)malloc(sizeof(int) * size);
  smallSet = (int*)malloc(sizeof(int) * (size / 10));

  // Generates values for number sets and sorts each set
  generate(smallSet, largeSet, max, size);
  sort(largeSet, size);
  sort(smallSet, size / 10);

  // Outputs the numbers found in both sets
  output(smallSet, largeSet, size);

  // Frees memory allocated earlier
  free(largeSet);
  free(smallSet);

  return 0;
}

/******************************************************************************
 * Function:    datainput
 * Description: function accepts input for the size of the larger data set
 * Parameters:  none
 * Return:      set, int, the size of the larger data set
 ******************************************************************************/
int datainput()
{
  //Local Declarations
  int size; //the size of the larger data set

  //Accepts input for size of large data set with validation
  do
  {
    printf("Enter size of larger data set -> ");
    scanf("%d", &size);
    if (size < 10)
      printf("\nError! Minimum size for larger data set is ten!\n");
  } while (size < 10);

  return size;
}

/******************************************************************************
 * Function:    maxvalinput
 * Description: function accepts input for the max value
 * Parameters:
 * Return:      maxval, int, the maximum value of the data set
 ******************************************************************************/
int maxval()
{
  //Local Declarations
  int maxval; //the max value of the data set

  //Accepts input for max value with validation
  do
  {
    printf("Enter maxmimum value of the data set -> ");
    scanf("%d", &maxval);
    if (maxval < 1)
      printf("\nError! Maximum value of data set must be at least one!\n");
  } while (maxval < 1);

  return maxval;
}

/******************************************************************************
 * Function:    generate
 * Description: Generates random values to fill the large and small number sets
 * Parameters:  smallSet, int*, Small number set allocated in main
 *              largeSet, int*, Large number set allocated in main
 *              max, int, Max random value to be generated
 *              size, int, Size of large number set
 * Return:      Void
 ******************************************************************************/
void generate(int* smallSet, int* largeSet, int max, int size)
{
  int i; // iterating variable

  // Generates vals of small set
  for (i = 0; i < size / 10; i++)
    smallSet[i] = rand() % max + 1;

  // Generates vals of large set
  for (i = 0; i < size; i++)
    largeSet[i] = rand() % max + 1;

  return;
}

/******************************************************************************
 * Function:    sort
 * Description: Sorts the array depending on the magnitude
 * Parameters:  dataSet, int*, Holds variable number of integers
 *			   size, int, size of dataSet
 * Return:      Void
 ******************************************************************************/
void sort(int* dataSet, int size)
{
  int i; // iterating variable
  int j; // iterating variable

  //Iterates values and swaps them to sort the array
  for (i = 0; i < size; i++)
  {
    for (j = size - 1; j > i; j--)
    {
      if (dataSet[j] < dataSet[j - 1])
        swap(&dataSet[j], &dataSet[j - 1]);
    }
  }

  return;
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
 * Function:    output
 * Description: Either outputs all values found in both sets or that no values 
 *              were found
 * Parameters:  smallSet, int*, Small set of numbers generated randomly
 *              largeSet, int*, Large set of numbers generated randomly
 *              size, int, size of larger number set
 * Return:      Void
 ******************************************************************************/
void output(int* smallSet, int* largeSet, int size)
{
  int valFound; // Prev value found
  int outStart; // Flag for output
  int i; // Iterating variable

  //Variable initialization
  valFound = 0;
  outStart = 0;

  // Outputs the values found in both sets only if there are values found
  printf("\n");
  for (i = 0; i < size / 10; i++)
  {
    if (valFound != smallSet[i])
    {
      valFound = search(largeSet, smallSet[i], size);

      if (!outStart && valFound)
      {
        printf("Values of smaller set found in the larger set:");
        outStart = 1;
      }

      if (valFound)
        printf(" %d", valFound);

      if (valFound != smallSet[size / 10 - 1] && valFound)
        printf(",");
    }
  }

  // If values are not found, print that no results were found in both sets
  if (!outStart)
    printf("Result: No values of the smaller set are found in the larger set.");

  printf("\n");

  return;
}

/******************************************************************************
 * Function:    Search
 * Description: Binary search that returns the number searched for if it is found
 * Parameters:  data, int*, Number set that will be searched
 *              target, int, Value to be searched for
 *              size, int, Size of data
 * Return:      Int either 0 if value was not found or the target if value is found
 ******************************************************************************/
int search(int* data, int target, int size)
{
  int first; // First index value searched within
  int mid; // Middle index value between first and last
  int last; // Last index value searched within
  int valFound; // 0 if not found and target if found

  // Initializations
  first = 0;
  valFound = 0;
  last = size - 1;

  // Searches within data while changing the index range
  while (first <= last)
  {
    mid = (first + last) / 2;
    if (target > data[mid])
    {
      first = mid + 1;
    }
    else if (target < data[mid])
    {
      last = mid - 1;
    }
    else
    {
      first = last + 1;
    }
  }

  // Sets valFound as target if the value arrived on is the target
  if (data[mid] == target)
  {
    valFound = target;
  }

  return valFound;
}
