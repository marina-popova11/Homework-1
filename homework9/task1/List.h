#pragma once

#include <stdbool.h>

typedef struct Node Node;

typedef struct List List;

// creating list
List* createList(void);

// adding element to list
Node* addElement(List* list);

// getting list`s head element
Node* getHeadElement(List* list);

// deleting value
void deleteValue(List* list);

// getting value
char* getValue(Node* element);

// getting frequency
int getFrequency(Node* element);

// getting next element
Node* getNext(Node* element);

// changing value
void setFrequency(Node* element, int frequency);

// deleting list
void deleteList(List* list);

// changes the value of the element
void setValue(Node* element, char* value);