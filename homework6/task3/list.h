#pragma once

#include <stdbool.h>

typedef struct ListElement ListElement;

typedef struct List List;

List* createList(void);

ListElement* createElement(const char* name, const char* phone);

bool addElement(List* list, const char* name, const char* phone);

bool readFromFile(FILE* file, List** list);

void split(ListElement* head, ListElement** first, ListElement** last);

ListElement* merge(ListElement* first, ListElement* second, int(*cmp)(const ListElement*, const ListElement*));

void mergeSort(ListElement** head, int (*cmp)(const ListElement*, const ListElement*));

int compareByName(const ListElement* first, const ListElement* second);

int compareByPhone(const ListElement* first, const ListElement* second);

void freeList(List* list);

void printList(List* list);