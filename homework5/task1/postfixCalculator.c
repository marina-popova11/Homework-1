#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../Stack/Stack.h"

bool operations(char operand, Stack* stack);
int calculator(const char* inputString);
char* enteringLine(void);
bool calculatorTest();

bool tests(void) {
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
    if (!calculatorTest()) {
        printf("calculatorTest() is failed\n");
        return false;
    }
    return true;
}

int main(void) {
    if (!tests()) {
        return -1;
    }
    printf("Enter an expression that is in a postfix form (using only characters ""0123456789+-*/""): ");
    char* inputString = enteringLine();
    printf("%s\n", inputString);
    int result = calculator(inputString);
    printf("%d\n", result);
    return 0;
}

bool operations(char operand, Stack* stack) {
    int upperElement = pop(stack);
    int bottomElement = pop(stack);

    switch (operand) {
    case '+': {
        int currentElement = bottomElement + upperElement;
        push(stack, currentElement);
        break;
    }
    case '-': {
        int currentElement = bottomElement - upperElement;
        push(stack, currentElement);
        break;
    }
    case '*': {
        int currentElement = bottomElement * upperElement;
        push(stack, currentElement);
        break;
    }
    case '/': {
        int currentElement = bottomElement / upperElement;
        push(stack, currentElement);
        break;
    }
    default: {
        printf("Such a sign is not taken into account!\n");
        return false;
    }
    }
    return true;
}

int calculator(const char* inputString) {
    Stack* stack = createStack();
    if (stack == NULL) {
        return -1;
    }
    char* currentString = inputString;
    int length = strlen(currentString);

    for (int i = 0; i < length; ++i) {
        switch (currentString[i]) {
        case '+':
            operations(currentString[i], stack);
            break;
        case '-':
            operations(currentString[i], stack);
            break;
        case '*':
            operations(currentString[i], stack);
            break;
        case '/':
            operations(currentString[i], stack);
            break;
        default:
            push(stack, currentString[i] - '0');
            break;
        }
    }
    if (stackSize(stack) == 1) {
        return peek(stack);
    }
}

char* enteringLine(void) {
    char* inputString = (char*)calloc(1, sizeof(char));
    if (inputString == NULL) {
        exit(1);
    }
    int stringLength = 0;
    int bufferSize = 1;
    while (true) {
        char oneElement = getchar();
        if (oneElement == '\n') {
            break;
        }
        if (stringLength + 1 >= bufferSize) {
            bufferSize *= 2;
            char* ptr = realloc(inputString, sizeof(char) * bufferSize);
            if (ptr == NULL) {
                return -1;
            }
            inputString = ptr;
        }
        inputString[stringLength] = oneElement;
        ++stringLength;
    }
    inputString[stringLength] = '\0';

    const char elements[] = "0123456789+-*/";
    int i = 0;
    while (inputString[i] != '\0') {
        if (strchr(elements, inputString[i]) == NULL) {
            printf("Such a symbol should not be used!\n");
            free(inputString);
            return -1;
        }
        ++i;
    }
    return inputString;
}

bool calculatorTest() {
    char string[] = "45+3-";
    return calculator(string) == 6;
}