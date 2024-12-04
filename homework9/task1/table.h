#pragma once

#include <stdbool.h>

bool tests();

typedef struct HashTable HashTable;

typedef struct HashTableIterator HashTableIterator;

HashTable* createTable(int size);

unsigned int hashFunction(const char* string, int size);

bool insertValue(HashTable* table, const char* string, int frequency);

void resizeTable(HashTable* table);

HashTableIterator* getIterator(HashTable* table);

bool getFrequencyByString(HashTable* table, const char* string, int* frequency);

bool nextStep(HashTableIterator* iterator);

void getCurrent(HashTableIterator* iterator, char** string, int* frequency);

void printTable(HashTable* table);

void deleteTable(HashTable* table);

float loadFactor(HashTable* table);

float averageListLength(HashTable* table);

int maxListLength(HashTable* table);

int getTableCountOfElemenet(HashTable* table);
