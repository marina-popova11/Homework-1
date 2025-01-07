#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "list.h"

bool createListTest() {
    List* list = createList();
    if (list != NULL) {
        deleteList(list);
        return true;
    }
    deleteList(list);
    return false;
}
bool addElementTest() {
    List* list = createList();
    Position position = first(list);
    addElement(list, position, 1);
    if (isValid(list, position)) {
        deleteList(list);
        return true;
    }
    deleteList(list);
    return false;
}

bool getValueTest() {
    List* list = createList();
    Position position = first(list);
    addElement(list, position, 1);
    position = next(position);
    if (getValue(list, position) == 1) {
        deleteList(list);
        return true;
    }
    deleteList(list);
    return false;
}

bool deleteElementTest() {
    List* list = createList();
    Position position = first(list);
    addElement(list, position, 5);
    deleteElement(list, position);
    if (isEmpty(list)) {
        deleteList(list);
        return true;
    }
    deleteList(list);
    return false;
}

bool setValueTest() {
    List* list = createList();
    Position position = first(list);
    addElement(list, position, 5);
    position = next(position);
    addElement(list, position, 6);
    setValue(list, position, 7);
    if (getValue(list, position) == 7) {
        deleteList(list);
        return true;
    }
    deleteList(list);
    return false;
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