/******************************************************************************
* Assignment:  Homework 3
* Lab Section: Friday, 11:30 AM, LILY G428
* Description: Gathers input of launch velocity, launch angle, and average
               rover speed and calculates flight time, flight range, maximum
               height, and retrieval time using user defined functions
* Programmers: Zachary Williams will2051@purdue.edu
******************************************************************************/

#include <stdio.h>
#include <math.h>

#define GRAV 9.80665

void getInput(double *vLaunch, double *angleLaunch, double *speedRover);
double calcRange(double velocity, double angle);
double calcFlightTime(double range, double velocityX);
double calcHMax(double velocityY);
double calcRetrievalTime(double range, double speed);
int calcHours(double time);
int calcMins(double time);
double calcSeconds(double time);
void outputResults(double timeFlight, double range, double hMax, double timeRetrieval);

int main()
{
  double vLaunch;    // Launch Velocity of projectile
  double angleLaunch;    // Launch Angle of projectile
  double speedRover;     // Average Speed of rover
  double timeFlight;     // Time of projectile in air
  double range;  // Flight Range of projectile
  double hMax;   // Max Height of projectile
  double timeRetrieval;  // Time for rover to retrieve projectile

  // Prompts user for input
  getInput(&vLaunch, &angleLaunch, &speedRover);

  // Calculates range, flight time, max height, and retrieval time using functions
  range = calcRange(vLaunch, angleLaunch);
  timeFlight = calcFlightTime(range, vLaunch * cos(angleLaunch * M_PI / 180));
  hMax = calcHMax(vLaunch * sin(angleLaunch * M_PI / 180));
  timeRetrieval = calcRetrievalTime(range, speedRover);

  // Outputs all calculated data
  outputResults(timeFlight, range, hMax, timeRetrieval);

  return 0;
}

/******************************************************************************
* Function:    getInput
* Description: Function takes input from user for velocity and angle of launch
*              as well as the speed of the rover
* Parameters:  vLaunch, Double, Launch Velocity of projectile
*              angleLaunch, Double, Launch Angle of projectile
*              speedRover, Double, Average Speed of rover
* Return:      Void
******************************************************************************/
void getInput(double *vLaunch, double *angleLaunch, double *speedRover)
{
  printf("Enter launch velocity (m/s) -> ");
  scanf("%lf",vLaunch);
  printf("Enter launch angle (degrees) -> ");
  scanf("%lf",angleLaunch);
  printf("Enter average speed of rover (km/h) -> ");
  scanf("%lf",speedRover);
}

/******************************************************************************
* Function:    calcRange
* Description: Function calculates range from initial velocity and angle
* Parameters:  velocity, Double, Launch Velocity of projectile
*              angle, Double, Launch Angle of projectile
* Return:      Double, Flight Range of projectile
******************************************************************************/
double calcRange(double velocity, double angle)
{
  return (pow(velocity,2) * sin(2 * angle * M_PI / 180)) / GRAV;
}

/******************************************************************************
* Function:    calcFlightTime
* Description: Function calculates flight time from range and x velocity
* Parameters:  range, Double, Flight Range of projectile
*              velocityX, Double, Velocity of projectile in x direction
* Return:      Double, Time of projectile in air
******************************************************************************/
double calcFlightTime(double range, double velocityX)
{
  return range / velocityX;
}

/******************************************************************************
* Function:    calcHMax
* Description: Function calculates max height from y velocity
* Parameters:  velocityY, Double, Velocity of projectile in y direction
* Return:      Double, Time of projectile in air
******************************************************************************/
double calcHMax(double velocityY)
{
  return pow(velocityY,2) / (2 * GRAV);
}

/******************************************************************************
* Function:    calcRetrievalTime
* Description: Function calculates retrieval time from range and rover speed
* Parameters:  range, Double, Flight Range of projectile
*              speed, Double, Average speed of rover
* Return:      Double, Time of retrieval by rover
******************************************************************************/
double calcRetrievalTime(double range, double speed)
{
  return 2 * (range / (speed * 1000 / 3600));
}

/******************************************************************************
* Function:    calcHours
* Description: Function calculates hours from total seconds
* Parameters:  time, Double, Total seconds
* Return:      int, Number of hours
******************************************************************************/
int calcHours(double time)
{
  return (int)time / 3600;
}

/******************************************************************************
* Function:    calcMins
* Description: Function calculates minutes from total seconds
* Parameters:  time, Double, Total seconds
* Return:      int, Number of minutes
******************************************************************************/
int calcMins(double time)
{
  return ((int)time % 3600) / 60;
}

/******************************************************************************
* Function:    calcSeconds
* Description: Function calculates the number of seconds after hours and minutes
* Parameters:  time, Double, Total seconds
* Return:      Double, Number of seconds
******************************************************************************/
double calcSeconds(double time)
{
  return ((int)(round(time * 10) * 10) % 6000) / 100.0;
}

/******************************************************************************
* Function:    displayResults
* Description: Function outputs all calculated values
* Parameters:  timeFlight, Double, Flight time of the projectile
*              range, Double, Horizontal distance that projectile travels
*              hMax, Double, Maximum height that projectile reaches
*              timeRetrieval, Double, Retrieval time for projectile by rover
* Return:      Double, Flight Range of projectile
******************************************************************************/
void outputResults(double timeFlight, double range, double hMax, double timeRetrieval)
{
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nFlight Time   : %d (hrs) %02d (minutes) %.1lf (seconds)", calcHours(timeFlight), calcMins(timeFlight), calcSeconds(timeFlight));
  printf("\n\nFlight Range  :%12.1lf meters", range);
  printf("\nMaximum Height:%12.1lf meters", hMax);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nRetrieval Time: %d (hrs) %02d (minutes) %.1lf (seconds)\n", calcHours(timeRetrieval), calcMins(timeRetrieval), calcSeconds(timeRetrieval));
}
