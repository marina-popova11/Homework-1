#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

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
    element->next = list->head;
    list->head = element;
}

List* createList() {
    return calloc(1, sizeof(List));
}

int listLength(List* list) {
    if (list->head == NULL) {
        return 0;
    }
    Node* element = list->head;
    int length = 1;
    while (element->next != NULL) {
        element = element->next;
        ++length;
    }
    return length;
}

int accessElement(int index, List* list) {
    if (list == NULL) {
        return 0;
    }
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

void freeList(List* list) {
    if (list == NULL) {
        return;
    }
    Node* element = list->head;
    Node* nextElement = NULL;
    while (element != NULL) {
        nextElement = element->next;
        free(element);
        element = nextElement;
    }
    free(list);
}
