//
//  stack.c
//  feb11
//
//  Created by Dylan Bennett on 2/13/19.
//  Copyright © 2019 Dylan Bennett. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "my_vector.h"

struct stack
{
    MY_VECTOR hVector;
};
typedef struct stack Stack;



STACK stack_init_default(void)
{
    Stack* pStack;
    
    pStack = (Stack*)malloc(sizeof(Stack));
    if (pStack != NULL)
    {
        pStack->hVector = my_vector_init_default();
        if (pStack->hVector == NULL)
        {
            free(pStack);
            return NULL;
        }
    }
    return pStack;
}



Status stack_push(STACK hStack, int item)
{
    Stack* pStack = (Stack*)hStack;
    
    return my_vector_push_back(pStack->hVector, item);
}



Status stack_pop(STACK hStack)
{
    Stack* pStack = (Stack*)hStack;
    
    return my_vector_pop_back(pStack->hVector);
}



Boolean stack_empty(STACK hStack)
{
    Stack* pStack = (Stack*)hStack;
    
    return my_vector_empty(pStack->hVector);
}




//Status stack_top(STACK hStack, int* pValue);
int stack_top(STACK hStack, Status* pStatus)
{
    Stack* pStack = (Stack*)hStack;
    if (stack_empty(hStack))
    {
        if (pStatus != NULL)
        {
            *pStatus = FAILURE;
        }
        return -1337;
    }
    if (pStatus != NULL)
    {
        *pStatus = SUCCESS;
    }
    return *(my_vector_at(pStack->hVector,
                          my_vector_get_size(pStack->hVector) - 1));
}




void stack_destroy(STACK* phStack)
{
    Stack* pStack = (Stack*)*phStack;
    my_vector_destroy(&(pStack->hVector));
    free(pStack);
    *phStack = NULL;
}
