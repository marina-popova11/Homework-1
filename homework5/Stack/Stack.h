#pragma once

#include <stdbool.h>

typedef struct Element Element;

typedef struct Stack Stack;

Stack* createStack();

void push(Stack* stack, int value);

int pop(Stack* stack);

int peek(Stack* stack);

bool isEmpty(Stack* stack);

void clearStack(Stack* stack);

int stackSize(Stack* stack);