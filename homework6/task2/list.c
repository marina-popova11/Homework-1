#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

typedef struct ListElement {
    int value;
    struct ListElement* next;
} ListElement;

typedef struct CircularList {
    ListElement* head;
    ListElement* tail;
} CircularList;

CircularList* createCircularList(int number) {
    CircularList* list = (CircularList*)malloc(sizeof(CircularList));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;

    for (int i = 0; i < number; ++i) {
        ListElement* element = (ListElement*)malloc(sizeof(ListElement));
        if (element == NULL) {
            return NULL;
        }
        element->value = i + 1;
        if (list->head == NULL) {
            element->next = element;
            list->head = element;
        }
        else {
            list->tail->next = element;
            element->next = list->head;
        }
        list->tail = element;
    }
    return list;
}

CircularList* getHead(CircularList* list) {
    return list->head;
}

CircularList* getTail(CircularList* list) {
    return list->tail;
}

ListElement* getNext(ListElement* element) {
    return element->next;
}

int getValue(ListElement* element) {
    return element->value;
}

void deleteElement(CircularList* list, ListElement* current, ListElement* previous) {
    if (current == list->head) {
        list->head = current->next;
        list->tail->next = list->head;
    }
    else if (current == list->tail) {
        list->tail = previous;
        list->tail->next = list->head;
    }
    previous->next = current->next;
    free(current);
}