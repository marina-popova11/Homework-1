#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define LENGTH 100
#define LENGTH2 10
#define LENGTH3 20

void ShellSorting(int* array, int arrayLength);
void print_array(int* array, int arrayLength);
void createArray(int* array, int arrayLength);
bool testCorrect();
bool testCorrect2();

int main() {
    if (!testCorrect() || !testCorrect2()) {
        printf("Test is failed!\n");
        return 1;
    }

    srand(time(NULL));

    int* array = malloc(LENGTH * sizeof(int));
    if (array == NULL) {
        printf("Failed to allicated array\n");
        return 1;
    }
    createArray(array, LENGTH);
    printf("Source array:\n");
    print_array(array, LENGTH);

    ShellSorting(array, LENGTH);
    printf("\nSorted array:\n");
    print_array(array, LENGTH);
    return 0;
}

void ShellSorting(int* array, int arrayLength) {
    int step;
    for (step = arrayLength / 2; step > 0; step /= 2) {
        for (int i = step; i < arrayLength; ++i) {
            for (int j = i - step; j >= 0 && array[j] > array[j + step]; j -= step) {
                int num = array[j + step];
                array[j + step] = array[j];
                array[j] = num;
            }
        }
    }
}

void createArray(int* array, int arrayLength) {
    for (int i = 0; i < arrayLength; ++i) {
        array[i] = rand() % 50 + 1;
    }
}

void print_array(int* array, int arrayLength) {
    printf("[");
    for (int i = 0; i < arrayLength; ++i) {
        printf(" %d ", array[i]);
    }
    printf("]\n");
}

bool testCorrect() {
    int array_1[LENGTH2] = { 4, 5, 2, 9, 0, 3, 1, 7, 8, 6 };
    int sorted_array[LENGTH2] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    ShellSorting(array_1, LENGTH2);
    for (int i = 0; i < LENGTH2; ++i) {
        if (array_1[i] != sorted_array[i])
            return false;
    }
    return true;
}

bool testCorrect2() {
    int* array_2 = malloc(LENGTH3 * sizeof(int));
    if (array_2 == NULL) {
        printf("Failed to allicated array\n");
        return 1;
    }

    createArray(array_2, LENGTH3);
    ShellSorting(array_2, LENGTH3);
    for (int i = 1; i < LENGTH3; ++i) {
        if (array_2[i] >= array_2[i - 1]) {
            return true;
        }
    }
    free(array_2);
}