#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int * generate();
int getValue(int*, int);

int main(void) {
  int *xValues;
  int *yValues;

  xValues = generate();


  int x;
  for(x = 0; x < 10; x++)
    {
      printf("%d", getValue(xValues, x));
    }
  
  return 0;
}

int * generate()
{
  int xValues[500];
  int index;

  for(index = 0; index < 500; index++)
  {
      xValues[index] = (rand() % 201) - 100;
  }

  return xValues;
}

int getValue(int *array, int index)
{
  return *(array + index);
}