#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Stack.h"

typedef struct Element {
    int value;
    struct Element* next;
}Element;

typedef struct Stack {
    Element* head;
} Stack;

Stack* createStack() {
    Stack* ptr = calloc(1, sizeof(Stack));
    if (ptr == NULL) {
        exit(1);
    }
    return ptr;
}

void push(Stack* stack, int value) {
    Element* element = calloc(1, sizeof(Element));
    if (element == NULL) {
        exit(1);
    }
    element->value = value;
    element->next = stack->head;
    stack->head = element;
}

int pop(Stack* stack) {
    if (stack->head == NULL) {
        exit(1);
    }
    Element* ptr = stack->head;
    int value = stack->head->value;
    printf("Deleted: %d\n", stack->head->value);
    stack->head = stack->head->next;
    free(ptr);
    return value;
}

int peek(Stack* stack) {
    if (isEmpty(stack->head)) {
        exit(1);
    }
    int value = stack->head->value;
    return value;
}

bool isEmpty(Stack* stack) {
    return stack->head == NULL;
}

void clearStack(Stack* stack) {
    while (!isEmpty(stack)) {
        void* ptr = stack->head->next;
        free(stack->head);
        stack->head = ptr;
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