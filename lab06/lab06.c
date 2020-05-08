
/******************************************************************************
 * Assignment:  Lab 6
 * Lab Section: Friday, 11:30, LILY G428
 * Description: Takes either 3 or 5 inputs of operators and operands and evaluates
 and outputs the equation and solution
 * Programmers: Zach Williams will2051@purdue.edu
 *              Ian Flude iflude@purdue.edu
 *              Ju Ting Chen chen3277@purdue.edu
 ******************************************************************************/
#include <ctype.h>
#include <stdio.h>

int takeInput(char* opert1, char* opert2, int* num1, int* num2, int* num3);
int evalErrors(char opert1, char opert2, int num1, int num2, int num3, int isThreeInput);
int eval3(char opert, int num1, int num2);
int eval5(char opert1, char opert2, int num1, int num2, int num3);
void output3(char opert,int num1,int num2,int result);
void output5(char opert1,char opert2,int num1,int num2,int num3,int result);

int main()
{
  char opert1; // Value of first operator
  char opert2; // Value of second operator
  int num1; // Value of first operand
  int num2; // Value of second operand
  int num3; // Value of third operand
  int isThreeInput; // Value of 0 or 1 depending on number of inputs
  int isValid; // Value of 0 or 1 depending on if expression is valid
  int solution; // Value of solution of the expression

  // Takes user input and determines boolean values for later use
  isThreeInput = takeInput(&opert1, &opert2, &num1, &num2, &num3);
  isValid = evalErrors(opert1,opert2,num1,num2,num3,isThreeInput);

  // Outputs either an error or the expression and solution depending on the boolean values
  if(!isValid)
  {
    printf("\nEquation: Cannot be evaluated!\n");
  }
  else if(isThreeInput)
  {
    solution = eval3(opert1,num1,num2);
    output3(opert1,num1,num2,solution);
  }
  else
  {
    solution = eval5(opert1,opert2,num1,num2,num3);
    output5(opert1,opert2,num1,num2,num3,solution);
  }

  return 0;
}

/******************************************************************************
 * Function:    takeInput
 * Description: Takes input from the user for operators and operands and returns
 boolean value depending on how many inputs are given
 * Parameters:  *opert1, char, first operator value
 *              *opert2, char, second operator value
 *			   *num1, int, first operand value
 *			   *num2, int, second operand value
 *              *num3, int, third operand value
 * Return:      int, boolean value representing if it is 3 or 5 inputs
 ******************************************************************************/
int takeInput(char *opert1, char *opert2, int *num1, int *num2, int *num3)
{
  int isThreeInput; // Boolean value 0 or 1 depending on number of inputs

  // Takes user input for operators and operands
  printf("Enter expression -> ");
  scanf("%c %c %d", opert1, opert2, num1);

  // Takes more user input if opert2 is an operator and translates values to
  // the correct values if opert2 is meant to be an integer value
  if (!isdigit(*opert2))
  {
    scanf("%d %d", num2, num3);
    isThreeInput = 0;
  }
  else
  {
    *num2 = *num1;
    *num1 = *opert2 - 48;
    isThreeInput = 1;
  }

  return isThreeInput;
}

/******************************************************************************
 * Function:    evalErrors
 * Description: This function determines if the calculations are valid
 * Parameters:  opert1, character, this is the first operator
 opert2, character, this is the second operator
 *              num1, integer, this is the first operand 
 *              num2, integer, this is the second operand
 num3, integer, this is the third operand
 isThreeInput, integer, boolean value depending on the number of inputs
 * Return:      integer and this is a boolean value to determine if calculation is valid
 ******************************************************************************/
