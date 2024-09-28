#include <stdio.h>
#define maximumNumberOfDigits 20

int main() {
    int numbers[maximumNumberOfDigits];
    int countZero = 0;
    printf("Enter the numbers(enter it separated by a space): ");
    for (int i = 0; i < maximumNumberOfDigits; i++) {
        scanf_s("%d", &numbers[i]);
    }
    for (int i = 0; i < maximumNumberOfDigits; i++) {
        if (numbers[i] == 0) {
            countZero++;
        }
    }
    printf("Number of zeros %d\n", countZero);
    return 0;
}
