#ifndef __ARRAY_H
#define __ARRAY_H

typedef enum
{
  False,
  True
} Bool;

typedef int *Int_ptr;
typedef Bool *Bool_ptr;

typedef Int_ptr Mapper(int);
typedef Bool Predicate(int);
typedef Int_ptr Reducer(int, int);

typedef struct
{
  Int_ptr array;
  int length;
} Array;

typedef Array *Array_ptr; 

Int_ptr square(int a);
Bool is_even(int element);

Array_ptr map(Array_ptr src, Mapper mapper);
Array_ptr filter(Array_ptr src, Predicate predicate);
int reduce(Array_ptr src, int init, Reducer reducer);

#endif
