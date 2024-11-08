#include <stdio.h>
#include <math.h>
#include <stdbool.h>

float exponentiationIterative(float number, int degree);
float exponentiationRecursive(float number, int degree);
float linearExponentiation(float number, int degree);

static bool testExponentiationIterative() {
    return exponentiationIterative(15, 5) == 759375;
}

static bool testExponentiationRecursive() {
    return exponentiationRecursive(2, -4) == 0,0625;
}

static bool testLinearExponentiation() {
    return linearExponentiation(0, 0) == 1;
}

int main() {
    if (!testExponentiationIterative() || !testExponentiationRecursive() || !testLinearExponentiation()) {
        printf("Tests failed\n");
        return 0;
    }

    float number = 0;
    int degree = 0;
    float result = 1;
    float result1 = 1;
    float result2 = 1;

    if (scanf("%f", &number) != 1) {
        printf("Incorrect value\n");
        return 1;
    }

    if (scanf("%d", &degree) != 1) {
        printf("Incorrect value\n");
        return 1;
    }

    if (degree != 0) {
        result = exponentiationIterative(number, degree);
        result1 = exponentiationRecursive(number, degree);
        if (degree < 0) {
            result1 = 1 / result1;
        }
        result2 = linearExponentiation(number, degree);
    }

    printf("%.10Lf\n", result);
    printf("%.10Lf\n", result1);
    printf("%.10Lf\n", result2);
    return 0;
}

float exponentiationIterative(float number, int degree) {
    float result = 1;
    int positiveDegree = abs(degree);
    while (positiveDegree > 0) {
        if (positiveDegree % 2 == 1) {
            result = result * number;
        }
        number = number * number;
        positiveDegree = positiveDegree / 2;
    }
    if (degree < 0) {
        result = 1 / result;
    }
    return result;
}

float exponentiationRecursive(float number, int degree) {
    int positiveDegree = abs(degree);
    if (positiveDegree == 0)
        return 1;
    return number * exponentiationRecursive(number, positiveDegree - 1);
}

float linearExponentiation(float number, int degree) {
    float result = 1;
    int positiveDegree = abs(degree);
    for (int i = 0; i < positiveDegree; ++i) {
        result = result * number;
    }
    if (degree < 0) {
        result = 1 / result;
    }
    return result;
}