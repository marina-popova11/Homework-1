#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "../List/list.h"
#include "sortedList.h"

void printOptions(void);
void printList(List* list);
void addElementToSortedList(List* list, Value value);
void deleteElementFromSortedList(List* list, Value value);

bool addToSortedListTest() {
    List* list = createList();
    addElementToSortedList(list, 25);
    addElementToSortedList(list, 45);
    addElementToSortedList(list, 35);
    Position position = first(list);
    position = next(position);
    position = next(position);
    position = next(position);
    if (getValue(list, position) == 45) {
        deleteList(list);
        return true;
    }
    deleteList(list);
    return false;
}

bool deleteFromSortedListTest() {
    List* list = createList();
    addElementToSortedList(list, 25);
    addElementToSortedList(list, 45);
    addElementToSortedList(list, 35);
    deleteElementFromSortedList(list, 25);
    Position position = first(list);
    position = next(position);
    if (getValue(list, position) == 35) {
        position = next(position);
        if (getValue(list, position) == 45) {
            deleteList(list);
            return true;
        }
    }
    deleteList(list);
    return false;
}

int main() {
    if (!addToSortedListTest() || !deleteFromSortedListTest()) {
        printf("Tests failed!\n");
        return -1;
    }
    List* list = createList();
    Position position = first(list);
    printOptions();
    int option = -1;
    while (option != 0) {
        printf(">");
        if (scanf("%d", &option) != 1) {
            printf("Error input\n");
            return 1;
        }
        switch (option) {
        case 0:
            break;
        case 1: {
            printf("Enter the value for the adding: ");
            Value value = 0;
            scanf("%d", &value);
            addElementToSortedList(list, value);
            break;
        }
        case 2: {
            printf("Enter the value for the deleting: ");
            Value value = 0;
            scanf("%d", &value);
            deleteElementFromSortedList(list, value);
            break;
        }
        case 3:
            printList(list);
            printf("\n");
            break;
        default:
            printf("There is no such operation\n");
            continue;
        }
    }
    deleteList(list);
    return 0;
}

void printOptions(void) {
    printf("0 - Exit\n");
    printf("1 - Add a value to the sorted list\n");
    printf("2 - Delete a value from list\n");
    printf("3 - Print list\n");
}

void printList(List* list) {
    Position position = first(list);
    position = next(position);
    while (position != NULL) {
        printf("%d ", getValue(list, position));
        position = next(position);
    }
}