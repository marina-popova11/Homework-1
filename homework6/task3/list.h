#pragma once

#include <stdbool.h>

typedef struct ListElement ListElement;

typedef struct List List;

// creating list
List* createList(void);

// creating element
ListElement* createElement(const char* name, const char* phone);

// adding element to list
bool addElement(List* list, const char* name, const char* phone);

// reading data from file
bool readFromFile(FILE* file, List** list);

// divides the list into parts
void split(ListElement* head, ListElement** first, ListElement** last);

// sorts the parts
void mergeSort(ListElement** head, int (*cmp)(const ListElement*, const ListElement*));

// compare by name
int compareByName(const ListElement* first, const ListElement* second);

// compare by phone number
int compareByPhone(const ListElement* first, const ListElement* second);

// deleting list
void freeList(List* list);

// outputs the list to the console
void printList(List* list);