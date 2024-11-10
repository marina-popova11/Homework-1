#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "list.h"

int main() {
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        return -1;
    }
    List* list = NULL;
    if (!readFromFile(file, &list)) {
        return -1;
    }
    fclose(file);

    printf("Enter a \"1\" to sort by name\n");
    printf("Enter a \"0\" to sort by phone number\n");
    printf(">");
    int choise = 0;
    scanf("%d", &choise);
    if (choise == 1) {
        mergeSort(list, compareByName);
    }
    else if (choise == 0) {
        mergeSort(list, compareByPhone);
    }
    else {
        return -1;
    }
    printf("Sorted records:\n");
    printList(list);

    freeList(list);
    return 0;
}