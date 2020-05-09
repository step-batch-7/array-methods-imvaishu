#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

typedef void (*Displayer)(void *);

void print_int(void *data)
{
  int *number = (int *)data;
  printf("%d\n",*number);
}

void print_void_array(ArrayVoid_ptr result,Displayer displayer)
{
for(int i = 0; i < result->length ; i++)
  {
  displayer(result->array[i]);
  }
  EMPTY_LINE;
}

int main(void)
{
  int *num1 = malloc(sizeof(int));
  *num1 = 1;
  int *num2 = malloc(sizeof(int));
  *num2 = 2;
  int *num3 = malloc(sizeof(int));
  *num3 = 3;
  int *num4 = malloc(sizeof(int));
  *num4 = 4;
  int *numbers[4] = {num1, num2, num3, num4};

  ArrayVoid_ptr void_array = malloc(sizeof(ArrayVoid));
  void_array->array = (Object *)&numbers[0];
  void_array->length = 4;
  int a[] = {1,2,3,4,5};
  int length = sizeof(a) / sizeof(int);
  ArrayVoid_ptr map_result = map_void(void_array, &increment);
  print_void_array(map_result, &print_int);
  return 0;
}