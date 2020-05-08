/******************************************************************************
* Assignment:  Lab02
* Lab Section: Friday, 11:30, LILY G428
* Description: Calculates max height, time to reach max height, velocity at 
               ground level, and time to reach ground level of a ball launched
               straight up from a building.
* Programmers: Zachary Williams will2051@purdue.edu
*              Soomin Kim kim2914@purdue.edu
*              Alex Rogers roger299@purdue.edu
******************************************************************************/

#include <stdio.h>
#include <math.h>

#define GRAV 9.8 // gravitational constant on earth

int main()
{
  double initH; // initial height of ball
  double initV; // initial velocity of ball
  double maxHTime; // time to reach maximum height
  double maxH; // maximum height above building
  double groundTime;  // time to reach ground level
  double groundV; // velocity at ground level
  
  // prompts user for input of initial velocity and height
  printf("Enter building height (m) -> ");
  scanf("%lf",&initH);
  printf("Enter initial velocity (m/s) -> ");
  scanf("%lf",&initV);
  
  // calculates time to reach maximum height
  maxHTime = initV / GRAV;
  
  // calculates maximum height above building
  maxH = (initV * maxHTime) - (.5 * pow(maxHTime,2) * GRAV);

  // calculates velocity at ground level
  groundV = -sqrt(pow(initV,2) + 2 * GRAV * initH);

  // calculates time to reach ground level
  groundTime = -(groundV - initV) / GRAV;
  
  // prints calculated values
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nTime to reach max height:%12.1lf seconds",maxHTime);
  printf("\nMaximum height above building:%8.1lf meters",maxH);
  printf("\nTime to reach ground level:%10.1lf seconds",groundTime);
  printf("\nVelocity at ground level:%16.1lf m/s\n",groundV);

  return 0;
}
