#include <stdio.h>

int division(int a, int b);

void main() {
    int a;
    int b;
    printf("Enter the first number: \n");
    int result1 = scanf("%d", &a);
    printf("Enter the second number: \n");
    int result2 = scanf("%d", &b);
    if (b == 0)
        printf("ERROR");
    else {
        int result = 0;
        if (a != 0) {
            result = division(a, b);
        }

        printf("Result = %d\n", result);
    }
}

int division(int a, int b) {
    int divisible = a;
    int quotient = 0;
    int d = 1;
    int k = 1;

    if (a > 0) {
        d = 1;
        if (b < 0) {
            d = -1;
            b = -b;
        }
    }
    else if (a < 0) {
        d = -1;
        k = -1;
        if (b < 0) {
            d = 1;
            b = -b;
        }
    }
    while (divisible * k >= b) {
        divisible -= b * k;
        quotient += d;
    }

    return quotient;
}
