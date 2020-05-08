/******************************************************************************
* Assignment:  Lab 04
* Lab Section: Friday 11:30am LILY G428
* Description: Given three angles, it determines if a triangle is formed and 
               the type of triangle that is formed.
* Programmers: Zach Williams will2051@purdue.edu
*              Alex Rogers roger299@purdue.edu
*              Soomin Kim kim2914@purdue.edu
******************************************************************************/

#include <stdio.h>

int getAngle(int);
void displayResults(int,int,int,char,char);
char calcStatus(int,int,int);
int calcSameSides(int,int,int);
char calcType(int,char);

int main()
{
  int ang1; // Value for angle 1
  int ang2; // Value for angle 2
  int ang3; // Value for angle 3
  int numCalls = 1; // Number of times getAngle is called

  // gathers user input for all three angles
  ang1 = getAngle(numCalls++);
  ang2 = getAngle(numCalls++);
  ang3 = getAngle(numCalls);
  
  // outputs results of function calls
  displayResults(ang1, ang2, ang3, calcStatus(ang1, ang2, ang3), calcType(calcSameSides(ang1, ang2, ang3), calcStatus(ang1, ang2, ang3)));

  return 0;
}

/******************************************************************************
* Function:    getAngle
* Description: Function takes input for the value of an angle
* Parameters:  angleNum, int, Angle number
* Return:      int, Value of angle
******************************************************************************/
int getAngle(int angleNum)
{
  int angleValue; // value of angle input from user

  // prompts user for input
  printf("Enter angle #%d -> ", angleNum);
  scanf("%d", &angleValue);

  return angleValue;
}

/******************************************************************************
* Function:    displayResults
* Description: Function displays results for other functions
* Parameters:  angle1, int, Value of angle 1
               angle2, int, Value of angle 2
               angle3, int, Value of angle 3
               triStatus, char, Y or N if angles form a triangle
               triType, char, Type of triangle that the angles form
* Return:      void
******************************************************************************/
void displayResults(int angle1, int angle2, int angle3, char triStatus, char triType)
{
  // prints significant values
  printf("\nGiven angles [%d %d %d]", angle1, angle2, angle3);
  printf("\nTriangle Status: %c", triStatus);
  printf("\nTriangle Type: %c\n", triType);
}

/******************************************************************************
* Function:    calcStatus
* Description: Function calculates if angles form a triangle
* Parameters:  angle1, int, Value of angle 1
               angle2, int, Value of angle 2
               angle3, int, Value of angle 3
* Return:      char, Y or N depending on if angles form a triangle
******************************************************************************/
char calcStatus(int angle1, int angle2, int angle3)
{
  char triStatus; // Y or N based on if angles form a triangle or not

  // set triStatus as Y or N depending on if angles add up to 180
  triStatus = ((angle1 + angle2 + angle3) / 180) * (180 / (angle1 + angle2 + angle3)) * 89;
  triStatus += (1 - ((angle1 + angle2 + angle3) / 180) * (180 / (angle1 + angle2 + angle3))) * 78;

  return triStatus;
}

/******************************************************************************
* Function:    calcSameSides
* Description: Function calculates number of sides that are the same
* Parameters:  angle1, int, Value of angle 1
               angle2, int, Value of angle 2
               angle3, int, Value of angle 3
* Return:      int, Number of sides that are equal
******************************************************************************/
int calcSameSides(int angle1, int angle2, int angle3)
{
  int numSidesEqual; // number of sides that have same length

  // calculates the number of equivalent sides
  numSidesEqual = ((angle1 / angle2) * (angle2 / angle1) + (angle2 / angle3) * (angle3 / angle2) + (angle1 / angle3) * (angle3 / angle1) + 1);
  numSidesEqual = ((numSidesEqual / 2) * (2 / numSidesEqual) * 2 + (numSidesEqual / 4) * (4 / numSidesEqual) * 3);

  return numSidesEqual;
}

/******************************************************************************
* Function:    calcType
* Description: Function calculates the type of triangle
* Parameters:  numSameSides, int, Number of sides that are equal
               triStatus, char, Y or N depending on if angles form a triangle
* Return:      char, Type of triangle
******************************************************************************/
char calcType(int numSameSides, char triStatus)
{
  char triType; // character that returns triangle type
  
  // calculates triangle type based on number of same sides
  numSameSides = numSameSides * (triStatus / 89) * (89 / triStatus) + 1;
  triType = ((numSameSides / 1) * (1 / numSameSides) * 32) + ((numSameSides / 3) * (3 / numSameSides) * 73) + ((numSameSides / 4) * (4 / numSameSides) * 69);
  
  return triType;
}
