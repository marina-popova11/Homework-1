#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int decimalisation(int* array);
int sum(int* num1, int* num2, int* array);
bool testBinToDec();

int main(void) {
    if (!testBinToDec()) {
        printf("Tests failed!\n");
        return 1;
    }
    int array[8] = { 1, 0, 1, 0, 0, 1, 0, 0 };
    printf("%d", decimalisation(array));

    return 0;
}

//converts from binary to decimal
int decimalisation(int* array) {
    int decValue = 0;
    int base = 1;
    if (array[0] == 1) {
        int result[8];
        int unit[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        sum(array, unit, result);
        for (int i = 0; i < 8; ++i) {
            result[i] = 1 - result[i];
        }
        for (int i = 7; i >= 0; --i) {
            decValue += result[i] * base;
            base *= 2;
        }
        return decValue * (-1);
    }
    for (int i = 7; i >= 0; --i) {
        decValue += array[i] * base;
        base *= 2;
    }
    return decValue;
}

//sums two binary numbers
int sum(int* num1, int* num2, int* array) {
    int memory = 0;
    for (int i = 7; i >= 0; --i) {
        int result = num1[i] + num2[i] + memory;
        if (result == 0) {
            array[i] = 0;
            memory = 0;
        }
        if (result == 1) {
            array[i] = 1;
            memory = 0;
        }
        if (result == 2) {
            array[i] = 0;
            memory = 1;
        }
        if (result == 3) {
            array[i] = 1;
            memory = 1;
        }
    }

    return array;
}

bool testBinToDec() {
    int array[8] = { 1, 1, 0, 0, 0, 1, 0, 0 };
    int result = decimalisation(array);
    
    return result == -60;
}