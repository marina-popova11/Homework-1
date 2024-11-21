#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Stack.h"

bool createStackTest() {
    Stack* ptr = createStack();
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
    push(ptr, 3);
    push(ptr, 4);
    push(ptr, 5);

    return peek(ptr) == 5;
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

int main(void) {
    if (!createStackTest()) {
        printf("CreateStackTest is failed\n");
        return false;
    }
    if (!pushAndSizeTest()) {
        printf("PushAndSizeTest is failed\n");
        return false;
    }
    if (!popTest()) {
        printf("PopTest is failed\n");
        return false;
    }
    if (!peekTest()) {
        printf("peekTest is failed\n");
        return false;
    }
    if (!isEmptyTest()) {
        printf("IsEmptyTest is failed\n");
        return false;
    }
    if (!clearStackTest()) {
        printf("ClearStackTest is failed\n");
        return false;
    }

    printf("All tests passed\n");
    return true;
}
