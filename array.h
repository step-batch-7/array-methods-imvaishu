#ifndef __ARRAY_H
#define __ARRAY_H

typedef enum
{
  False,
  True
} Bool;

typedef int *Int_ptr;
typedef Bool *Bool_ptr;

typedef int (*Mapper)(int);
typedef Bool (*Predicate)(int);
typedef int (*Reducer)(int, int);

#define EMPTY_LINE printf("\n");

typedef struct
{
  Int_ptr array;
  int length;
} Array;

typedef Array *Array_ptr; 

int square(int a);
Bool is_even(int element);
int sum(int num1,int num2);

Array_ptr map(Array_ptr src, Mapper mapper);
Array_ptr filter(Array_ptr src, Predicate predicate);
int reduce(Array_ptr src, int init, Reducer reducer);

#endif
