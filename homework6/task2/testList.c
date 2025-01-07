#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

bool createCircularListTest(void) {
    CircularList* list = createCircularList();
    for (int i = 1; i <= 10; ++i) {
        addElement(list, i);
    }
    ListElement* head = getHead(list);
    if (getValue(head) == 1) {
        deleteList(list);
        return true;
    }
    deleteList(list);
    return false;
}

bool addElementTest(void) {
    CircularList* list = createCircularList();
    for (int i = 1; i <= 10; ++i) {
        addElement(list, i);
    }
    return getListLength(list) == 10;
}

bool deleteElementTest(void) {
    CircularList* list = createCircularList();
    for (int i = 1; i <= 10; ++i) {
        addElement(list, i);
    }
    ListElement* head = getHead(list);
    ListElement* tail = getTail(list);

    while (head != getNext(head)) {
        for (int count = 1; count < 4; ++count) {
            tail = head;
            head = getNext(head);
        }
        deleteElement(list, head, tail);
        head = getNext(tail);
    }
    if (getValue(head) == 5) {
        deleteList(list);
        return true;
    }
    deleteList(list);
    return false;
}
