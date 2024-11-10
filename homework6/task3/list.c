#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "list.h"

#define MAX_LENGTH 50

typedef struct ListElement {
    char* name;
    char* phoneNumber;
    struct ListElement* next;
} ListElement;

typedef struct List {
    ListElement* head;
    ListElement* tail;
} List;

List* createList(void) {
    List* list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

ListElement* createElement(const char* name, const char* phone) {
    ListElement* element = malloc(sizeof(ListElement));
    if (element == NULL) {
        return false;
    }
    strcpy(element->name, name);
    strcpy(element->phoneNumber, phone);
    element->next = NULL;
    return element;
}

bool addElement(List* list, const char* name, const char* phone) {
    ListElement* element = malloc(sizeof(ListElement));
    if (element == NULL) {
        return false;
    }
    element->name = calloc(1, sizeof(ListElement));
    element->phoneNumber = calloc(1, sizeof(ListElement));

    strcpy(element->name, name);
    strcpy(element->phoneNumber, phone);
    element->next = NULL;
    if (list->head == NULL) {
        list->head = element;
    }
    else {
        list->tail->next = element;
    }
    list->tail = element;
    return true;
}

bool readFromFile(FILE* file, List** list) {
    List* newList = createList();

    while (!feof(file)) {
        char newName[MAX_LENGTH] = { 0 };
        char newPhoneNumber[MAX_LENGTH] = { 0 };
        while (fscanf(file, "%s", newName) != EOF && fscanf(file, "%s", newPhoneNumber) != EOF) {
            addElement(newList, newName, newPhoneNumber);
        }
    }
    *list = newList;
    return true;
}

void split(ListElement* head, ListElement** first, ListElement** last) {
    ListElement* fast = head->next;
    ListElement* slow = head;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *first = head;
    *last = slow->next;
    slow->next = NULL;
}

ListElement* merge(ListElement* first, ListElement* second, int(*cmp)(const ListElement*, const ListElement*)) {
    ListElement* result = NULL;

    if (!first) {
        return second;
    }
    if (!second) {
        return first;
    }
    if (cmp(first, second) <= 0) {
        result = first;
        result->next = merge(first->next, second, cmp);
    }
    else {
        result = second;
        result->next = merge(first, second->next, cmp);
    }
    return result;
}

void mergeSort(ListElement** head, int (*cmp)(const ListElement*, const ListElement*)) {
    ListElement* first;
    ListElement* second;

    if ((*head) == NULL || (*head)->next == NULL) {
        return;
    }
    split(*head, &first, &second);
    mergeSort(&first, cmp);
    mergeSort(&second, cmp);

    *head = merge(first, second, cmp);
}

int compareByName(const ListElement* first, const ListElement* second) {
    return strcmp(first->name, second->name);
}

int compareByPhone(const ListElement* first, const ListElement* second) {
    return strcmp(first->phoneNumber, second->phoneNumber);
}

void freeList(List* list) {
    ListElement* tmp = list->head;
    while (tmp != NULL) {
        free(tmp->name);
        free(tmp->phoneNumber);
        tmp = tmp->next;
    }
    free(tmp);
}

void printList(List* list) {
    while (list->head->next != NULL) {
        printf("%s %s\n", list->head->name, list->head->phoneNumber);
        list->head = list->head->next;
    }
    printf("%s %s\n", list->head->name, list->head->phoneNumber);
}