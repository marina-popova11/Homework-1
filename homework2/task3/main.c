#include <stdio.h>
#include <math.h>
#include <stdbool.h>

float exponentiationIteractive(float number, int degree);
float exponentiationRecursive(float number, int degree);
float linearExponentiation(float number, int degree);

static bool testCorrect() {
    return (exponentiationIteractive(15, 5) == 759375);
}

static bool testCorrect1() {
    return (exponentiationRecursive(2, -4) == 0, 0625);
}

static bool testCorrect2() {
    return (linearExponentiation(0, 0) == 1);
}

int main() {
    if (!testCorrect() || !testCorrect1() || !testCorrect2()) {
        printf("Tests failed\n");
        return 0;
    }

    float number = 0;
    int degree = 0;
    long double result = 1;
    long double result1 = 1;
    long double result2 = 1;

    if (scanf("%f", &number) != 1) {
        printf("Incorrect value\n");
        return 1;
    }

    if (scanf("%d", &degree) != 1) {
        printf("Incorrect value\n");
        return 1;
    }

    if (degree != 0) {
        result = exponentiationIteractive(number, degree);
        result1 = exponentiationRecursive(number, degree);
        result2 = linearExponentiation(number, degree);
        if (degree < 0) {
            result = 1 / result;
            result1 = 1 / result1;
            result2 = 1 / result2;
        }
    }

    printf("%.10Lf\n", result);
    printf("%.10Lf\n", result1);
    printf("%.10Lf\n", result2);
    return 0;
}

float exponentiationIteractive(float number, int degree) {
    float res = 1;
    degree = abs(degree);
    while (degree > 0) {
        if (degree % 2 == 1) {
            res = res * number;
        }
        number = number * number;
        degree = degree / 2;
    }
    return res;
}

float exponentiationRecursive(float number, int degree) {
    degree = abs(degree);
    if (degree == 0)
        return 1;
    return number * exponentiationRecursive(number, degree - 1);
}

float linearExponentiation(float number, int degree) {
    float result = 1;
    degree = abs(degree);
    for (int i = 0; i < degree; ++i) {
        result = result * number;
    }
}