int evalErrors(char opert1, char opert2, int num1, int num2, int num3, int isThreeInput)
{
  int valid; // Boolean value 0 or 1 depending on validity of expression

  // If statements determine if the expression results in division by zero
  if(isThreeInput)
  {
    if((opert1 == '/' || opert1 == '%') && num2 == 0)
    {
      valid = 0;
    }
    else
      valid = 1;
  }
  else
  {
    if((opert2 == '/' || opert2 == '%') && num2 == 0)
    {
      valid = 0;
    }
    else if((opert1 == '/' || opert1 == '%') && num3 == 0)
    {
      valid = 0;
    }
    else
      valid = 1;
  }

  return valid;
}

/******************************************************************************
 * Function:    eval3
 * Description: This function calculates the solution of the input expression
 * Parameters:  opert, character, this is the operator
 *              num1, integer, this is the first operand 
 *              num2, integer, this is the second operand
 * Return:      integer and this is the total of the expression
 ******************************************************************************/
int eval3(char opert, int num1, int num2)
{
  int solution; //this is the net total

  //switch statement to calculate solution
  switch(opert)
  {
    case '-':
      solution = num1 - num2;
      break;
    case '+':
      solution = num1 + num2;
      break;
    case '*':
      solution = num1 * num2;
      break;
    case '/':
      solution = num1 / num2;
      break;
    case '%':
      solution = num1 % num2;
      break;
  }

  return solution;
}

/******************************************************************************
 * Function:    eval5
 * Description: This function evaluates the input expression and calculates the
 solution of the expression depending on the operators
 * Parameters:  opert1, character, this is the first operator
 *              opert2, character, this is the second operator
 *              num1, integer, this is the first operand
 *              num2, integer, this is the second operand
 *              num3, integer, this is the third operand             
 * Return:      integer and this is the total output of the expression
 ******************************************************************************/
int eval5(char opert1, char opert2, int num1, int num2, int num3)
{
  int solution; //this is the net total

  //switch statements to calculate solution
  switch (opert2)
  {
    case '+':
    case '-': 
      switch (opert1)
      {
        case '/':
        case '*':
        case '%':
          solution = eval3(opert1,num2,num3);
          solution = eval3(opert2,num1,solution);
          break;
        default:
          solution = eval3(opert2,num1,num2);
          solution = eval3(opert1,solution,num3);
      }
      break;
    default:
      solution = eval3(opert2,num1,num2);
      solution = eval3(opert1,solution,num3);
      break;
  }

  return solution;
}

/******************************************************************************
 * Function:    output3
 * Description: This function takes the resulting equation and prints it out
 *              when the user input is only one operator and two operands.
 * Parameters:  opert, char, operator value
 *              num1, int, first operand value
 *              num2, int, second operand value
 *              result, int, solution of evaluated expression
 * Return:      void
 ******************************************************************************/
void output3(char opert,int num1,int num2,int result)
{
  printf("\nEquation: %d %c %d = %d\n", num1, opert, num2, result);

  return;
}

/******************************************************************************
 * Function:    output5
 * Description: This function prints out the resulting equation when the user 
 *              input includes two operators and three operands.
 * Parameters:  opert1, char, this is the first user input operator.
 *              opert2, char, this is the second user input operator.
 *              num1, int, this is the first user input operand.
 *              num2, int, this is the second user input operand.
 *              num3, int, this is the third user input operand.
 *              result, int, this is the solution of the evaluated expression
 * Return:      void
 ******************************************************************************/
void output5(char opert1,char opert2,int num1,int num2,int num3,int result)
{
  //switch statements to determine output
  switch (opert2)
  {
    case '+':
    case '-': 
      switch (opert1)
      {
        case '/':
        case '*':
        case '%':
          printf("\nEquation : %d %c (%d %c %d) = %d\n", num1, opert2, num2, opert1, num3, result);
          break;
        default:
          printf("\nEquation : (%d %c %d) %c %d = %d\n", num1, opert2, num2, opert1, num3, result);
      }
      break;
    default:
      printf("\nEquation : (%d %c %d) %c %d = %d\n", num1, opert2, num2, opert1, num3, result);
  }

  return;
}  
