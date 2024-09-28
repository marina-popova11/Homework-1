#include <stdio.h>
int findSimpleNum(int num);
int main() {
    int num = 0;
    printf("Set the number\n");
    scanf_s("%d\n", &num);
    findSimpleNum(num);

    return 0;
}
int simple(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
int findSimpleNum(int num) {
    for (int i = 2; i <= num; i++) {
        if (simple(i))
            printf("%d ", i);
        else
            continue;
    }
}