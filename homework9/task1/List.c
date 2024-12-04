#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "List.h"

//typedef struct Node {
//    char* word;
//    int frequency;
//    struct Node* next;
//} Node;
//
//typedef struct List {
//    Node* head;
//    int length;
//} List;

List* createList(void) {
    List* list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->length = 0;
    return list;
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

void deleteList(List* list) {
    while (!isEmpty(list)) {
        deleteValue(list);
    }
    free(list);
}