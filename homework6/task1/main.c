#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "../List/list.h"

void printOptions(void);
void printList(List* list);
void addElementToSortedList(List* list, Value value);
void deleteElementFromSortedList(List* list, Value value);


int main() {
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
            free(list);
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
            Value place = 0;
            scanf("%d", &place);
            deleteElementFromSortedList(list, place);
            break;
        }
        case 3:
            printList(list);
            printf("\n");
            break;
        default:
            printf("There is no such operation\n");
            return 0;
        }
    }
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

void addElementToSortedList(List* list, Value value) {
    Position position = first(list);
    while (!isLast(list, position) && getValue(list, next(position)) <= value) {
        position = next(position);
    }
    addElement(list, position, value);
}

void deleteElementFromSortedList(List* list, Value value) {
    Position position = first(list);
    while (!isLast(list, position)) {
        if (getValue(list, next(position)) == value) {
            deleteElement(list, position);
            break;
        }
        position = next(position);
    }
}