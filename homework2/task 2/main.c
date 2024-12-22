#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define ARRAY_LENGTH 100000
#define LENGTH 15

bool babbleSort(int* array, int arrayLength);
bool countingSort(int* array, int arrayLength);
static void printArray(int* array, int length);
static bool testCorrect();

int main(void) {
    if (!testCorrect()) {
        printf("Tests failed\n");
        return -1;
    }

    srand(time(NULL));

    int* arrayForBubble = malloc(ARRAY_LENGTH * sizeof(int));
    if (arrayForBubble == NULL) {
        printf("Failed to allicated array\n");
        return -1;
    }
    int num1 = 0;
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        num1 = -100 + rand() % 200;
        arrayForBubble[i] = num1;
    }
    clock_t startTimeBabble = clock();
    babbleSort(arrayForBubble, ARRAY_LENGTH);
    clock_t endTimeBubble = clock();

    double timeBabble = endTimeBubble - startTimeBabble;
    printf("Processor time spent on bubble sorting: %f seconds\n", (float)timeBabble / CLOCKS_PER_SEC);
    
    int* arrayForCounting = malloc(ARRAY_LENGTH * sizeof(int));
    if (arrayForCounting == NULL) {
        printf("Failed to allicated array\n");
        return -1;
    }
    int num2 = 0;
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        num2 = -100 + rand() % 200;
        arrayForCounting[i] = num2;
    }
    clock_t startTimeCounting = clock();
    countingSort(arrayForCounting, ARRAY_LENGTH);
    clock_t endTimeCounting = clock();

    double timeCounting = endTimeCounting - startTimeCounting;
    printf("Processor time spent on sorting by counting: %f seconds\n", (float)timeCounting / CLOCKS_PER_SEC);
    free(arrayForBubble);
    free(arrayForCounting);

    return 0;
}

bool babbleSort(int* array, int arrayLength) {
    bool flag = false;
    while (arrayLength > 1) {
        for (int i = 0; i < arrayLength - 1; ++i) {
            if (array[i] > array[i + 1]) {
                flag = true;
                int num = array[i + 1];
                array[i + 1] = array[i];
                array[i] = num;
            }
        }
        if (!flag) {
            break;
        }
        --arrayLength;
    }
    return true;
}

bool countingSort(int* array, int arrayLength) {
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
    int array1[LENGTH] = { 2, 14, 6, 0, 4, 5, 3, 7, 12, 8, 4, 5, 3, 2, 0 };

    int sortedArray1[LENGTH] = { 0, 0, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 8, 12, 14 };

    babbleSort(array1, LENGTH);
    for (int i = 0; i < LENGTH; ++i) {
        if (array1[i] != sortedArray1[i])
            return false;
    }

    int array2[LENGTH] = { 2, 14, 6, -1, 4, 5, 3, 7, 12, 8, 4, 5, 3, 2, 0 };
    int sortedArray2[LENGTH] = { -1, 0, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 8, 12, 14 };

    countingSort(array2, LENGTH);
    for (int i = 0; i < LENGTH; ++i) {
        if (array2[i] != sortedArray2[i])
            return false;
    }

    return true;
}