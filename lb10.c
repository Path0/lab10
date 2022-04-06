#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
  int xVals[500];
  int yVals[500];
  double distance;
  int verticalLines;
  int horizontalLines;

  seedInput();
  generateValues(xVals, yVals);

  distance = longestDistance(xVals, yVals);
  verticalLines = equalValues(xVals, yVals);
  horizontalLines = equalValues(yVals, xVals);

  output(distance, horizontalLines, verticalLines);
  
  return 0;
}

void seedInput()
{
  int input; // User inputed starting number 

  do
  {
    printf("Enter seed value -> ");
    scanf("%d",&input);

    if (input < 1)
    {
      printf("Error! Positive seed values only!!\n\n");
    }
  }while(input < 1);

  srand(input);

  return;
}

void generateValues(int *xValues, int *yValues)
{
  int index;
  int randomValue;
  for(index = 0; index < 500; index++)
  {
    randomValue = (rand() % 201) - 100;
    //*(xValues + index) = randomValue;
    setValue(xValues, index, randomValue);
        
    randomValue = (rand() % 201) - 100;
    setValue(yValues, index, randomValue);
    //*(yValues + index) = randomValue;
  }  
}


int getValue(int *array, int index)
{
  return *(array + index);
}

void setValue(int *array, int index, int value)
{
  *(array + index) = value;
}

int equalValues(int values[], int altvalues[])
{
  int initial;
  int compare;
  int count;

  count = 0;

  for(initial = 0; initial < 500; initial++)
  {
    for(compare = 0; compare < 500; compare++)
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
    //count -= 1;
  }
  count /= 2;
  //count -= 3;
  return(count);
}

double distance(int x1, int y1, int x2, int y2)
{
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double longestDistance(int *xValues, int *yValues)
{
  int index;
  int indexInner;
  int currentX;
  int currentY;
  int testX;
  int testY;
  double currentDistance;
  double currentMax;

  currentMax = 0;

  for(index = 0; index < 500; index++)
  {
    currentX = getValue(xValues, index);
    currentY = getValue(yValues, index);
    for(indexInner = 0; indexInner < 500; indexInner++)
    {
      testX = getValue(xValues, indexInner);
      testY = getValue(yValues, indexInner);

      currentDistance = distance(currentX, currentY, testX, testY);

      if(currentDistance > currentMax)
      {
        currentMax = currentDistance;
      }
    }
    
  }
  return currentMax;
}

void output(double distance, int horizontal, int vertical)
{
  printf("\nMaximum Distance: %.1lf\n", distance);
  printf("Horizontal Lines: %d\n", horizontal);
  printf("Vertical Lines: %d\n", vertical);
  return;
}
