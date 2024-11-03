#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

int countEntries(char* string, char* substring);

int main() {
    char string[50], secondString[50];
    printf("Enter the strung:\n");
    scanf("%s", string);

    printf("Enter the substring:\n");
    scanf("%s", secondString);

    printf("The number of occurrences: %d", countEntries(string, secondString));
    return 0;
}

int countEntries(char* string, char* substring) {
    int count = 0;
    int lengthOfString = strlen(string);
    int lengthOfSubstring = strlen(substring);
    for (int i = 0; i < (lengthOfString - lengthOfSubstring + 1); ++i) {
        bool entry = true;
        for (int j = 0; j < lengthOfSubstring; ++j) {
            if (string[i + j] != substring[j]) {
                entry = false;
                break;
            }
        }
        if (entry) {
            ++count;
        }
    }
    return count;
}