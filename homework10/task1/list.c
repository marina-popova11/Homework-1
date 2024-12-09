#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

void printList(List* list) {
    Node* element = list->head;
    if (element == NULL) {
        printf("The list is empty!\n");
        return;
    }
    while (element != NULL) {
        printf("%d ", element->data);
        element = element->next;
    }
    printf("\n");
}

void insert(int value, List* list) {
    Node* element = malloc(sizeof(Node));
    if (element == NULL) {
        return;
    }
    element->data = value;
    element->next = NULL;
    if (list->head == NULL) {
        list->head = element;
    }
    else {
        element->next = list->head->next;
        list->head->next = element;
    }
}

List* createList() {
    List* list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    return list;
}

int listLength(List* list) {
    Node* element = list->head;
    int length = 1;
    while (element->next != NULL) {
        element = element->next;
        ++length;
    }
    return length;
}

int accessElement(int index, List* list) {
    Node* element = list->head;
    for (int i = 0; i < index; ++i) {
        element = element->next;
        if (element == NULL) {
            printf("Error: index out of range\n");
            return -1;;
        }
    }
    return element->data;
}

