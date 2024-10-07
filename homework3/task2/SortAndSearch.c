#include "SortAndSearch.h"

#include <stdio.h>
#include <stdbool.h>

void sortByInserts(int* array, int left, int right) {
    int element = 0;
    int position = 0;

    for (int i = 1; i < right + 1; ++i) {
        element = array[i];
        position = i;
        while (position > 0 && array[position - 1] > element) {
            int num = array[position - 1];
            array[position - 1] = array[position];
            array[position] = num;
            position -= 1;
        }
    }
}

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

void smartQuicksort(int* array, int left, int right) {
    if (right - left + 1 <= 10) {
        sortByInserts(array, left, right);
        return;
    }

    int part = halfQsort(array, left, right);
    smartQuicksort(array, left, part);
    smartQuicksort(array, part + 1, right);
}

bool binarySearch(int* array, int left, int right, int* element) {
    while (left <= right) {
        int middle = (left + right) / 2;
        int middleElement = array[middle];
        if (array[middle] == element)
            return true;
        else if (array[middle] < element)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return array[left] == element;
}