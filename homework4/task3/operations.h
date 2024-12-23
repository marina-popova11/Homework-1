#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LENGTH 50
#define PHONE_LENGTH 30
#define NUMBER_OF_ENTRIES 100

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Person;

// reading from a file, adding to a collection
int readRecords(const char* filename, Person* colection, int* recordsCount);

// adding an entry
int addRecord(Person* collection, int* recordNumber);

//output of all entries to the console
void printAllRecords(Person* collection, int recordNumber);

//search for a phone number by name
char* findAPhone(Person* collection, int recordNumber, const char* nameToSearch);

//search for a name by phone number
char* findAName(Person* collection, int recordNumber, const char* phoneToSearch);

//save all data
void saveTheData(Person* collection, int recordNumber, const char* filename);