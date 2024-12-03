#pragma once

#include <stdbool.h>

typedef struct Node Node;

typedef struct List List;

typedef struct HashTable HashTable;

typedef struct HashTableIterator HashTableIterator;

List* createList(void);

Node* getHeadElement(List* list);

void deleteValue(List* list);

char* getValue(Node* element);

int getFrequency(Node* element);

Node* getNext(Node* element);

void setFrequency(Node* element, int frequency);

void deleteList(List* list);

HashTable* createTable(int size);

unsigned int hashFunction(const char* string);

void insertValue(HashTable* table, const char* string, int frequency);

void resizeTable(HashTable* table);

HashTableIterator* getIterator(HashTable* table);

bool getFrequencyByString(HashTable* table, const char* string, int* frequency);

bool nextStep(HashTableIterator* iterator);

void getCurrent(HashTableIterator* iterator, char** string, int* frequency);

void deleteBuckets(HashTable* table);

void printTable(HashTable* table);

void deleteTable(HashTable* table);

float loadFactor(HashTable* table);

float averageListLength(HashTable* table);

int maxListLength(HashTable* table);
