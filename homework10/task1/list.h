#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List List;

// inserting an element
bool insert(int value, List* list);

// output of all lists to the console 
void printList(List* list);

// creating a list
List* createList();

// allows you to find an item with the specified index in the list
int accessElement(int index, List* list, int* value);

// counts the length of the list
int listLength(List* list);

// deleting list
void freeList(List* list);