#include <stdio.h>
#include <string.h>
#include <stddef.h>

int main() {
    char s[] = "rrrrrrrrrrrrrrffr";
    char s1[] = "rr";
    size_t count = 0;
    size_t length_s = strlen(s);
    size_t length_s1 = strlen(s1);
    for (size_t i = 0; i < length_s; i++) {
        if (s[i] == s1[0]) {
            if (strncmp(&s[i], &s1, length_s1) == 0) {
                count++;
                i += length_s1 - 1;
            }
        }
    }
    printf("%zu", count);
    return 0;
}