#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Stack.h"

bool createStackTest() {
    Stack* ptr = createStack;
    return ptr != NULL;
}

bool pushAndSizeTest() {
    Stack* ptr = createStack();
    push(ptr, 1);
    push(ptr, 2);
    return stackSize(ptr) == 2;
}

bool popTest() {
    Stack* ptr = createStack();
    push(ptr, 3);
    push(ptr, 4);
    push(ptr, 5);

    pop(ptr);
    pop(ptr);
    return pop(ptr) == 3;
}

bool peekTest() {
    Stack* ptr = createStack();
    push(ptr, 1);
    push(ptr, 2);
    push(ptr, 3);
    return peek(ptr) == 3;
}

bool isEmptyTest() {
    Stack* ptr = createStack();
    push(ptr, 1);
    push(ptr, 2);
    push(ptr, 3);
    push(ptr, 4);

    while (!isEmpty(ptr)) {
        pop(ptr);
    }
    return isEmpty(ptr);
}

bool clearStackTest() {
    Stack* ptr = createStack();
    push(ptr, 1);
    push(ptr, 2);
    push(ptr, 3);
    push(ptr, 4);

    clearStack(ptr);
    return isEmpty(ptr);
}