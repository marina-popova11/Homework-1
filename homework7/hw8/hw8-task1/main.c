#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "AVLTree.h"

void printOptions(void);

int main(void) {
    if (!tests()) {
        return -1;
    }
    Tree* tree = createTree();
    Node* root1 = NULL;
    int option = -1;
    while (option != 0) {
        printOptions();
        printf(">");
        if (scanf("%d", &option) != 1) {
            printf("Error input\n");
            continue;
            return 1;
        }
        switch (option) {
        case 1: {
            char key[256] = { 0 };
            char value[256] = { 0 };
            printf("Enter the key to add to the dictionary:\n");
            scanf("%s", key);
            printf("Enter the value to add to the dictionary:\n");
            scanf("%s", value);
            if (getNode(tree) == NULL) {
                insertNode(tree, key, value, &root1);
                root1 = getNode(tree);
            }
            else {
                insertNode(tree, key, value, &root1);
            }
            break;
        }
        case 2: {
            printf("Enter the key to retrieve value: ");
            char key[256] = { 0 };
            scanf("%s", key);
            char* result = searchValue(tree, key);
            if (result != NULL) {
                printf("Value for this key: %s\n", result);
            }
            else {
                printf("There are no values for the given key\n");
            }
            break;
        }
        case 3: {
            printf("Enter the key for the deleting: ");
            char key[256] = { 0 };
            scanf("%s", key);
            deleteNode(tree, key, &root1);
            break;
        }
        case 4: {
            printf("Enter the key for verification\n");
            char key[256] = { 0 };
            scanf("%s", key);
            if (isValueInList(tree, key)) {
                printf("There is a value for this key\n");
            }
            else {
                printf("There is no such key in the dictionary\n");
            }
            break;
        }
        case 0:
            break;
        default:
            printf("There is no such operation\n");
            continue;
            return -1;
        }
    }
    freeTree(tree);
    free(tree);
    return 0;
}

void printOptions(void) {
    printf("1 - Assign a value to a key\n");
    printf("2 - Retrieve a value by key\n");
    printf("3 - Delete key and value\n");
    printf("4 - Check the value of a given key in the dictionary\n");
    printf("0 - Exit\n");
}
