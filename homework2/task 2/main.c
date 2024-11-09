#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_LENGTH 100000
#define LENGTH 15

bool babbleSorting(int* array, int arrayLength);
bool countingSorting(int* array, int arrayLength);
static void printArray(int* array, int length);
static bool testCorrect();

int main() {
    if (!testCorrect()) {
        printf("Tests failed\n");
        return -1;
    }

    srand(time(NULL));

    int* array = malloc(ARRAY_LENGTH * sizeof(int));
    if (array == NULL) {
        printf("Failed to allicated array\n");
        return 1;
    }
    int num;
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        num = -100 + rand() % 200;
        array[i] = num;
    }

    clock_t startTimeBabble = clock();
    babbleSorting(array, ARRAY_LENGTH);

    double timeBabble = clock() - startTimeBabble;
    printf("Processor time spent on bubble sorting: %f seconds\n", (float)timeBabble / CLOCKS_PER_SEC);
    clock_t startTimeCounting = clock();
    countingSorting(array, ARRAY_LENGTH);

    double timeCounting = clock() - startTimeCounting;
    printf("Processor time spent on sorting by counting: %f seconds\n", (float)timeCounting / CLOCKS_PER_SEC);
    free(array);

    return 0;
}

bool babbleSorting(int* array, int arrayLength) {
    for (int i = 0; i < arrayLength; ++i) {
        bool flag = false;
        for (int j = arrayLength - 1; j > i; --j) {
            if (array[j - 1] > array[j]) {
                flag = true;
                int num = array[j - 1];
                array[j - 1] = array[j];
                array[j] = num;
            }
        }
        if (!flag) {
            break;
        }
    }
    return true;
}

bool countingSorting(int* array, int arrayLength) {
    int maxElement = 0;
    for (int i = 0; i < arrayLength; ++i) {
        if (array[i] > maxElement) {
            maxElement = array[i];
        }
    }
    int minElement = 1000;
    for (int i = 0; i < arrayLength; ++i) {
        if (array[i] < minElement) {
            minElement = array[i];
        }
    }

    int valuesCount = maxElement - minElement + 1;
    int* countArray = calloc(valuesCount, sizeof(int));
    if (countArray == NULL) {
        printf("Failed to allocate memory\n");
        return false;
    }

    for (int i = 0; i < arrayLength; ++i) {
        ++countArray[array[i] - minElement];
    }

    int pointer = 0;
    for (int i = 0; i < valuesCount; ++i) {
        for (int j = 0; j < countArray[i]; ++j) {
            array[pointer] = i + minElement;
            ++pointer;
        }
    }
    free(countArray);
    return true;
}

static void printArray(int* array, int length) {
    printf("[");
    for (int i = 0; i < length; i++)
        printf(" %d ", array[i]);
    printf("]");
    printf("\n");
}

static bool testCorrect() {
    int array[LENGTH] = { 2, 14, 6, 0, 4, 5, 3, 7, 12, 8, 4, 5, 3, 2, 0 };

    int sortedArray[LENGTH] = { 0, 0, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 8, 12, 14 };
    
    babbleSorting(array, LENGTH);
    for (int i = 0; i < LENGTH; ++i) {
        if (array[i] != sortedArray[i])
            return false;
    }

    countingSorting(array, LENGTH);
    for (int i = 0; i < LENGTH; ++i) {
        if (array[i] != sortedArray[i])
            return false;
    }
    
    return true;
}