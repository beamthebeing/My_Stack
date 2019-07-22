//
// my_vector.h
// sickDay1 part2
//
#ifndef my_vector_h
#define my_vector_h


#include "status.h"


typedef void* MY_VECTOR; //can't be derefenced, handle to an unknown type


MY_VECTOR my_vector_init_default(void);


//change the value of element in the container
//add an element to the container
//remove an element from the container
//sort??
//view the value of the elements in the container

//destroy the object

int* my_vector_at(MY_VECTOR hVector, int index); //change a value at an index, get a value at an index
Status my_vector_pop_back(MY_VECTOR hVector); //remove item
Status my_vector_push_back(MY_VECTOR hVector, int item); //Make space
int my_vector_get_size(MY_VECTOR hVector);
int my_vector_get_capacity(MY_VECTOR hVector);
Boolean my_vector_empty(MY_VECTOR hVector);


void my_vector_destroy(MY_VECTOR* phVector);


#endif /* my_vector_h */
