#include <stdio.h>
#include <stdbool.h>

long long fibonacciRecursive(int n);
long long fibonacciIterative(int n);

static bool testCorrect() {
    return fibonacciRecursive(15) == 610;
}

static bool testCorrect1() {
    return fibonacciIterative(20) == 6765;
}

static bool testCorrect2() {
    return fibonacciIterative(0) == 0;
}

int main(void) {
    if (!testCorrect() || !testCorrect1() || !testCorrect2()) {
        printf("Tests failed\n");
        return 0;
    }
    int number = 0;
    printf("Enter the number:");
    scanf("%d", &number);
    printf("\n");
    if (number < 0) {
        printf("You cannot enter negative numbers!\n");
        return -1;
    }
    printf("counting iterative:\n");
    long long result = fibonacciIterative(number);
    printf("result: %lld\n", result);

    printf("counting recursive:\n");
    result = fibonacciRecursive(number);
    printf("result: %lld\n", result);

    printf("The recursive algorithm starts working much slower than the iterative one \
starting from the 40th number.\n");
}

long long fibonacciIterative(int number) {
    long long fibonacciNum1 = 0;
    long long fibonacciNum2 = 1;
    if (number == 0 || number == 1)
        return number;
    for (int i = 2; i <= number; ++i) {
        long long fibonacciNum3 = fibonacciNum1 + fibonacciNum2;
        fibonacciNum1 = fibonacciNum2;
        fibonacciNum2 = fibonacciNum3;
    }
    return fibonacciNum2;
}

long long fibonacciRecursive(int number) {
    if (number == 0 || number == 1) {
        return number;
    }
    return fibonacciRecursive(number - 2) + fibonacciRecursive(number - 1);
}

