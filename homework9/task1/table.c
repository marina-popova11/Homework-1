#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "table.h"
#include "List.h"

typedef struct HashTable {
    List** buckets;
    int size;
    int countUnicWords;
} HashTable;

typedef struct HashTableIterator {
    HashTable* table;
    int index;
    Node* element;
} HashTableIterator;

HashTable* createTable(int size) {
    HashTable* table = malloc(sizeof(HashTable));
    if (table == NULL) {
        return NULL;
    }
    table->size = size;
    table->countUnicWords = 0;
    table->buckets = malloc(sizeof(List*) * table->size);
    for (int i = 0; i < size; ++i) {
        table->buckets[i] = createList();
    }
    return table;
}

unsigned int hashFunction(const char* string, int size) {
    int length = strlen(string);
    unsigned int hash = 0;
    for (int i = 0; i < length; ++i) {
        hash = (hash + string[i]) * 5;
    }
    return hash % size;
}

bool insertValue(HashTable* table, const char* string, int frequency) {
    if ((float)table->countUnicWords / table->size > 0.7) {
        resizeTable(table);
    }
    unsigned int index = hashFunction(string, table->size);
    List* current = table->buckets[index];
    Node* element = getHeadElement(current);
    while (element != NULL) {
        char* elementString = getValue(element);
        if (strcmp(elementString, string) == 0) {
            setFrequency(element, frequency);
            return true;
        }
        element = getNext(element);
    }

    element = malloc(sizeof(Node));
    if (element == NULL) {
        return false;
    }
    element->word = strdup(string);
    setFrequency(element, frequency);
    element->next = table->buckets[index]->head;
    table->buckets[index]->head = element;
    ++table->countUnicWords;
    return true;
}

void deleteBuckets(HashTable* table) {
    for (int i = 0; i < table->size; ++i) {
        deleteList(table->buckets[i]);
    }
}

void resizeTable(HashTable* table) {
    int newSize = table->size * 2;
    HashTable* newTable = createTable(newSize);
    HashTableIterator* iterator = getIterator(table);
    while (nextStep(iterator)) {
        char* currentString = NULL;
        int frequency = 0;
        getCurrent(iterator, &currentString, &frequency);
        insertValue(newTable, currentString, frequency);

    }
    free(iterator);
    deleteBuckets(table);
    *table = *newTable;
    free(newTable);
}

HashTableIterator* getIterator(HashTable* table) {
    HashTableIterator* iterator = malloc(sizeof(HashTableIterator));
    if (iterator == NULL) {
        return NULL;
    }
    iterator->table = table;
    iterator->index = -1;
    iterator->element = NULL;
    return iterator;
}

bool nextStep(HashTableIterator* iterator) {
    while (iterator->element == NULL) {
        ++iterator->index;
        if (iterator->index >= iterator->table->size) {
            return false;
        }
        iterator->element = getHeadElement(iterator->table->buckets[iterator->index]);
    }
    return true;
}

void getCurrent(HashTableIterator* iterator, char** string, int* frequency) {
    *string = getValue(iterator->element);
    *frequency = getFrequency(iterator->element);
    iterator->element = getNext(iterator->element);
}

bool getFrequencyByString(HashTable* table, const char* string, int* frequency) {
    int index = hashFunction(string, table->size);
    List* list = table->buckets[index];
    Node* element = getHeadElement(list);

    while (element != NULL) {
        const char* elementString = getValue(element);
        if (strcmp(string, elementString) == 0) {
            *frequency = getFrequency(element);
            return true;
        }
        element = getNext(element);
    }

    return false;
}

void printTable(HashTable* table) {
    for (int i = 0; i < table->size; ++i) {
        List* current = table->buckets[i];
        Node* element = getHeadElement(current);
        while (element != NULL) {
            printf("%s: %d\n", getValue(element), getFrequency(element));
            element = getNext(element);
        }
    }
}

void deleteTable(HashTable* table) {
    deleteBuckets(table);
    free(table->buckets);
    free(table);
}

float loadFactor(HashTable* table) {
    int count = 0;
    for (int i = 0; i < table->size; ++i) {
        List* current = table->buckets[i];
        Node* element = getHeadElement(current);
        while (element != NULL) {
            count++;
            element = getNext(element);
        }
    }
    return (float)count / table->size;
}

float averageListLength(HashTable* table) {
    int totalLength = 0;
    int nonEmptyBuckets = 0;

    for (int i = 0; i < table->size; ++i) {
        List* current = table->buckets[i];
        Node* element = getHeadElement(current);
        int length = 0;
        while (element != NULL) {
            length++;
            element = getNext(element);
        }
        if (length > 0) {
            totalLength += length;
            nonEmptyBuckets++;
        }
    }

    return nonEmptyBuckets ? (float)totalLength / nonEmptyBuckets : 0.0;
}

int maxListLength(HashTable* table) {
    int maxLength = 0;

    for (int i = 0; i < table->size; ++i) {
        List* current = table->buckets[i];
        Node* element = getHeadElement(current);
        int length = 0;
        while (element != NULL) {
            length++;
            element = getNext(element);
        }
        if (length > maxLength) {
            maxLength = length;
        }
    }
    return maxLength;
}

int getTableSize(HashTable* table) {
    return table->size;
}

int getTableCountOfElemenet(HashTable* table) {
    return table->countUnicWords;
}