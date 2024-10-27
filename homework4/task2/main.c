#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "Search.h"

#define LENGTH 1000

void print_array(int* array, int arrayLength);
bool testQuickSort();
bool testMostFrequencyElement();

int main(void) {
    if (!testQuickSort() || !testMostFrequencyElement()) {
        printf("Tests failed!\n");
        return 1;
    }

    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }

    int data[LENGTH] = { 0 };
    int numsRead = 0;
    while (!feof(file)) {
        const int filledFormatSpecifiers = fscanf(file, "%d", &data[numsRead]);
        if (filledFormatSpecifiers < 0)
            break;
        ++numsRead;
    }
    fclose(file);

    int result = theMostFrequencyElement(data, LENGTH);
    printf("%d", result);

    return 0;
}

void print_array(int* array, int arrayLength) {
    printf("[");
    for (int i = 0; i < arrayLength; ++i) {
        printf(" %d ", array[i]);
    }
    printf("]\n");
}

bool testQuickSort() {
    int array[15] = { 2, 4, 55, 21, 3, 2, 8, 18, 5, 3, 5, 19, 18, 2, 18 };
    int sorted_array[15] = { 2, 2, 2, 3, 3, 3, 4, 5, 5, 8, 18, 18, 18, 19, 55 };
    quickSort(array, 0, 15 - 1);
    for (int i = 0; i < 15; ++i) {
        return array[i] == sorted_array[i];
    }
}

bool testMostFrequencyElement() {
    int array[20] = { 2, 3, 4, 5, 3, 5, 6, 7, 5, 5 ,4 ,8, 9, 6, 5, 3 ,7, 8, 5, 6 };
    int result = theMostFrequencyElement(array, 20);
    return result == 5;
}