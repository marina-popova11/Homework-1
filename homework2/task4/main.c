#include <stdio.h>
#include <stdbool.h>

long long fibonacciRecursive(int n);
long long fibonacciIterative(int n);

static bool testCorrect() {
    return (fibonacciRecursive(15) == 610);
}

static bool testCorrect1() {
    return (fibonacciIterative(20) == 6765);
}

static bool testCorrect2() {
    return (fibonacciIterative(0) == 0);
}

static bool testCorrect3() {
    return (fibonacciRecursive(-1) == 0);
}

int main(void) {
    if (!testCorrect() || !testCorrect1() || !testCorrect2() || !testCorrect3()) {
        printf("Tests failed\n");
        return 0;
    }
    int number = 40;
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
    long long f1 = 0, f2 = 1;
    if (number < 0) {
        printf("Fibonacci numbers must be greater than or equal to 0\n");
        return 0;
    }
    if (number == 0 || number == 1)
        return number;
    for (int i = 2; i <= number; ++i) {
        long long fib = f1 + f2;
        f1 = f2;
        f2 = fib;
    }
    return f2;
}

long long fibonacciRecursive(int number) {
    if (number < 0) {
        printf("Fibonacci numbers must be greater than or equal to 0\n");
        return 0;
    }
    if (number == 0 || number == 1) {
        return number;
    }
    return fibonacciRecursive(number - 2) + fibonacciRecursive(number - 1);
}

