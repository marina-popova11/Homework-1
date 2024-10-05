#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "frequentelement.h"

#define ARRAY_LENGTH 50
#define LENGTH 10

void print_array(int* array, int arrayLength);
void createArray(int* array, int arrayLength);
bool testCorrect();

int main() {
    if (!testCorrect()) {
        printf("Test is failed\n");
        return 1;
    }

    srand(time(NULL));

    int* array = malloc(ARRAY_LENGTH * sizeof(int));
    if (array == NULL) {
        printf("Failed to allicated array\n");
        return 1;
    }

    printf("Source array:\n");
    createArray(array, ARRAY_LENGTH);
    print_array(array, ARRAY_LENGTH);
    int result = theMostFrequencyElement(array, ARRAY_LENGTH);
    printf("%d", result);

    free(array);
    return 0;
}

void print_array(int* array, int arrayLength) {
    printf("[");
    for (int i = 0; i < arrayLength; ++i)
        printf(" %d ", array[i]);
    printf("]");
    printf("\n");
}

void createArray(int* array, int arrayLength) {
    for (int i = 0; i < arrayLength; ++i) {
        array[i] = rand() % 20 + 1;
    }
}

bool testCorrect() {
    int array[LENGTH] = { 7, 2, 3, 4 ,5, 2, 7, 2, 5, 2 };
    int sorted_array[LENGTH] = { 2, 2, 2, 2, 3, 4, 5, 5, 7, 7 };
    int result1 = theMostFrequencyElement(array, LENGTH);
    return result1 == 2;
}