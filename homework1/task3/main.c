#include <stdio.h>

int division(int a, int b);

int main() {
    int a;
    int b;
    printf("Enter the first number: \n");
    int result1 = scanf("%d", &a);
    printf("Enter the second number: \n");
    int result2 = scanf("%d", &b);
    if (b == 0) {
        printf("ERROR");
        return 1;
    } else {
        int result = 0;
        if (a != 0) {
            result = division(a, b);
        }
        printf("Result = %d\n", result);
    }
    return 0;
}

int division(int a, int b) {
    int divisible = a;
    int divider = b;
    int quotient = 0;
    int signOfQuotient = 1;
    int variableOfSign  = 1; 

    if (a > 0) {
        signOfQuotient = 1;
        if (b < 0) {
            signOfQuotient = -1;
            divider = -divider;
        }
    }
    else if (a < 0) {
        signOfQuotient = -1;
        variableOfSign = -1;
        if (b < 0) {
            signOfQuotient = 1;
            divider = -divider;
        }
    }
    while (divisible * variableOfSign >= divider) {
        divisible -= divider * variableOfSign; 
        quotient += signOfQuotient;
    }
    if (a < 0 && b > 0) {
        quotient -= 1;
    } else if (a < 0 && b < 0)
        quotient += 1;

    return quotient;
}
