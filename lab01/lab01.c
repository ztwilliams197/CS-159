/******************************************************************************
* Assignment:  Lab01
* Lab Section: Friday, 11:30, LILY G428
* Description: Calculates volume and area measurements for a frustum given
*              user input of radii, height, side
* Programmers: Zachary Williams will2051@purdue.edu
*              Soomin Kim kim2914@purdue.edu
*              Alex Rogers roger299@purdue.edu
******************************************************************************/

#include <stdio.h>

#define PI 3.14  // Constant value for Pi

int main()
{
  float upRad;   // Value for Upper Radius of frustum
  float lowRad;  // Value for Lower Radius of frustum
  float height;  // Value for Height of frustum
  float side;    // Value for Side of frustum
  float volume;  // Value for Volume of frustum
  float latArea; // Value for Lateral Surface Area of frustum
  float topArea; // Value for Top Surface Area of frustum
  float botArea; // Value for Bottom Surface Area of frustum
  float totArea; // Value for Total Surface Area of frustum

  // Prompts user for measurements of frustum and stores them in variables
  printf("Enter the value for the upper radius (r) -> ");
  scanf("%f",&upRad);
  printf("Enter the value for the lower radius (R) -> ");
  scanf("%f",&lowRad);
  printf("Enter the value for the height (h) -> ");
  scanf("%f",&height);
  printf("Enter the value for the side (s) -> ");
  scanf("%f",&side);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

  // Calculates volume of frustum 
  volume = (1.0 / 3.0) * PI * height * (upRad * upRad + (lowRad * lowRad) + (upRad * lowRad));
  
  // Calculates lateral surface area
  latArea = PI * (upRad + lowRad) * side;
  
  // Calculates top surface area
  topArea = PI * upRad * upRad;
  
  // Calculates bottom surface area
  botArea = PI * lowRad * lowRad;
  
  // Calculates total surface area
  totArea = latArea + topArea + botArea;

  // Outputs calculated values of frustum
  printf("\nVolume: %.2f",volume);
  printf("\nLateral Surface Area: %.2f",latArea);
  printf("\nTop Surface Area: %.2f",topArea);
  printf("\nBottom Surface Area: %.2f",botArea);
  printf("\nTotal Surface Area: %.2f\n",totArea);

  return 0;
}
