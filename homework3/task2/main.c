#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 10

#include "SortAndSearch.h"

void createArray(int* array, int arrayLength);
void print_array(int* array, int arrayLength);
bool testCorrect();
bool testCorrect1();

int main() {
    if (!testCorrect() || testCorrect1()) {
        printf("Tests failed\n");
        return 1;
    }

    srand(time(NULL));

    int n = 0;
    int k = 0;

    printf("Enter the number of array elements:\n");
    int n2 = scanf("%d", &n);
    printf("\nEnter the number of items to search for (no more than 10):\n");
    int k2 = scanf("%d", &k);

    int* array = malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Failed to allicated array\n");
        return 1;
    }
    printf("\nSourse array:\n");
    createArray(array, n);
    print_array(array, n);
    printf("\n");

    smartQuicksort(array, 0, n - 1);

    int foundNumbers = 0;

    for (int i = 0; i < k; ++i) {
        int number = rand() % 30 + 1;
        if (binarySearch(array, 0, n - 1, number)) {
            printf("%d\n", number);
            foundNumbers++;
        }

    }

    printf("\n%d numbers out of %d was/were found in the array\n", foundNumbers, k);
    free(array);
    return 0;
}

void createArray(int* array, int arrayLength) {
    for (int i = 0; i < arrayLength; ++i) {
        array[i] = rand() % 30 + 1;
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
    int array_1[LENGTH] = { 1, 12, 3, 6, 7, 11, 8, 9, 10, 11 };
    return binarySearch(array_1, 0, LENGTH - 1, 7);
}

bool testCorrect1() {
    int array_1[LENGTH] = { 1, 12, 3, 6, 7, 11, 8, 9, 10, 11 };
    return binarySearch(array_1, 0, LENGTH - 1, 5);
}