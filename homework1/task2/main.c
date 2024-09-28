#include <stdio.h>

void swap(int* left, int* right);

void main() {
    int firstVar = 0;
    int secondVar = 0;
    printf("Enter the first variable - \n");
    if (scanf("%d", &firstVar) != 1) {
        printf("Incorrect value\n");
        return 1;
    }

    printf("Enter the second variable - \n");
    if (scanf("%d", &secondVar) != 1) {
        printf("Incorrect value\n");
        return 1;
    }

    swap(&firstVar, &secondVar);
    printf("firstVar = %d, secondVar = %d\n", firstVar, secondVar);
}

void swap(int* left, int* right) {
    if (*left == *right) {
        return;
    }
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}
