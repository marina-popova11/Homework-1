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

int pop(Stack* stack) {
    Element* ptr = stack->head;
    int value = stack->head->value;
    stack->head = stack->head->next;
    free(ptr);
    return value;
}

int peek(Stack* stack) {
    return stack->head->value;
}

bool isEmpty(Stack* stack) {
    return stack->head == NULL;
}

void clearStack(Stack* stack) {
    if (stack == NULL) {
        return;
    }

    while (!isEmpty(stack)) {
        Element* head = stack->head;
        stack->head = head->next;
        free(head);
    }
}

int stackSize(Stack* stack) {
    int size = 0;
    void* ptr = stack->head;
    while (!isEmpty(stack)) {
        stack->head = stack->head->next;
        ++size;
    }
    stack->head = ptr;
    return size;
}