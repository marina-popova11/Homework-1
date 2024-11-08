#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

bool createCircularListTest() {
    CircularList* list = createCircularList(10);
    ListElement* head = getHead(list);
    return getValue(head) == 1;
}

bool deleteElementTest() {
    CircularList* list = createCircularList(10);
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
    return getValue(head) == 5;
}
