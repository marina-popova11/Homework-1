#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "List.h"

typedef struct Node {
    char* word;
    int frequency;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    int length;
} List;

Node* addElement(List* list) {
    Node* element = malloc(sizeof(Node));
    if (element == NULL) {
        return false;
    }
    element->word = NULL;
    element->frequency = 0;
    element->next = NULL;
    if (list->head == NULL) {
        list->head = element;
        list->length = 1;
        return element;
    }
    list->head->next = element;
    list->head = element;
    ++list->length;
    return element;
}

List* createList(void) {
    return calloc(1, sizeof(List));
}

Node* getHeadElement(List* list) {
    return list->head;
}

bool isEmpty(List* list) {
    return list->head == NULL;
}

void deleteValue(List* list) {
    if (isEmpty(list)) {
        return;
    }
    --list->length;
    Node* element = list->head;
    list->head = list->head->next;
    free(element->word);
    free(element);
}

char* getValue(Node* element) {
    return element->word;
}

int getFrequency(Node* element) {
    return element->frequency;
}

Node* getNext(Node* element) {
    return element->next;
}

void setFrequency(Node* element, int frequency) {
    element->frequency = frequency;
}

void setValue(Node* element, char* value) {
    element->word = strdup(value);
}

void deleteList(List* list) {
    while (!isEmpty(list)) {
        deleteValue(list);
    }
    free(list);
}