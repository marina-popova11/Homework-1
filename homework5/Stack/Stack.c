#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Stack.h"

typedef struct Element {
    int value;
    struct Element* next;
} Element;

typedef struct Stack {
    Element* head;
} Stack;

Stack* createStack() {
    return calloc(1, sizeof(Stack));
}

bool push(Stack* stack, int value) {
    Element* element = calloc(1, sizeof(Element));
    if (element == NULL) {
        return false;
    }
    element->value = value;
    element->next = stack->head;
    stack->head = element;
    return true;
}

int pop(Stack* stack, int* errorCode) {
    if (stack->head == NULL) {
        *errorCode = -1;
        return -1;
    }
    errorCode = 0;
    Element* ptr = stack->head;
    int value = stack->head->value;
    stack->head = stack->head->next;
    free(ptr);
    return value;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->head->value;
}

bool isEmpty(Stack* stack) {
    if (stack == NULL) {
        return true;
    }
    return stack->head == NULL;
}

void clearStack(Stack** stack) {
    Stack* tmpStack = *stack;
    while (isEmpty(*stack)) {
        int errorCode = 0;
        pop(*stack, &errorCode);
        if (errorCode < 0) {
            break;
        }
    }
    free(tmpStack);
    *stack = NULL;
}

int stackSize(Stack* stack) {
    int size = 0;
    Element* ptr = stack->head;
    while (!isEmpty(stack)) {
        stack->head = stack->head->next;
        ++size;
    }
    stack->head = ptr;
    return size;
}