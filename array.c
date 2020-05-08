#include <stdlib.h>
#include "array.h"

int *square(int a)
{
  int *result = malloc(sizeof(int));
  *result = a * a;
  return result;
}

Array_ptr map(Array_ptr src, Mapper mapper){
  Array_ptr new_array = malloc(sizeof(Array));
  new_array->array =  malloc(sizeof(int) * src->length);
  for(int index = 0 ; index < src->length ; index++)
  {
    new_array->array[index] = *mapper(src->array[index]);
  }
  new_array->length = src->length;
  return new_array;
}