
/******************************************************************************
* Assignment:  Lab 5
* Lab Section: Friday, 11:30, LILY G428
* Description: This program takes an integer input and puts it through a random number generator to create a random decimal number that is to be used as the length for calculating the volume and surface area of various different shapes. This is done in two functions taking the user input and generating the random number. Then, split into eight functions, the program takes the generated length and computes the surface area and volume of a right regular hexagonal prism, a right regular pentagonal prism, a cube, and a triangular prism. Then another function outputs the values.
* Programmers: Ian Flude iflude@purdue.edu
*              Ju Ting Chen chen3277@purdue.edu
*              Zachary Williams will2051@purdue.edu
******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int valueInput();
double ranNumGen(int);
void output(double);
double hexSA(double);
double pentSA(double);
double cubeSA(double);
double triSA(double);
double hexV(double);
double pentV(double);
double cubeV(double);
double triV(double);

int main(void)
{
  int seed; //This is the seed variable that the user inputs.
  double randNum; //This is the value for length that the random number generator creates.

  //Generating random number for length and outputting dimensions
  seed = valueInput();
  randNum = ranNumGen(seed);
  output(randNum);

  return 0;
}

/******************************************************************************
* Function:    valueInput
* Description: This function takes input for a seed value and returns that value.
* Parameters:  void
* Return:      int, seed value for random numbers
******************************************************************************/
int valueInput()
{
  int seedValue; // Seed value from input

  printf("Enter the seed value -> ");
  scanf("%d", &seedValue);

  return seedValue;
}

/******************************************************************************
* Function:    ranNumGen
* Description: This function takes the seed value and generates a random number
               with from 0 to 50 with a decimal to the thousandth place
* Parameters:  seed, int, this is the seed value
* Return:      double, this is the random number for length
******************************************************************************/
double ranNumGen(int seed)
{
  double randNum; // Whole number value of random number
  double randDec; // Decimal value of random number

  //Generates random number between 0 and 51 with 3 decimal places
  srand(seed);
  randNum = rand() % 51;
  randDec = (rand() % 1001) / 1000.0;

  return randNum + randDec;
}

/******************************************************************************
* Function:    output
* Description: This function takes the random number and outputs all of the
               calculated values for volume and area
* Parameters:  randNum, double, this is the random number for length
* Return:      void
******************************************************************************/
void output(double randNum)
{
  printf("\nGenerated Length: %.3lf\n", randNum);
  printf("\nShape      Surface Area   Volume");
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\n Hexagonal:%10.2lf%12.2lf", hexSA(randNum), hexV(randNum));
  printf("\nPentagonal:%10.2lf%12.2lf", pentSA(randNum), pentV(randNum));
  printf("\n      Cube:%10.2lf%12.2lf", cubeSA(randNum), cubeV(randNum));
  printf("\nTriangular:%10.2lf%12.2lf\n", triSA(randNum), triV(randNum));
}

/******************************************************************************
* Function:    hexV
* Description: This function takes the length and the formula for volume of a right regular hexagonal prism to produce the volume for it.
* Parameters:  length, double, this is the randomly generated length.
* Return:      double, this is the hexagon's volume.
******************************************************************************/
double hexV(double length)
{
  return (3 * sqrt(3) * pow(length, 3)) / 2;
}

/******************************************************************************
* Function:    pentV
* Description: This function takes the length as input and the formula for the volume of a right regular pentagonal prism to compute its volume.
* Parameters:  length, double, this is the randomly generated length value
* Return:      double, this is the pentagram's volume
******************************************************************************/
double pentV(double length)
{
  return (sqrt(5 * (5 + (2 * sqrt(5)))) * pow(length, 3)) / 4;
}

/******************************************************************************
* Function:    cubeV
* Description: This function takes the length as input and the formula for the volume of a cube to compute its volume.
* Parameters:  length, double, this is the randomly generated length value
* Return:      double, this is the cube's volume
******************************************************************************/
double cubeV(double length)
{
  return pow(length, 3);
}

/******************************************************************************
* Function:    triV
* Description: This function takes the length as input and the formula for the volume of a triangular prism to compute its volume.
* Parameters:  length, double, this is the randomly generated length value
* Return:      double, this is the cube's volume
******************************************************************************/
double triV(double length)
{
  return length * sqrt((6 * pow(length, 4)) - (3 * pow(length, 4))) / 4;
}

/******************************************************************************
* Function:    hexSA
* Description: This function takes the randomly generated length as the length
*              of all sides of a right regular hexagonal prism and calculates
*              its surface area.
* Parameters:  length, double, the length of all sides of the hexagonal prism.
* Return:      double, the surface area of the right regular
*              hexagonal prism.
******************************************************************************/
double hexSA(double length)
{
  return 6 * pow(length, 2) + (3 * sqrt(3) * pow(length, 2));
}

/******************************************************************************
* Function:    pentSA
* Description: This function calculates the surface area of the right regular
*              pentagonal prism from the randomly generated side length
* Parameters:  length, double, the randomly calculated length used as the side
*              length of the right regular pentagonal prism.
* Return:      double, the surface area of the right regular
*              pentagonal prism.
******************************************************************************/
double pentSA(double length)
{
  return 5 * pow(length, 2) + ((1 / 2.0) * sqrt(5 * (5 + 2 * sqrt(5))) * pow(length, 2));
}

/******************************************************************************
* Function:    cubeSA
* Description: brief description of what the function does
* Parameters:  length, double, the length of each side of the cube generated
*              by the random number generator.
* Return:      double, the surface area calculated of the cube
******************************************************************************/

double cubeSA(double length)
{
  return 6 * pow(length, 2);
}

/******************************************************************************
* Function:    triSA
* Description: This function calculates the surface area of the triangular prism
*              using the length generated randomly.
* Parameters:  length, double, the length of each side of the triangular prism
*              generated by the random number generator.
* Return:      double, the surface area of the triangular prism.
******************************************************************************/
double triSA(double length)
{
  return 3 * pow(length, 2) + (0.5 * sqrt(3 * pow(length, 4)));
}

