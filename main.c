//
//  main.c
//  feb11
//
//  Created by Dylan Bennett on 2/13/19.
//  Copyright © 2019 Dylan Bennett. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "my_vector.h"
#include "status.h"

int main(int argc, char * argv[])
{
    STACK hStack;
    int i;
    
    hStack = stack_init_default();
    if (hStack == NULL)
    {
        printf("Failed to allocate space for stack.\n");
        exit(1);
    }
    
    for (i = 0; i < 10; i ++)
    {
        stack_push(hStack, i);
    }
    
    while(!stack_empty(hStack))
    {
        printf("Top = %d\n", stack_top(hStack, NULL));
        stack_pop(hStack);
    }
    
    stack_destroy(&hStack);
    return 0;
}


//push pop empty and top
