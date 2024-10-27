#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isBalance(char* array);

int main(void) {
    char symbols[20];
    printf("Enter the string: ");
    int result = scanf("%s", symbols);

    if (isBalance(symbols)) {
        printf("It is a balance\n");
    }
    else {
        printf("Not a balance\n");
    }
    return 0;
}

bool isBalance(char *array) {
    int count = 0;
    for (int i = 0; i < strlen(array); i++) {
        if (array[i] == '(') {
            count++;
        }
        else if (array[i] == ')') {
            count--;
        }
        if (count < 0) {
            return false;
        }
    }
    if (count != 0) {
        return false;
    }
    return true;

}