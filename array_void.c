#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

Object increment(Object data)
{
  int *number = malloc(sizeof(int));
  *number = *(int *)data + 1;
  return number;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr new_array = malloc(sizeof(ArrayVoid));
  new_array->array =  malloc(sizeof(Object) * src->length);
  int count = 0;
  while(count < src->length)
  {
    new_array->array[count] = mapper(src->array[count]);
    count++;
  }
  new_array->length = count;
  return new_array;
}

Bool is_num_even(Object data)
{
  return !(*(int *)data % 2);
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  ArrayVoid_ptr new_array = malloc(sizeof(ArrayVoid));
  new_array->array = malloc(sizeof(Object) * src->length);

  int count = 0;
  for(int i = 0 ; i < src->length ; i++)
  {
    if(predicate(src->array[i]))
    {
    new_array->array[count] = src->array[i];
    count++;
    }
  }
  new_array->length = count;
  return new_array;
}

Object add(Object num1,Object num2)
{
  int *result = malloc(sizeof(int));
  *result = *(int *)num1 + *(int *)num2;
  return result;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  int count = 0;
  while(count < src->length)
  {
    init = reducer(init,src->array[count]);
    count++;
  }
  return init;
}