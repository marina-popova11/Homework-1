#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_LENGTH (sizeof(int) * 8)

void decToBin(int number, int* array);
void sum(int* number1, int* number2, int* answer);
int binToDec(int* array);
void printBin(int* array);
bool testSumInBin();
bool testBinToDec();
bool testSimInDec();

int main(void) {
    if (!testSumInBin() || !testBinToDec()|| !testSimInDec()) {
        printf("Tests failed!\n");
        return 1;
    }

    int n = 0;
    int m = 0;
    printf("Enter the numbers from -128 to 127:\n");
    int n1 = scanf("%u", &n);
    int m1 = scanf("%u", &m);

    printf("The first number in binary:\n");
    int resultn[MAX_LENGTH] = { 0 };
    decToBin(n, resultn);
    printBin(resultn);

    printf("The second number in binary:\n");
    int resultm[MAX_LENGTH] = { 0 };
    decToBin(m, resultm);
    printBin(resultm);

    printf("\n");
    printf("The sum of binary numbers:\n");
    int result[MAX_LENGTH] = { 0 };
    sum(resultn, resultm, result);
    printBin(result);

    printf("The sum in decimal notation:\n");
    printf("%d", binToDec(result));

    return 0;
}

void decToBin(int number, int* array) {
    int mask = 1;
    for (int i = MAX_LENGTH - 1; i >= 0; --i) {
        array[i] = ((number & mask) ? 1 : 0);
        number >>= 1;
    }
}

void sum(int* number1, int* number2, int* answer) {
    int buffer = 0;

    for (int i = MAX_LENGTH - 1; i >= 0; --i) {
        int result = number1[i] + number2[i] + buffer;

        switch (result) {
            case 0:
                answer[i] = 0;
                buffer = 0;
                break;
            case 1:
                answer[i] = 1;
                buffer = 0;
                break;
            case 2:
                buffer = 1;
                answer[i] = 0;
                break;
            case 3:
                buffer = 1;
                answer[i] = 1;
                break;
            default:
                printf("Unexpected error\n");
        }
    }
    return answer;
}

void printBin(int* array) {
    for (int i = 0; i < MAX_LENGTH; ++i) {
        printf("%d", array[i]);
    }
    printf("\n");
}

int binToDec(int* array) {
    int decValue = 0;
    int base = 1;
    for (int i = MAX_LENGTH - 1; i >= 0; --i) {
        decValue += array[i] * base;
        base *= 2;
    }
    return decValue;
}

bool testSumInBin() {
    int n = 12;
    int m = -10;

    int arrayFirstNumber[MAX_LENGTH] = { 0 };
    decToBin(n, arrayFirstNumber);
    int arraySecondNumber[MAX_LENGTH] = { 0 };
    decToBin(m, arraySecondNumber);

    int result[MAX_LENGTH] = { 0 };
    sum(arrayFirstNumber, arraySecondNumber, result);

    return binToDec(result) == 2;
}

bool testBinToDec() {
    int number = -12;
    int binNumber[MAX_LENGTH] = { 0 };
    decToBin(number, binNumber);
    return binToDec(binNumber) == -12;
}

bool testSimInDec() {
    int num1 = -120;
    int num2 = 100;

    int arrayFirstNumber[MAX_LENGTH] = { 0 };
    decToBin(num1, arrayFirstNumber);
    int arraySecondNumber[MAX_LENGTH] = { 0 };
    decToBin(num2, arraySecondNumber);

    int result[MAX_LENGTH] = { 0 };
    sum(arrayFirstNumber, arraySecondNumber, result);

    return binToDec(result) == -20;
}