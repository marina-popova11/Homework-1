#pragma once

#include <stdbool.h>

typedef struct HashTable HashTable;

typedef struct HashTableIterator HashTableIterator;

// creating hash table
HashTable* createTable(int size);

// inserting value to hash table
bool insertValue(HashTable* table, const char* string, int frequency);

// getting the frequency of a row in a table
bool getFrequencyByString(HashTable* table, const char* string, int* frequency);

HashTableIterator* getIterator(HashTable* table);

void getCurrent(HashTableIterator* iterator, char** string, int* frequency);

// output of the hash table to the console
void printTable(HashTable* table);

// deleting hash table
void deleteTable(HashTable* table);

// calculates the fill factor of the hash table
float loadFactor(HashTable* table);

// calculates the average length of the list
float averageListLength(HashTable* table);

// calculates the maximum length of the list
int maxListLength(HashTable* table);

// getting table`s size
int getTableSize(HashTable* table);

//returns the number of unique elements
int getTableCountOfElemenet(HashTable* table);
