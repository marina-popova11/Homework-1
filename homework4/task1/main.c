#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int binN(int number, int* array);
int sum(int* num1, int* num2, int* array);
int decimalisation(int* array);
void print(int* array, int arrayLength);
int arrayToInt(int* array);
bool testSumInBin();
bool testBinToDec();
bool testSimInDec();

int main(void) {
    if (!testSumInBin() || !testBinToDec()|| !testSimInDec()) {
        printf("Tests failed!\n");
        return 1;
    }

    int n, m;
    printf("Enter the numbers from -128 to 127:\n");
    int n1 = scanf("%u\n", &n);
    int m1 = scanf("%u\n\n", &m);

    printf("The first number in binary:\n");
    int resultn[8];
    binN(n, resultn);
    print(resultn, 8);

    printf("The second number in binary:\n");
    int resultm[8];
    binN(m, resultm);
    print(resultm, 8);

    printf("\n");
    printf("The sum of binary numbers:\n");
    int result[8];
    sum(resultn, resultm, result);
    print(result, 8);

    printf("The sum in decimal notation:\n");
    printf("%d", decimalisation(result));

    return 0;
}

int binN(int number, int* array) {
    int n = abs(number);
    int binaryNumbers[8] = { 0 };
    int i = 0;
    for (int i = 0; i < 7; ++i) {
        binaryNumbers[7 - i] = (n % 2);
        n /= 2;
    }
    if (number < 0) {
        for (int i = 0; i < 8; ++i) {
            binaryNumbers[i] = 1 - binaryNumbers[i];
        }
        int unit[8] = { 0, 0, 0, 0, 0, 0, 0, 1 };
        sum(binaryNumbers, unit, array);
        return array;
    }
    for (int i = 0; i < 8; ++i) {
        array[i] = binaryNumbers[i];
    }
    return array;
}

int arrayToInt(int* array) {
    int k = 0;
    for (int i = 0; i < 8; ++i) {
        k = 10 * k + array[i];
    }
    return k;
}

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

void print(int* array, int arrayLength) {
    for (int i = 0; i < arrayLength; ++i) {
        printf("%d", array[i]);
    }
    printf("\n");
}

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

bool testSumInBin() {
    int n = 12;
    int m = -10;

    int arrayFirstNumber[8];
    binN(n, arrayFirstNumber);
    int arraySecondNumber[8];
    binN(m, arraySecondNumber);

    int result[8];
    sum(arrayFirstNumber, arraySecondNumber, result);

    int binResultSum[8] = { 0, 0, 0, 0, 0, 0, 1, 0 };
    for (int i = 0; i < 8; ++i) {
        return result[i] == binResultSum[i];
    }
}

bool testBinToDec() {
    int arrayFirstNumber[8] = { 1, 1, 1, 1, 0, 1, 0, 0 };
    return decimalisation(arrayFirstNumber) == -12;
}

bool testSimInDec() {
    int num1 = -120;
    int num2 = 100;

    int arrayFirstNumber[8];
    binN(num1, arrayFirstNumber);
    int arraySecondNumber[8];
    binN(num2, arraySecondNumber);

    int result[8];
    sum(arrayFirstNumber, arraySecondNumber, result);

    return decimalisation(result) == -20;
}