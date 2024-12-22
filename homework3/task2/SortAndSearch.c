#include "SortAndSearch.h"

#include <stdio.h>
#include <stdbool.h>

void swap(int* first, int* second) {
    if (*first == *second) {
        return;
    }
    *first ^= *second;
    *second ^= *first;
    *first ^= *second;
}

void insertionSort(int* array, int left, int right) {
    int element = 0;
    int position = 0;

    for (int i = 1; i < right + 1; ++i) {
        element = array[i];
        position = i;
        while (position > 0 && array[position - 1] > element) {
            swap(&array[position - 1], &array[position]);
            position -= 1;
        }
    }
}

int halfQsort(int* array, int left, int right) {
    int supportElement = array[left];
    int leftIndex = left - 1;
    int rightIndex = right + 1;

    while (leftIndex <= rightIndex) {
        ++leftIndex;
        --rightIndex;
        while (array[leftIndex] < supportElement) ++leftIndex;
        while (array[rightIndex] > supportElement) --rightIndex;
        if (leftIndex >= rightIndex) {
            break;
        }
        int num = array[leftIndex];
        array[leftIndex] = array[rightIndex];
        array[rightIndex] = num;
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

void smartQuicksort(int* array, int left, int right) {
    if (right - left + 1 <= 10) {
        insertionSort(array, left, right);
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