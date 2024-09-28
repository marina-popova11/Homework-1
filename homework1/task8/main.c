#include <stdio.h>

void swap(int start, int end, int* array);

void print_array(int A[], int N) {
    for (int i = 0; i < N; i++)
        printf("%d", A[i]);
    printf("\n");
}

#define ARRAY_SIZE 10

void main() {
    printf("Enter array (10 elements) to flip: ");
    int array[ARRAY_SIZE] = { 0 };
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Incorrect value\n");
            return 1;
        }
    }
    printf("\n");

    printf("Enter the length of the first part of the array: ");
    int m;
    if (scanf("%d", &m) != 1) {
        printf("Incorrect value\n");
        return 1;
    }

    if (m > ARRAY_SIZE) {
        printf("The length of first part is greater than array length\n");
        return 1;
    }

    printf("\n");

    swap(0, m - 1, array);
    swap(m, ARRAY_SIZE - 1, array);
    swap(0, ARRAY_SIZE - 1, array);
    print_array(array, ARRAY_SIZE);
}

void swap(int start, int end, int* array) {
    for (int i = start; i < (start + end + 1) / 2; i++) {
        int var = array[i];
        array[i] = array[end + start - i];
        array[end + start - i] = var;
    }
}
