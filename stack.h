//
//  stack.h
//  feb11
//
//  Created by Dylan Bennett on 2/13/19.
//  Copyright © 2019 Dylan Bennett. All rights reserved.
//

#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include "status.h"

typedef void* STACK;

STACK stack_init_default(void);

//push
Status stack_push(STACK hStack, int item);

//pop
Status stack_pop(STACK hStack);

//empty
Boolean stack_empty(STACK hStack);

//top
//Status stack_top(STACK hStack, int* pValue);
//or
int stack_top(STACK hStack, Status* pStatus);

void stack_destroy(STACK* phStack);

#endif /* stack_h */
