#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "tree.h"

void printOptions(void);

bool createNodeTest() {
    Tree* tree = createTree();
    return tree != NULL;
}

bool insertNodeAndIsValueInListTest() {
    Tree* tree = createTree();
    insertNode(tree, 12, "123");
    insertNode(tree, 34, "456");
    insertNode(tree, 9, "3");
    return isValueInList(tree, 9);
}

bool deleteNodeWithoutChildrenTest() {
    Tree* tree = createTree();
    insertNode(tree, 12, "3");
    insertNode(tree, 7, "5");
    insertNode(tree, 4, "15");

    deleteKey(tree, 4);
    return !isValueInList(tree, 4);
}

bool deleteNodeWithOneChildTest() {
    Tree* tree = createTree();
    insertNode(tree, 12, "3");
    insertNode(tree, 7, "5");
    insertNode(tree, 14, "15");
    insertNode(tree, 21, "14");
    insertNode(tree, 24, "1");

    deleteKey(tree, 21);

    return !isValueInList(tree, 21);
}

bool deleteNodeWithbothChildrenTest() {
    Tree* tree = createTree();
    insertNode(tree, 12, "3");
    insertNode(tree, 7, "5");
    insertNode(tree, 14, "15");
    insertNode(tree, 21, "14");
    insertNode(tree, 13, "1");

    deleteKey(tree, 13);

    return !isValueInList(tree, 13);
}

bool deleteNodeFromRoot() {
    Tree* tree = createTree();
    insertNode(tree, 12, "3");
    insertNode(tree, 7, "5");
    insertNode(tree, 14, "15");
    insertNode(tree, 21, "14");
    insertNode(tree, 13, "1");

    deleteKey(tree, 12);

    return getRootKey(tree) == 14;
}

bool searchByKeyTest() {
    Tree* tree = createTree();
    insertNode(tree, 12, "3");
    insertNode(tree, 7, "511");
    insertNode(tree, 14, "15");
    insertNode(tree, 21, "14");
    insertNode(tree, 24, "1");

    char* string = searchByKey(tree, 7);
    return !strcmp(string, "511");
}

bool tests() {
    if (!createNodeTest()) {
        printf("CreateNodeTest is failed\n");
        return false;
    }
    if (!insertNodeAndIsValueInListTest()) {
        printf("InsertNodeAndIsValueInListTest is failed\n");
        return false;
    }
    if (!deleteNodeWithoutChildrenTest()) {
        printf("DeleteNodeWithoutChildrenTest is failed\n");
        return false;
    }
    if (!deleteNodeWithOneChildTest()) {
        printf("DeleteNodeWithOneChildTest is failed\n");
        return false;
    }
    if (!deleteNodeWithbothChildrenTest()) {
        printf("DeleteNodeWithbothChildrenTest is failed\n");
        return false;
    }
    if (!deleteNodeFromRoot()) {
        printf("deleteNodeFromRoot is failed\n");
        return false;
    }
    if (!searchByKeyTest()) {
        printf("SearchByKeyTest is failed\n");
        return false;
    }
    printf("All tests passed\n");
    return true;
}

int main(void) {
    if (!tests()) {
        return -1;
    }
    Tree* tree = createTree();
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
                int key = 0;
                char value[256] = { 0 };
                printf("Enter the key to add to the dictionary:\n");
                scanf("%d", &key);
                printf("Enter the value to add to the dictionary:\n");
                scanf("%s", value);
                insertNode(tree, key, value);
                break;
            }
            case 2: {
                printf("Enter the key to retrieve value: ");
                int key = 0;
                scanf("%d", &key);
                char* result = searchByKey(tree, key);
                if (result != NULL) {
                    printf("Value for this key: %s\n", result);
                } else {
                    printf("There are no values for the given key\n");
                }
                break;
            }
            case 3: {
                printf("Enter the key for the deleting: ");
                int key = 0;
                scanf("%d", &key);
                deleteKey(tree, key);
                break;
            }
            case 4: {
                printf("Enter the key for verification\n");
                int key = 0;
                scanf("%d", &key);
                if (isValueInList(tree, key)) {
                    char* tmp = searchByKey(tree, key);
                    printf("There is a value for this key - %s", tmp);
                } else {
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
    return 0;
}

void printOptions(void) {
    printf("1 - Assign a value to a key\n");
    printf("2 - Retrieve a value by key\n");
    printf("3 - Delete key and value\n");
    printf("4 - Check the value of a given key in the dictionary\n");
    printf("0 - Exit\n");
}