#include <stdio.h>

long long fibonacciRecursive(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    return fibonacciRecursive(n - 2) + fibonacciRecursive(n - 1);
}

long long fibonacciIterative(int n) {
    long long f1 = 0, f2 = 1;
    
    for (int i = 2; i <= n; ++i) {
        long long fib = f1 + f2;
        f1 = f2;
        f2 = fib;
    }
    
    return f2;
}

int main(void) {
    int n = 40;
    printf("counting iterative:\n");
    long long result = fibonacciIterative(n);
    printf("result: %lld\n", result);

    printf("counting recursive:\n");
    result = fibonacciRecursive(n);
    printf("result: %lld\n", result);
}
