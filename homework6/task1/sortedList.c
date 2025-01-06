#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sortedList.h"

void addElementToSortedList(List* list, Value value) {
    Position position = first(list);
    while (!isLast(list, position) && getValue(list, next(position)) <= value) {
        position = next(position);
    }
    addElement(list, position, value);
}

void deleteElementFromSortedList(List* list, Value value) {
    Position position = first(list);
    while (!isLast(list, position)) {
        if (getValue(list, next(position)) == value) {
            deleteElement(list, position);
            break;
        }
        position = next(position);
    }
}