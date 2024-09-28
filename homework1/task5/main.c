#include <stdio.h>
#include <string.h>

void main() {
    char symbols[] = "(())()())()";
    int count = 0;
    for (int i = 0; i < strlen(symbols); i++) {
        if (symbols[i] == '(') {
            count++;
        }
        else if (symbols[i] == ')') {
            count--;
        }
    }
    if ((count < 0) || (count > 0)) {
        printf("Not a balance\n");
    }
    else {
        printf("It is a balance\n");
    }
}