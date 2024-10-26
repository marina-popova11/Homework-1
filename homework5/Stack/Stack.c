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

Stack* push(Stack* stack, int value) {
    Element* element = malloc(sizeof(Element));
    if (element == NULL) {
        exit(1);
    }
    element->value = value;
    element->next = stack->head;
    stack->head = element;

    return stack->head->value;
}

int pop(Stack* stack) {
    if (stack->head == NULL) {
        exit(1);
    }
    int value;
    value = stack->head->value;
    printf("Deleted: %d\n", stack->head->value);

    Stack* ptr = stack->head;
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

//void printStack(Stack* stack) {
//    printf("Stack >");
//    while (!isEmpty(stack)) {
//        printf("%d", stack->head->value);
//        stack->head = stack->head->next;
//    }
//}

void clearStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}