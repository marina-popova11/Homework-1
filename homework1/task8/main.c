#include <stdio.h>
#define ARRAY_SIZE 10

void flip(int start, int end, int* array);
void swap(int start, int border, int end, int* array);

void printArray(int array[], int length) {
    for (int i = 0; i < length; i++)
        printf("%d", array[i]);
    printf("\n");
}

void main() {
    printf("Enter array (10 elements) to flip: ");
    int array[ARRAY_SIZE] = { 0 };
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Incorrect value\n");
            return 1;
        }
    }
    printf("\n");

    printf("Enter the length of the first part of the array: ");
    int m = 0;
    if (scanf("%d", &m) != 1) {
        printf("Incorrect value\n");
        return 1;
    }

    if (m > ARRAY_SIZE) {
        printf("The length of first part is greater than array length\n");
        return 1;
    }

    printf("\n");
    swap(0, m, ARRAY_SIZE - 1, array);
    printArray(array, ARRAY_SIZE);
}

void flip(int start, int end, int* array) {
    for (int i = start; i < (start + end + 1) / 2; i++) {
        int var = array[i];
        array[i] = array[end + start - i];
        array[end + start - i] = var;
    }
}

void swap(int start, int border, int end, int* array) {
    flip(start, border - 1, array);
    flip(border, end, array);
    flip(start, end, array);
}

