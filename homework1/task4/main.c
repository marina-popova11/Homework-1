#include <stdio.h>

int main() {
    int differentSum[28] = { 0 };
    int var1, var2, var3;
    for (var1 = 0; var1 < 10; var1++) {
        for (var2 = 0; var2 < 10; var2++) {
            for (var3 = 0; var3 < 10; var3++) {
                int sum = var1 + var2 + var3;
                differentSum[sum]++;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < 28; i++) {
        count += differentSum[i] * differentSum[i];
    }
    printf("%d", count);
    return 0;
}
