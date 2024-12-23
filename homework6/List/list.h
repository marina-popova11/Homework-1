#pragma once

#include <stdbool.h>

typedef struct ListElement ListElement;

typedef struct List List;

typedef ListElement* Position;

typedef int Value;

// create list
List* createList(void);

// adding new element in list by position
bool addElement(List* list, Position position, Value value);

// deleting element from list by position
bool deleteElement(List* list, Position position);

// getting value from list by position
Value getValue(List* list, Position position);

//changing the value
void setValue(List* list, Position position, Value value);

//assigning the first position
Position first(List* list);

//assigning the next position
Position next(Position position);

//checking for the last element
bool isLast(List* list, Position position);

//checking for the existence of a value
bool isValid(List * list, Position position);
