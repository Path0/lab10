/*****+******-**-*------*-*-**-------*-*****--******************************
*
*  Lab #: 10
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: Randomly generates an array of 500 x and y values,
*  and finds the longest straight-line distance between any two points,
*  how many vertical lines there are, and how many horizontal lines there are.
*
******+******-**-*------*-*-**-------*-*****--*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAYSIZE 500

void seedInput();
void generateValues(int*, int*);
void setValue(int*, int, int);
int getValue(int*, int);
double distance(int, int, int, int);
double longestDistance(int*, int*);
int equalValues(int [], int []);
void output(double, int, int);

int main(void) 
{
  int xVals[ARRAYSIZE]; // array of x values 
  int yVals[ARRAYSIZE]; // array of y values
  
  double distance; // longest distance between two points
  int verticalLines; // amount of vertical lines able to be made using given points
  int horizontalLines; // amount of horizontal lines able to be made using given points

  // gets inputs and assigns x and y values
  seedInput();
  generateValues(xVals, yVals);

  // calculates distance and line amounts
  distance = longestDistance(xVals, yVals);
  verticalLines = equalValues(xVals, yVals);
  horizontalLines = equalValues(yVals, xVals);

  output(distance, horizontalLines, verticalLines);
  
  return 0;
}

/*****+***-**-**-*------*-*-**-------*-*****--******************************
*
*  Function Information
*
*  Name of Function: seedInput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. N/A
*
*  Function Description: Gets user input and seeds the random function. Checks
*  if the seed input is positive and if it is not asks the user to enter 
*  an input that is.
*
******+***-**-**-*------*-*-**-------*-*****--*****************************/
void seedInput()
{
  int input; // User inputed starting number 

  do // do while loop goes until user inputs something correct
  {
    printf("Enter seed value -> ");
    scanf("%d",&input);

    if (input < 1)
    {
      printf("\nError! Positive seed values only!!\n\n");
    }
  }while(input < 1);

  srand(input);

  return;
}

/*****+***-**-**-*------*-*-**-------*-*****--******************************
*
*  Function Information
*
*  Name of Function: generateValues
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *xValues // pointer to the first element of the array of x values
*    2. int *yValues // pointer to the first element of the array of y values
*
*  Function Description: Generates random values between -100 and 100
*  and stores them in the x and y value arrays
*
******+***-**-**-*------*-*-**-------*-*****--*****************************/
void generateValues(int *xValues, int *yValues)
{
  int index; // index value for the for loop
  int randomValue; // random value to assign to x and/or y
  for(index = 0; index < ARRAYSIZE; index++)
  { 
    // generates x value then y value, repeat
    randomValue = (rand() % 201) - 100;
    setValue(xValues, index, randomValue);
        
    randomValue = (rand() % 201) - 100;
    setValue(yValues, index, randomValue);
  }  
}

/*****+***-**-**-*------*-*-**-------*-*****--******************************
*
*  Function Information
*
*  Name of Function: getValue
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *array // array pointer to get the value of
*    2. int index // index in the array to get the value of
*
*  Function Description: Returns the value in the index position of the given array
*
******+***-**-**-*------*-*-**-------*-*****--*****************************/
int getValue(int *array, int index)
{
  return * (array + index); // aka array[index] but with pointers
}

/*****+***-**-**-*------*-*-**-------*-*****--******************************
*
*  Function Information
*
*  Name of Function: setValue
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *array // array to use to set the value in
*    2. int index // index of the array to set the value of
*    3. int value // value to set the index of array to
*
*  Function Description: Sets the value of the index in a specified array to 
*  a value passed into the function
*
******+***-**-**-*------*-*-**-------*-*****--*****************************/
void setValue(int *array, int index, int value)
{
  * (array + index) = value; // aka array[index] = value; but with pointers
}

/*****+***-**-**-*------*-*-**-------*-*****--******************************
*
*  Function Information
*
*  Name of Function: equalValues
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int values[] // array of values to check for equality
*    2. int altValues[] // array of alternate values to check for duplicates
*
*  Function Description: Given an array of values, finds how many times the arrays
*  are equal, except the times when the alternate values equal, which results in a
*  duplicate point.
*
******+***-**-**-*------*-*-**-------*-*****--*****************************/
int equalValues(int values[], int altvalues[])
{
  int initial; //The first value in the array that is being counted
  int compare; //The value that the intial value is being compared to
  int count; // The number of times that simlar values are found

  count = 0;

  for(initial = 0; initial < ARRAYSIZE; initial++)
  {
    for(compare = 0; compare < ARRAYSIZE; compare++)
    {
      if(values[initial] == values[compare])
      {
        count += 1;
        if(altvalues[initial] == altvalues[compare])
        {
          count -= 1;
        }
      }
    }
  }
  count /= 2;
  return(count);
}

/*****+***-**-**-*------*-*-**-------*-*****--******************************
*
*  Function Information
*
*  Name of Function: distance
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int x1 // x component of the first point
*    2. int y1 // y component of the first point
*    3. int x2 // x component of the second point
*    4. int y2 // y component of the secont point
*
*  Function Description: Distance formula. 
*
******+***-**-**-*------*-*-**-------*-*****--*****************************/
double distance(int x1, int y1, int x2, int y2)
{
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

/*****+***-**-**-*------*-*-**-------*-*****--******************************
*
*  Function Information
*
*  Name of Function: longestDistance
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *xValues // array of x values
*    2. int *yValues // array of y values
*
*  Function Description: Given x and y values, finds the longest distance
*  between two points in the dataset
*
******+***-**-**-*------*-*-**-------*-*****--*****************************/
double longestDistance(int *xValues, int *yValues)
{
  int index; // outer index for the outer for loop
  int indexInner; // innder index for the inner for loop
  int currentX; // current x value to test against
  int currentY; // current y value to test against
  int testX; // x value to find the distance from it to current x
  int testY; // y value to find the distance from it to current y
  double currentDistance; // current distance to be used for checking if it's the max
  double currentMax; // maximum distance found

  currentMax = 0;

  // checks all the points and finds the distances, updates currentMax as needed
  for(index = 0; index < ARRAYSIZE; index++)
  {
    // these values are checked against all 500 of the others
    currentX = getValue(xValues, index);
    currentY = getValue(yValues, index);
    for(indexInner = 0; indexInner < ARRAYSIZE; indexInner++)
    {
      testX = getValue(xValues, indexInner);
      testY = getValue(yValues, indexInner);

      currentDistance = distance(currentX, currentY, testX, testY);

      // if the distance between these two points is greater than the max, it's the new max
      if(currentDistance > currentMax)
      {
        currentMax = currentDistance;
      }
    }
    
  }
  return currentMax;
}

/*****+***-**-**-*------*-*-**-------*-*****--******************************
*
*  Function Information
*
*  Name of Function:output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.double, distance, the largest calculated distance between two points in the data set
*    2.int, horizontal, the number of times that there is a horizontal line in the data set
*    3.
*
*  Function Description:
*
******+***-**-**-*------*-*-**-------*-*****--*****************************/
void output(double distance, int horizontal, int vertical)
{
  printf("\nMaximum Distance: %.1lf\n", distance);
  printf("Horizontal Lines: %d\n", horizontal);
  printf("Vertical Lines: %d\n", vertical);
  return;
}
