#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define LENGTH 20

char check(char* array);
int size(char n);
bool testCorrect();
bool testCorrect1();

int main() {
    if (testCorrect() || !testCorrect1()) {
        printf("Test is failed!\n");
        return 1;
    }

    printf("Enter the string:\n");
    char str[LENGTH];
    scanf("%s", str);

    if (check(str))
        printf("It is palindrome\n");
    else
        printf("It isnt palindrome\n");

    return 0;
}

char check(char* array) {
    if (array == NULL) {
        return false;
    }
    size_t length = strlen(array);
    char* rev = strrev(array);

    for (int i = 0; i < length; ++i) {
        for (int j = length - 1; j >= 0; --j) {
            if (size(array[i]) != size(array[j]))
                return false;
            else if (strcmp(array, rev) == 0)
                return true;

        }
    }
    return false;
}

int size(char n) {
    if (isupper((unsigned char)n))
        n = tolower((unsigned char)n);
    else
        n = toupper((unsigned char)n);
    return n;
}

bool testCorrect() {
    char line[] = "ASDdsa";
    return check(line);
}

bool testCorrect1() {
    char line[] = "AsdffdsA";
    return check(line);
}