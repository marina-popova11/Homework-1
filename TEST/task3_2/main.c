#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100
bool testPrintFromString();
char* readAndPrintFromFile(char* string, char* stringWithoutDuplicate);

int main(void) {
    if (!testPrintFromString()) {
        printf("Test is failed\n");
        return 1;
    }
    FILE* file = fopen("fileTest.txt", "r");
    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }
    char string[MAX_LENGTH] = { '\0' };
    fscanf(file, "%s", string);
    char stringSithoutDuplicate[MAX_LENGTH] = { '\0' };
    printf("%s", readAndPrintFromFile(string, stringSithoutDuplicate));
    fclose(file);
    return 0;
}

char* readAndPrintFromFile(char* string, char* stringWithoutDuplicate) {
    int length = strlen(string);
    int j = 0;
    for (int i = 0; i < length; ++i) {
        if (string[i] == string[i - 1]) {
            continue;
        }
        else {
            stringWithoutDuplicate[j] = string[i];
            ++j;
        }
    }
    return stringWithoutDuplicate;
}

bool testPrintFromString() {
    char firstString[MAX_LENGTH] = "aasdkkkkfhhwhbbbbwh";
    char secondString[MAX_LENGTH] = { '\0' };
    if (strcmp(readAndPrintFromFile(firstString, secondString), "asdkfhwhbwh") == 0) {
        return true;
    }
    return false;
}