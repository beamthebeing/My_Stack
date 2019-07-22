//
//  my_vector.c
//  sickDay1 part 2
//

#include <stdio.h>
#include <stdlib.h>
#include "my_vector.h"
#include "status.h"

/*
 Known type; only add things that the object "needs"; Memory footprint
 */
struct my_vector
{
    /*
     private
     */
    int size; //Number of elements/items the container holds right now
    int capacity; //Number of items the vector/container CAN hold
    int* data;
};
typedef struct my_vector My_vector;

MY_VECTOR my_vector_init_default(void)
{
    My_vector* pVector;
    pVector = (My_vector*)malloc(sizeof(My_vector)); //Malloc returns address; Malloc always returns void*
    if(pVector != NULL) //typical writing this way for init functions
    {
        pVector->size = 0;
        pVector->capacity = 1;
        pVector->data = (int*) malloc(sizeof(int)*pVector->capacity);
        if (pVector->data == NULL)
        {
            free(pVector); // need this or there will be a memory leak
            return NULL;
        }
    }
    return (MY_VECTOR)pVector;
}

//make space
Status my_vector_push_back(MY_VECTOR hVector, int item)
{
    My_vector* pVector = (My_vector*)hVector;
    int*pTemp;
    
    //if there is not enough room, then make room
    if (pVector->size >= pVector->capacity)
    {
        pTemp = malloc(sizeof(int) * 2 * pVector->capacity);
        if (pTemp == NULL)
        {
            return FAILURE;
        }
        for (int i=0; i < pVector->size; i++)
        {
            pTemp[i] = pVector->data[i];
        }
        free(pVector->data);
        pVector->data = pTemp;
        pVector->capacity *= 2;
    }
    pVector->data[pVector->size] = item;
    pVector->size++;
    return SUCCESS;
}

//remove item
Status my_vector_pop_back(MY_VECTOR hVector)
{
    My_vector* pVector = (My_vector*)hVector;
    if (pVector->size <= 0)
    {
        return FAILURE;
    }
    pVector->size --;
    return SUCCESS;
}

int* my_vector_at(MY_VECTOR hVector, int index)
{
    My_vector* pVector = (My_vector*)hVector;
    if(index < 0 || index >= pVector->size)
    {
        return NULL;
    }
    return &(pVector->data[index]);
}

int my_vector_get_size(MY_VECTOR hVector)
{
    My_vector* pVector = (My_vector*)hVector;
    return pVector->size;
}
int my_vector_get_capacity(MY_VECTOR hVector)
{
    My_vector* pVector = (My_vector*)hVector;
    return pVector->capacity;
}

Boolean my_vector_empty(MY_VECTOR hVector)
{
    My_vector* pVector = (My_vector*)hVector;
    return (Boolean)(pVector->size <= 0); //Cast is not nessacary but some like it
}



void my_vector_destroy(MY_VECTOR* phVector)
{
    My_vector* pVector = (My_vector*)*phVector; //dereferncing pointer gives me the handle
    free(pVector->data);
    free(pVector);
    *phVector = NULL;
}


