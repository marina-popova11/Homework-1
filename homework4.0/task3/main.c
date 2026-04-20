#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "operations.h"

#define NAME_LENGTH 50
#define PHONE_LENGTH 30
#define NUMBER_OF_ENTRIES 100

void printOperations(void);
bool testOpenFile();
bool testReadFromFile();

int main(void) {
    if (!testOpenFile() || !testReadFromFile()) {
        printf("Tests failed!\n");
        return 1;
    }
    person collection[NUMBER_OF_ENTRIES];

    int recordNumber = 0;
    if (readRecords("phoneDirectory.txt", collection, &recordNumber) != 0) {
        printf("Error reading database\n");
        return 1;
    }
    printOperations();

    int operations = -1;
    while (operations != 0) {
        printf(">");
        if (scanf("%d", &operations) != 1) {
            printf("Error input\n");
            return 1;
        }
        switch (operations) {
        case 0:
            return 0;
        case 1:
            addRecord(collection, &recordNumber);
            break;
        case 2:
            printAllRecords(collection, recordNumber);
            break;
        case 3:
            printf("Enter a name to search for a phone number: \n");
            char nameToSearch[NAME_LENGTH] = { '\0' };
            char nameSearch = scanf("%s", nameToSearch);
            char* searchedPhoneNumber = findAPhone(collection, recordNumber, nameToSearch);

            if (searchedPhoneNumber == NULL) {
                printf("That number doesn't exist for this name!\n");
            } else {
                printf("Found number: %s\n", searchedPhoneNumber);
            }
            break;
        case 4:
            printf("Enter a phone number to search the name: \n");
            char phoneToSearch[PHONE_LENGTH] = { '\0' };
            char phoneSearch = scanf("%s", phoneToSearch);
            char* searchedName = findAName(collection, recordNumber, phoneToSearch);

            if (searchedName == NULL) {
                printf("That name doesn't exist for this phone number!\n");
            } else {
                printf("Found name: %s\n", searchedName);
            }
            break;
        case 5:
            saveTheData(collection, recordNumber, "phoneDirectory.txt");
            break;
        default:
            printf("There is no such operation\n");
            return 0;
        }
    }
    return 0;
}

void printOperations(void) {
    printf("Operatoins:\n"
        "0. Exit\n"
        "1. Add a record(name and phone number)\n"
        "2. Print all available records\n"
        "3. Find a phone by name\n"
        "4. Find a name by phone\n"
        "5. Save the current data to a file\n\n");
}

bool testOpenFile() {
    FILE* file = fopen("testFile.txt", "r");
    if (file == NULL) {
        return false;
    }
    return true;
}

bool testReadFromFile() {
    person* collectionTest[NUMBER_OF_ENTRIES];
    int recordNumberTest = 0;
    if (readRecords("testFile.txt", collectionTest, &recordNumberTest) != 0) {
        printf("Error reading database\n");
        return false;
    }
    return recordNumberTest == 2;
}