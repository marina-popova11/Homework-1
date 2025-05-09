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
    return calloc(1, sizeof(List));
}

ListElement* createElement(const char* name, const char* phone) {
    ListElement* element = malloc(sizeof(ListElement));
    if (element == NULL) {
        return false;
    }
    element->name = strdup(name);
    element->phoneNumber = strdup(phone);
    element->next = NULL;
    return element;
}

bool addElement(List* list, const char* name, const char* phone) {
    ListElement* element = malloc(sizeof(ListElement));
    if (element == NULL) {
        return false;
    }
    element->name = strdup(name);
    element->phoneNumber = strdup(phone);

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
    ListElement tmp = { 0, NULL };
    ListElement* tail = &tmp;
    tmp.next = NULL;

    while (first != NULL && second != NULL) {
        if (cmp(first, second) <= 0) {
            tail->next = first;
            first = first->next;
        } else {
            tail->next = second;
            second = second->next;
        }
        tail = tail->next;
    }
    if (first != NULL) {
        tail->next = first;
    } else {
        tail->next = second;
    }
    return tmp.next;
}

void mergeSort(ListElement** head, int (*cmp)(const ListElement*, const ListElement*)) {
    if ((*head) == NULL || (*head)->next == NULL) {
        return;
    }
    ListElement* first = NULL;
    ListElement* second = NULL;
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