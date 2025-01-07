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

CircularList* createCircularList(void) {
    CircularList* list = (CircularList*)malloc(sizeof(CircularList));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void addElement(CircularList* list, int value) {
    ListElement* element = (ListElement*)malloc(sizeof(ListElement));
    if (element == NULL) {
        return;
    }
    element->value = value;
    if (list->head == NULL) {
        element->next = element;
        list->head = element;
    } else {
        list->tail->next = element;
        element->next = list->head;
    }
    list->tail = element;
}

//CircularList* createCircularList(int number) {
//    CircularList* list = (CircularList*)malloc(sizeof(CircularList));
//    if (list == NULL) {
//        return NULL;
//    }
//    list->head = NULL;
//    list->tail = NULL;
//
//    for (int i = 0; i < number; ++i) {
//        ListElement* element = (ListElement*)malloc(sizeof(ListElement));
//        if (element == NULL) {
//            return NULL;
//        }
//        element->value = i + 1;
//        if (list->head == NULL) {
//            element->next = element;
//            list->head = element;
//        } else {
//            list->tail->next = element;
//            element->next = list->head;
//        }
//        list->tail = element;
//    }
//    return list;
//}

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
    if (list->head == NULL) {
        return;
    }
    if (current == list->head) {
        list->head = current->next;
        list->tail->next = list->head;
    } else if (current == list->tail) {
        list->tail = previous;
        list->tail->next = list->head;
    } else {
        previous->next = current->next;
    }
    free(current);
}

void deleteList(CircularList* list) {
    if (list->head == NULL) {
        return;
    }
    ListElement* current = list->head;
    ListElement* previous = list->tail;
    while (current != list->head) {
        ListElement* next = current->next;
        deleteElement(list, current, previous);
        current = next;
        if (previous == current) {
            previous = NULL;
        }
    }
    list->head = NULL;
    list->tail = NULL;
    free(list);
}

int getListLength(CircularList* list) {
    if (list->head == NULL) {
        return 0;
    }
    int length = 0;
    ListElement* element = list->head;
    do {
        ++length;
        element = element->next;
    } while (element != list->head);
    return length;
}