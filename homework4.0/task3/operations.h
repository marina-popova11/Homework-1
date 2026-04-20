#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LENGTH 50
#define PHONE_LENGTH 30
#define NUMBER_OF_ENTRIES 100

typedef struct{
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
}person;

int readRecords(const char* filename, person* colection, int* recordsCount);
int addRecord(person* collection, int* recordNumber);
void printAllRecords(person* collection, int recordNumber);
char* findAPhone(person* collection, int recordNumber, const char* nameToSearch);
char* findAName(person* collection, int recordNumber, const char* phoneToSearch);
void saveTheData(person* collection, int recordNumber, const char* filename);