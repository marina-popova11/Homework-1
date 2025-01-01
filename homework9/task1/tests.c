#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "test.h"
#include "table.h"
#include "List.h"

bool createHashTableAndInsertValueTest() {
    HashTable* table = createTable(32);
    insertValue(table, "123", 1);
    insertValue(table, "345", 1);
    insertValue(table, "456", 1);
    insertValue(table, "112", 1);
    insertValue(table, "776", 1);
    insertValue(table, "332", 1);
    insertValue(table, "111", 1);
    insertValue(table, "123", 2);
    if (getTableCountOfElemenet(table) == 7) {
        deleteTable(table);
        return true;
    }
    deleteTable(table);
    return false;
}

bool insertValueTest() {
    HashTable* table = createTable(4);
    insertValue(table, "red", 1);
    insertValue(table, "yellow", 2);
    int frequency = 0;
    bool foundRed = getFrequencyByString(table, "red", &frequency);
    bool foundYellow = getFrequencyByString(table, "yellow", &frequency);
    if (foundRed && foundYellow) {
        deleteTable(table);
        return true;
    }
    deleteTable(table);
    return false;
}

bool resizeTableTest() {
    HashTable* table = createTable(2);
    insertValue(table, "red", 1);
    insertValue(table, "yellow", 2);
    insertValue(table, "blue", 3);
    if (getTableSize(table) > 2) {
        deleteTable(table);
        return true;
    }
    deleteTable(table);
    return false;
}

bool loadFactorTest() {
    HashTable* table = createTable(8);
    insertValue(table, "red", 1);
    insertValue(table, "yellow", 2);
    float loadFactorValue = loadFactor(table);
    if (loadFactorValue < 0.4) {
        deleteTable(table);
        return true;
    }
    deleteTable(table);
    return false;
}

bool averageAndMaxListLengthTest() {
    HashTable* table = createTable(10);
    insertValue(table, "red", 1);
    insertValue(table, "yellow", 2);
    insertValue(table, "blue", 3);
    float averageLength = averageListLength(table);
    int maxLength = maxListLength(table);
    if (maxLength == 1 && averageLength == 1) {
        deleteTable(table);
        return true;
    }
    deleteTable(table);
    return false;
}

bool tests() {
    if (!createHashTableAndInsertValueTest()) {
        printf("CreateHashTableAndInsertValueTest is failed\n");
        return false;
    }
    if (!insertValueTest()) {
        printf("InsertValueTest is failed\n");
        return false;
    }
    if (!resizeTableTest()) {
        printf("ResizeTableTest is failed\n");
        return false;
    }
    if (!loadFactorTest()) {
        printf("LoadFactorTest is failed\n");
        return false;
    }
    if (!averageAndMaxListLengthTest()) {
        printf("AverageAndMaxListLengthTest is failed\n");
        return false;
    }
    printf("All tests passed\n");
    return true;
}