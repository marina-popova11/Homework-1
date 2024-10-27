#include <stdio.h>

int division(int dividend, int divisor);

int main() {
    int dividend = 0;
    int divisor = 0;
    printf("Enter the first number: \n");
    scanf("%d", &dividend);
    printf("Enter the second number: \n");
    scanf("%d", &divisor);

    if (divisor == 0) {
        printf("ERROR");
        return 1;
    } else {
        int result = 0;
        if (dividend != 0) {
            result = division(dividend, divisor);
        }
        printf("Result = %d\n", result);
    }
    return 0;
}

int division(int dividend, int divisor) {
    int divisible = dividend;
    int divider = divisor;
    int quotient = 0;
    int signOfQuotient = 1;
    int variableOfSign  = 1; 

    if (dividend > 0) {       //if the divisible is greater than zero, we make a quotient sign with a plus
        signOfQuotient = 1;
        if (divisor < 0) {       //if the divisor is less than zero, the sign of the quotient 
            signOfQuotient = -1; //changes to minus, and the divisor changes to the opposite, for the convenience of counting
            divider = -divider;
        }
    }

    else if (dividend < 0) {     //if the divisible is less than zero, the sign of the quotient becomes negative, 
        signOfQuotient = -1;     //variableOfSign has the same sign as the divisible, therefore it becomes negative
        variableOfSign = -1;
        if (divisor < 0) {       //if, with a negative divisible, the divisor is also negative, we change the sign of the quotient
            signOfQuotient = 1;  // to a positive one, the divisor changes its sign
            divider = -divider;  //if the divisor is positive in both cases, all changes are skipped and the "while" loop begins
        }
    }

    while (divisible * variableOfSign >= divider) { //comparing the modules of two numbers
        divisible -= divider * variableOfSign;  //using variableOfSign, subtraction is more convenient
        quotient += signOfQuotient;
    }
    if (dividend < 0 && divisor > 0) { //checking for a positive division remainder
        quotient -= 1;
    } else if (dividend < 0 && divisor < 0)
        quotient += 1;

    return quotient;
}
