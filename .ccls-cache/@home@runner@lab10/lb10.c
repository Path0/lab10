#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void seedInput();
//int *generate();
void generateValues(int*, int*);
void setValue(int*, int, int);
int getValue(int*, int);

int distance(int, int, int, int);
double shortestDistance(int*, int*);
int horizontal(int []);

int main(void) {
  int xVals[500];
  int yVals[500];
  int *xValues;
  int *yValues;

  xValues = xVals;
  yValues = yVals;

  seedInput();
  generateValues(xValues, yValues);

  int index;
  for(index = 0; index < 10; index++)
  {
    printf("%d\n", getValue(xValues, index));
    printf("%d\n", getValue(yValues, index));
  }

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

/*
int * generate()
{
  static int xValues[500];
  int index;
  int i;

  for(index = 0; index < 500; index++)
  {
      xValues[index] = (rand() % 201) - 100;
      yvales[index] = 
  }

  for(i=0; i < 10; i++)
  {
    printf("%d\n", xValues[i]);
  }
  return xValues;
}
*/

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

int horizontal(int xValues[])
{
  int intital;
  int compare;
  int count;

  for(intital = 0; intital < 500; intital++)
  {
    for(compare = 0; compare < 500; compare++)
    {
      if(xValues[intital] == xValues[compare])
      {
        count += 1;
      }
    }
    count -= 1;
  }
  return(count);
}

int distance(int x1, int y1, int x2, int y2)
{
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double shortestDistance(int *xValues, int *yValues)
{
  int index;
  int indexInner;
  int currentX;
  int currentY;
  int testX;
  int testY;
  int currentDistance;
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

