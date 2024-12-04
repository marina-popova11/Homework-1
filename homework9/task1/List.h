#pragma once

#include <stdbool.h>

typedef struct Node {
    char* word;
    int frequency;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    int length;
} List;

//typedef struct Node Node;
//
//typedef struct List List;

List* createList(void);

Node* getHeadElement(List* list);

void deleteValue(List* list);

char* getValue(Node* element);

int getFrequency(Node* element);

Node* getNext(Node* element);

void setFrequency(Node* element, int frequency);

void deleteList(List* list);