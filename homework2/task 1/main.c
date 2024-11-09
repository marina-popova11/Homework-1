#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_LENGTH 20

void halfQsort(int* array, int left, int right);
void printArray(int array[], int length);
bool testCorrect();

int main() {
    if (!testCorrect()) {
        printf("Tests failed\n");
        return -1;
    }

    srand(time(NULL));

    int* array = malloc(ARRAY_LENGTH * sizeof(int));
    if (array == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    printf("The source array:\n");
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        array[i] = rand() % 30 + 1;
    }
    printArray(array, ARRAY_LENGTH);

    halfQsort(array, 0, ARRAY_LENGTH - 1);
    printf("The sorted array:\n");
    printArray(array, ARRAY_LENGTH);

    free(array);
    return 0;
}

void printArray(int array[], int length) {
    printf("[");
    for (int i = 0; i < length; ++i) {
        printf(" %d ", array[i]);
    }
    printf("]");
    printf("\n");
}

void halfQsort(int* array, int left, int right) {
    if (left >= right) {
        return;
    }

    int firstElement = array[0];
    int i = left - 1;
    int j = right + 1;

    while (i <= j) {
        ++i;
        --j;
        while (array[i] < firstElement) {
            ++i;
        }
        while (array[j] >= firstElement) {
            --j;
        }
        if (i <= j) {
            int num = array[i];
            array[i] = array[j];
            array[j] = num;
        }
    }
}

bool testCorrect() {
    int array[ARRAY_LENGTH] = { 6, 7, 4, 5, 3, 6, 7, 2, 0, 4, 5, 2, 7, 6, 9, 11, 2, 13, 8, 3 };
    int sortedArray[ARRAY_LENGTH] = { 3, 2, 4, 5, 3, 2, 5, 2, 0, 4, 7, 6, 7, 6, 9, 11, 7, 13, 8, 6 };
    halfQsort(array, 0, ARRAY_LENGTH - 1);
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        if (array[i] != sortedArray[i]) {
            return false;
        }
    }
    return true;
}