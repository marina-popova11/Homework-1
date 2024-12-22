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
    const double epsilon = 0.000001;
    return exponentiationRecursive(2, -4) > 0.0625 - epsilon;
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
    float resultExponentiationIterative = 1;
    float resultExponentiationRecursive = 1;
    float resultLinearExponentiation = 1;

    printf("Enter the number:");
    if (scanf("%f", &number) != 1) {
        printf("Incorrect value\n");
        return 1;
    }

    printf("Enter the degree:");
    if (scanf("%d", &degree) != 1) {
        printf("Incorrect value\n");
        return 1;
    }

    if (degree != 0) {
        resultExponentiationIterative = exponentiationIterative(number, degree);
        resultExponentiationRecursive = exponentiationRecursive(number, degree);
        resultLinearExponentiation = linearExponentiation(number, degree);
    }

    printf("%.10Lf\n", resultExponentiationIterative);
    printf("%.10Lf\n", resultExponentiationRecursive);
    printf("%.10Lf\n", resultLinearExponentiation);
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
    if (degree == 0) {
        return 1;
    }
    if (degree < 0) {
        return 1 / exponentiationRecursive(number, abs(degree));
    } else {
        return number * exponentiationRecursive(number, degree - 1);
    }
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