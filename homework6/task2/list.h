#pragma once

typedef struct ListElement ListElement;

typedef struct CircularList CircularList;

CircularList* createCircularList(int number);

ListElement* getNext(ListElement* element);

int getValue(ListElement* element);

void deleteElement(CircularList* list, ListElement* current, ListElement* previous);

CircularList* getHead(CircularList* list);

CircularList* getTail(CircularList* list);
