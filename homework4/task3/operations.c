#include "operations.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int readRecords(const char* filename, Person* collection, int* recordsCount) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return 1;
    }

    char newName[NAME_LENGTH] = { '\0' };
    char newPhone[PHONE_LENGTH] = { '\0' };
    int i = 0;

    while (fscanf(file, "%s", newName) != EOF && fscanf(file, "%s", newPhone) != EOF) {
        strcpy(collection[i].name, newName);
        strcpy(collection[i].phone, newPhone);
        ++i;
    }
    fclose(file);

    *recordsCount = i;

    return 0;
}

int addRecord(Person* collection, int* recordNumber) {
    if (*recordNumber >= NUMBER_OF_ENTRIES) {
        printf("The base is completely full, there is not enough space\n");
        return 1;
    }

    char newName[NAME_LENGTH] = { '\0' };
    char newPhone[PHONE_LENGTH] = { '\0' };
    Person newRecord = { {'\0'}, {'\0'} };

    printf("Enter the name: ");
    char name2 = scanf("%s", newName);
    strcpy(newRecord.name, newName);

    printf("Enter the phone number: ");
    char phone2 = scanf("%s", newPhone);
    strcpy(newRecord.phone, newPhone);

    collection[*recordNumber] = newRecord;
    (*recordNumber)++;
    printf("\nThe entry was successfully added\n");
    return 0;
}

void printAllRecords(Person* collection, int recordNumber) {
    for (int i = 0; i < recordNumber; ++i) {
        printf("%s %s\n", collection[i].name, collection[i].phone);
    }
}

char* findAPhone(Person* collection, int recordNumber, const char* nameToSearch) {
    for (int i = 0; i < recordNumber; ++i) {
        if (strcmp(nameToSearch, collection[i].name) == 0) {
            return collection[i].phone;
        }
    }
    return NULL;
}

char* findAName(Person* collection, int recordNumber, const char* phoneToSearch) {
    for (int i = 0; i < recordNumber; ++i) {
        if (strcmp(phoneToSearch, collection[i].phone) == 0) {
            return collection[i].name;
        }
    }
    return NULL;
}

void saveTheData(Person* collection, int recordNumber, const char* filename) {
    FILE* file = fopen(filename, "w");
    for (int i = 0; i < recordNumber; ++i) {
        fprintf(file, "%s %s\n", collection[i].name, collection[i].phone);
    }
    printf("Data successfully saved!\n");
    fclose(file);
}