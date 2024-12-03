#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

void readFromFile(const char* filename, HashTable* table) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }
    char string[1024] = { '\0' };
    while (fscanf(file, "%s", string) != EOF) {
        int frequency = -1;
        if (!getFrequencyByString(table, string, &frequency)) {
            frequency = 0;
        }
        ++frequency;
        insertValue(table, string, frequency);
    }
    fclose(file);
}

int main() {
    HashTable* table = createTable(64);

    readFromFile("file.txt", table);
    printf("Word frequencies:\n");
    printTable(table);

    printf("\nLoad factor: %.2f\n", loadFactor(table));
    printf("Average list length: %.2f\n", averageListLength(table));
    printf("Max list length: %d\n", maxListLength(table));

    deleteTable(table);
    return 0;
}

