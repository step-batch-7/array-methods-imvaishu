#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int square(int a)
{
  return a * a;
}

Array_ptr map(Array_ptr src, Mapper mapper){
  Array_ptr new_array = malloc(sizeof(Array));
  new_array->array =  malloc(sizeof(int) * src->length);
  for(int index = 0 ; index < src->length ; index++)
  {
    new_array->array[index] = mapper(src->array[index]);
  }
  new_array->length = src->length;
  return new_array;
}

Bool is_even(int element)
{
  return !(element % 2);
}

Array_ptr filter(Array_ptr src, Predicate predicate)
{
  Array_ptr new_array = malloc(sizeof(Array));
  new_array->array = malloc(sizeof(int) * src->length);
  int count = 0;
  for(int index = 0 ; index < src->length ; index++)
  {
    if(predicate(src->array[index]))
    {
    new_array->array[count] = src->array[index];
    count++;
    }
  }
  new_array->length = count;
  return new_array;
}

int sum(int num1,int num2)
{
  return num1 + num2;
}

int reduce(Array_ptr src, int init, Reducer reducer)
{
  for(int index = 0 ; index < src->length;index++)
  {
    init = reducer(init,src->array[index]);
  }
  return init;
}