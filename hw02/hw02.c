/******************************************************************************
* Assignment:  HW 2
* Lab Section: Friday, 11:30, LILY G428
* Description: Takes the coordinates of points A, B, and C as input and
               calculates and outputs the magnitudes and directions of vectors
               Q, R, and S
* Programmers: Zachary Williams will2051@purdue.edu
******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
  double aX;   //X value for point A
  double aY;   //Y value for point A
  double bX;   //X value for point B
  double bY;   //Y value for point B
  double cX;   //X value for point C
  double cY;   //Y value for point C
  double qMag; //Magnitude of vector Q
  double qDir; //Direction of vector Q
  double rMag; //Magnitude of vector R
  double rDir; //Direction of vector R
  double sMag; //Magnitude of vector S
  double sDir; //Direction of vector S

  //Prompts the user for input of the coordinates of points A, B, and C
  printf("Enter the x and y values for point A -> ");
  scanf("%lf %lf", &aX, &aY);
  printf("Enter the x and y values for point B -> ");
  scanf("%lf %lf", &bX, &bY);
  printf("Enter the x and y values for point C -> ");
  scanf("%lf %lf", &cX, &cY);

  //Calculates magnitude and direction of vectors Q, R, and S
  qMag = sqrt(pow(bX - aX,2) + pow(bY - aY,2));
  qDir = acos((bX - aX) / qMag) * 180 / M_PI;
  rMag = sqrt(pow(cX - bX,2) + pow(cY - bY,2));
  rDir = acos((cX - bX) / rMag) * 180 / M_PI;
  sMag = sqrt(pow(cX - aX,2) + pow(cY - aY,2));
  sDir = acos((cX - aX) / sMag) * 180 / M_PI;

  //Outputs magnitude and direction of all vectors
  printf("\n    Magnitude  Direction");
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nQ:%9.2lf%10.2lf deg",qMag,qDir);
  printf("\nR:%9.2lf%10.2lf deg",rMag,rDir);
  printf("\nS:%9.2lf%10.2lf deg\n",sMag,sDir);

  return 0;
}