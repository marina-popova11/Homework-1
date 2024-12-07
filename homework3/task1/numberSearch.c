#include "frequentelement.h"

#include <stdio.h>

int halfQsort(int* array, int left, int right) {
    int supportElement = array[left];
    int i = left - 1;
    int j = right + 1;

    while (i <= j) {
        ++i;
        --j;
        while (array[i] < supportElement) ++i;
        while (array[j] > supportElement) --j;
        if (i >= j) {
            break;
        }
        int num = array[i];
        array[i] = array[j];
        array[j] = num;
    }
    return j;
}

void quickSort(int* array, int left, int right) {
    if (left < right) {
        int part = halfQsort(array, left, right);
        quickSort(array, left, part);
        quickSort(array, part + 1, right);
    }
}

int theMostFrequencyElement(int* array, int arraylength) {
    if (arraylength == 0)
        return 0;
    quickSort(array, 0, arraylength - 1);

    int element = array[0];
    int quantity = 0;

    int maxCountNumber = element;
    int maxCount = quantity;

    for (int i = 0; i < arraylength; ++i) {
        if (array[i] != element) {
            if (quantity > maxCount) {
                maxCount = quantity;
                maxCountNumber = array[i - 1];
            }
            quantity = 0;
            element = array[i];
        }
        quantity++;
    }

    if (quantity > maxCount) {
        maxCount = quantity;
        maxCountNumber = element;
    }

    int mostFrequentNumber = maxCountNumber;
    int numberOfRepetitions = maxCount;

    return mostFrequentNumber;
}
