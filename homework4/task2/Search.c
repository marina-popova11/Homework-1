#include "Search.h"

#include <stdio.h>

void swap(int* first, int* second) {
    if (*first == *second) {
        return;
    }
    *first ^= *second;
    *second ^= *first;
    *first ^= *second;
}

int halfQsort(int* array, int left, int right) {
    int supportElement = array[left];
    int leftIndex = left - 1;
    int rightIndex = right + 1;

    while (leftIndex <= rightIndex) {
        ++leftIndex;
        --rightIndex;
        while (array[leftIndex] < supportElement) {
            ++leftIndex;
        }
        while (array[rightIndex] > supportElement) {
            --rightIndex;
        }
        if (leftIndex >= rightIndex) {
            break;
        }
        swap(&array[leftIndex], &array[rightIndex]);
    }
    return rightIndex;
}

void quickSort(int* array, int left, int right) {
    if (left < right) {
        int part = halfQsort(array, left, right);
        quickSort(array, left, part);
        quickSort(array, part + 1, right);
    }
}

int theMostFrequencyElement(int* array, int arrayLength) {
    if (arrayLength == 0) {
        return 0;
    }
    quickSort(array, 0, arrayLength - 1);

    int element = array[0];
    int quantity = 0;

    int maxCountNumber = element;
    int maxCount = quantity;

    for (int i = 0; i < arrayLength; ++i) {
        if (array[i] != element) {
            if (quantity > maxCount) {
                maxCount = quantity;
                maxCountNumber = array[i - 1];
            }
            quantity = 0;
            element = array[i];
        }
        ++quantity;
    }

    if (quantity > maxCount) {
        maxCount = quantity;
        maxCountNumber = element;
    }

    int mostFrequentNumber = maxCountNumber;
    int numberOfRepetitions = maxCount;

    return mostFrequentNumber;
}
