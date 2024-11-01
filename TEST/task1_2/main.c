#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(int number);
bool testIsPalindrome1();
bool testIsPalindrome2();

bool tests() {
    if (!testIsPalindrome1()) {
        printf("Test 1 is failed\n");
    }
    if (testIsPalindrome2()) {
        printf("Test 2 is failed\n");
    }
}

int main(void) {
    if (!tests) {
        return 1;
    }

    int number = 0;
    printf("Enter the number: ");
    scanf("%d", &number);
    if (isPalindrome(number)) {
        printf("It is palindrome.\n");
    }
    else {
        printf("It is not palindrome.\n");
    }
    return 0;
}

bool isPalindrome(int number) {
    int current = number;
    int reserved = 0;

    if (current < 0) {
        return false;
    }
    while (current != 0) {
        int element = current % 10;
        reserved = reserved * 10 + element;
        current /= 10;
    }
    return number == reserved;
}

bool testIsPalindrome1() {
    int number = 123321;
    return isPalindrome(number);
}

bool testIsPalindrome2() {
    int number = 5648792;
    return isPalindrome(number);
}
