#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "list.h"

bool createListTest() {
    List* list = createList();
    return list != NULL;
}

bool addElementTest() {
    List* list = createList();
    Position position = first(list);
    addElement(list, position, 1);
    return isValid(list, position);
}

bool getValueTest() {
    List* list = createList();
    Position position = first(list);
    addElement(list, position, 1);
    position = next(position);
    return getValue(list, position) == 1;
}

bool deleteElementTest() {
    List* list = createList();
    Position position = first(list);
    addElement(list, position, 5);
    return deleteElement(list, position);
}

bool setValueTest() {
    List* list = createList();
    Position position = first(list);
    addElement(list, position, 5);
    position = next(position);
    addElement(list, position, 6);
    setValue(list, position, 7);
    return getValue(list, position) == 7;
}

int main(void) {
    if (!createListTest()) {
        printf("CreateListTest is failed\n");
        return false;
    }
    if (!addElementTest()) {
        printf("AddElementTest is failed\n");
        return false;
    }
    if (!deleteElementTest()) {
        printf("DeleteElementTest is failed\n");
        return false;
    }
    if (!getValueTest()) {
        printf("GetValueTest is failed\n");
        return false;
    }
    if (!setValueTest()) {
        printf("SetValueTest is failed\n");
        return false;
    }

    printf("All tests passed\n");
    return true;
}