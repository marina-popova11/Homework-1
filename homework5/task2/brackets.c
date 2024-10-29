#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../Stack/Stack.h"

char* enteringLine();
bool isBalance(const char* string);
bool isBalanceTest();

int main() {
    if (!isBalanceTest()) {
        return -1;
    }
    printf("Enter the string of brackets (using only characters \"(){}[]\"): ");
    char* inputString = enteringLine();
    if (inputString == NULL) {
        return 1;
    }

    if (isBalance(inputString)) {
        printf("It is a balance!\n");
        return 0;
    } else {
        printf("It is not a balance!\n");
        return 0;
    }
}

char* enteringLine() {
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

    const char elements[] = "(){}[]";
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

bool isBalance(const char* string) {
    Stack* stack = createStack();
    if (stack == NULL) {
        return false;
    }
    char* currentString = string;

    int length = strlen(string);
    for (int i = 0; i < length; ++i) {
        switch (currentString[i]) {
            case '(':
            case '[':
            case '{':
                push(stack, currentString[i]);
                break;
            case ')':
                if (isEmpty(stack)) {
                    printf("It is not a balance!\n");
                    return false;
                }
                if ('(' == peek(stack)) {
                    pop(stack);
                    break;
                }
            case ']':
                if (isEmpty(stack)) {
                    printf("It is not a balance!\n");
                    return false;
                }
                if ('[' == peek(stack)) {
                    pop(stack);
                    break;
                }
            case '}':
                if (isEmpty(stack)) {
                    printf("It is not a balance!\n");
                    return false;
                }
                if ('{' == peek(stack)) {
                    pop(stack);
                    break;
                }  
        }
    }
    return stackSize(stack) == 0;   
}

bool isBalanceTest() {
    char string[] = "(){}[()]";
    return isBalance(string);
}