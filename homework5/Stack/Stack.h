#pragma once

#include <stdbool.h>

typedef struct Stack Stack;

Stack* createStack();

bool push(Stack* stack, int value);

int pop(Stack* stack);

int peek(Stack* stack);

bool isEmpty(Stack* stack);

void clearStack(Stack* stack);

int stackSize(Stack* stack);