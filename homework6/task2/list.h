#pragma once

typedef struct ListElement ListElement;

typedef struct CircularList CircularList;

// create circular list
CircularList* createCircularList(int number);

//getting next element
ListElement* getNext(ListElement* element);

// getting element`s value
int getValue(ListElement* element);

// deleting element from list
void deleteElement(CircularList* list, ListElement* current, ListElement* previous);

// getting head element from list
CircularList* getHead(CircularList* list);

// getting tail element from list
CircularList* getTail(CircularList* list);
