#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../Stack/Stack.h"
#define MAX 100

char* enteringLine(void);
int operators(char operand);
void infixToPostfix(const char* infix, char* postfix);

int main(void) {
    printf("Enter the string in infix:\n");
    char* inputString = enteringLine();
    char postfixString[MAX] = { 0 };
    printf("The string in postfix:\n");
    infixToPostfix(inputString, postfixString);
    printf("%s", postfixString);
    return 0;
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

    const char elements[] = "0123456789+-*/() ";
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

int operators(char operand) {
    switch (operand) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return -1;
    }
}

void infixToPostfix(const char* infix, char* postfix) {
    Stack* stack = createStack();
    if (stack == NULL) {
        return NULL;
    }

    int i = 0, j = 0;
    while (infix[i] != '\0') {
        char character = infix[i];
        switch (character) {
        case '(':
            push(stack, character);
            break;
        case ')':
            while (peek(stack) != '(') {
                char element = peek(stack);
                postfix[j] = element;
                pop(stack);
                ++j;
            }
            pop(stack);
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            if (isEmpty(stack)) {
                push(stack, character);
                break;
            }
            while (!isEmpty(stack) && operators(peek(stack)) >= operators(character)) {
                postfix[j] = pop(stack);
                ++j;
            }
            push(stack, character);
            break;
        default:
            postfix[j] = infix[i];
            ++j;
            break;
        }
        ++i;
    }
    while (!isEmpty(stack)) {
        postfix[j] = pop(stack);
        ++j;
    }
    postfix[j] = '\0';
}