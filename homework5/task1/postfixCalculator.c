#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../Stack/Stack.h"

bool operations(char operand, Stack* stack);
int calculator(const char* inputString);
char* enteringLine(void);
bool calculatorTest();

int main(void) {
    if (!calculatorTest()) {
        return -1;
    }
    printf("Enter an expression that is in a postfix form (using only characters \"0123456789+-*/\"): ");
    char* inputString = enteringLine();
    if (inputString == NULL) {
        return 1;
    }
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
    if (!isEmpty(stack)) {
        return peek(stack);
    }
    return -1;
}

char* enteringLine(void) {
    char* inputString = (char*)calloc(1, sizeof(char));
    if (inputString == NULL) {
        return NULL;
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
                return NULL;
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
            return NULL;
        }
        ++i;
    }
    return inputString;
}

bool calculatorTest() {
    char string[] = "45+3-";
    return calculator(string) == 6;
}