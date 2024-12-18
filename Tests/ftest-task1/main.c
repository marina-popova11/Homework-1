#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

bool testBinToDec();

//converts from binary to decimal
int binaryToDecimal(const char* binaryString) {
    int decimalValue = 0;

    while (*binaryString) {
        decimalValue <<= 1;
        if (*binaryString == '1') {
            decimalValue += 1;
        }
        ++binaryString;
    }

    return decimalValue;
}

int main() {
    if (!testBinToDec()) {
        return -1;
    }
    char binaryString[65];
    printf("Enter string:\n");
    scanf("%64s", binaryString);

    int decimalValue = binaryToDecimal(binaryString);
    printf("decimal: %d\n", decimalValue);

    return 0;
}

bool testBinToDec() {
    char* array = "01111111";
    int result = binaryToDecimal(array);
    
    return result == 127;
}