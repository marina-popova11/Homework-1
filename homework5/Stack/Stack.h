#pragma once

#include <stdbool.h>

typedef struct Stack Stack;

// create stack
Stack* createStack();

//function of adding an item to the stack
bool push(Stack* stack, int value);

//function of removing an item from the stack
int pop(Stack* stack, int* errorCode);

//a function that outputs the top item on the stack
int peek(Stack* stack);

//checking the stack for emptiness
bool isEmpty(Stack* stack);

//clearing the stack
void clearStack(Stack** stack);

//getting the stack length
int stackSize(Stack* stack);