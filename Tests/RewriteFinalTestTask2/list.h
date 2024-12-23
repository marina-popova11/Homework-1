#pragma once

typedef struct ListElement {
    char* value;
    struct ListElement* next;
} ListElement;

typedef struct List {
    ListElement* head;
} List;

List* createList(void);

//inserting a value at the end
bool insertValueAtTheEnd(List* list, char* value);

//adding a line starting with A
bool addStringWithA(List** list);

//deleting
void deleteList(List* list);

//get listLength
int listLength(List* list);

void printList(List* list);