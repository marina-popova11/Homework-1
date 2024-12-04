#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

bool testSortedTree() {
    int array[] = { 3, 4, 2, 6, 1, 9 };
    int sortedArray[] = { 1, 2, 3, 4, 6, 9 };
    int length = sizeof(array) / (sizeof(int));
    sortingArray(array, length);
    for (int i = 0; i < length; ++i) {
        if (array[i] != sortedArray[i]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    if (!testSortedTree()) {
        printf("Test failed!\n");
        return -1;
    }
    int array[] = { 121, 323, 772, 213, 310, 553 };
    int length = sizeof(array) / (sizeof(int));
    sortingArray(array, length);
    printf("Sorted array: ");
    for (int i = 0; i < length; ++i) {
        printf("%d ", array[i]);
    }
    return 0;
}

