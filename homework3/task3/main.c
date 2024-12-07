#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "smartQsort.h"

#define LENGTH 100
#define LENGTH2 10
#define LENGTH3 20

void printArray(int* array, int arrayLength);
void createArray(int* array, int arrayLength);
bool testCorrect();
bool testCorrect1();

int main(void) {
    if (!testCorrect() || !testCorrect1()) {
        printf("Test is failed!\n");
        return 1;
    }

    srand(time(NULL));

    int* array = malloc(LENGTH * sizeof(int));
    if (array == NULL) {
        printf("Failed to allicated array\n");
        return 1;
    }

    printf("Sourse array:\n");
    createArray(array, LENGTH);
    printArray(array, LENGTH);

    printf("\nSorted array:\n");
    smartQuicksort(array, 0, LENGTH - 1);
    printArray(array, LENGTH);

    free(array);
    return 0;
}

void createArray(int* array, int arrayLength) {
    for (int i = 0; i < arrayLength; ++i) {
        array[i] = rand() % 30 + 1;
    }
}

void printArray(int* array, int arrayLength) {
    printf("[");
    for (int i = 0; i < arrayLength; ++i) {
        printf(" %d ", array[i]);
    }
    printf("]\n");
}

bool testCorrect() {
    int array_1[LENGTH2] = { 4, 2, 5, 3, 6, 3, 1, 7, 5, 8 };
    int sorted_array[LENGTH2] = { 1, 2, 3, 3, 4, 5, 5, 6, 7, 8 };
    sortByInserts(array_1, 0, LENGTH2 - 1);
    for (int i = 0; i < LENGTH2; ++i) {
        if (array_1[i] != sorted_array[i])
            return false;
    }
    return true;
}

bool testCorrect1() {
    int* array_2 = malloc(LENGTH3 * sizeof(int));
    if (array_2 == NULL) {
        printf("Failed to allicated array\n");
        return 1;
    }
    createArray(array_2, LENGTH3);
    smartQuicksort(array_2, 0, LENGTH3 - 1);
    for (int i = 1; i < LENGTH3; ++i) {
        if (array_2[i] >= array_2[i - 1]) {
            return true;
        }
    }
    free(array_2);
    return false;
}