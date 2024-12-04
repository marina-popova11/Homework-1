#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "table.h"
#include "List.h"

bool createListTest() {
    List* list = createList();
    return list != NULL;
}

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

    return getTableCountOfElemenet(table) == 7;
}

bool tests() {
    if (!createListTest()) {
        printf("CreateListTest is failed\n");
        return false;
    }
    if (!createHashTableAndInsertValueTest()) {
        printf("CreateHashTableAndInsertValueTest is failed\n");
        return false;
    }
    printf("All tests passed\n");
    return true;
}