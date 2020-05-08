#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void display_element(void *data)
{
  int *number = (int *)data;
  printf("%d\n",*number);
}

void display_result(Array_ptr result)
{
for(int i = 0; i < result->length ; i++)
  {
   display_element(&result->array[i]);
  }
}

Array_ptr create_dynamic_array(Int_ptr numbers,int length)
{
  Array_ptr new_array = malloc(sizeof(Array));
  new_array->length = length;
  new_array->array = malloc(sizeof(int) * length);
  for(int index = 0 ; index < length ; index++)
  {
    new_array->array[index] = numbers[index];
  }
  return new_array;
}


int main(void)
{
  int a[] = {1,2,3,4,5};
  int length = sizeof(a) / sizeof(int);
  Array_ptr src = create_dynamic_array(a,length);
  Array_ptr map_result = map(src,&square);
  display_result(map_result);
 
  return 0;
}