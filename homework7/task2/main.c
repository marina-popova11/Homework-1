#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

bool createTreeTest() {
    Tree* tree = createTree();
    return tree != NULL;
}

bool createValueNodeTest() {
    int value = 12;
    Node* node = createValueNode(value);
    return getValue(node) == 12;
}

bool createOperationNodeTest() {
    Tree* tree = createTree();
    Node* left = NULL;
    Node* right = NULL;
    char operation = '>';
    Node* node = createOperatoinNode(operation, left, right);
    return getOperation(node) == '>';
}

bool calculatingTest() {
    FILE* fileTest = fopen("fileTest.txt", "r");
    if (fileTest == NULL) {
        return false;
    }
    Tree* tree = createTree();
    if (!readFromFile(fileTest, &tree)) {
        return false;
    }
    fclose(fileTest);
    return calculatingTree(tree) == 4;
}

bool tests() {
    if (!createTreeTest()) {
        printf("CreateTreeTest is failed\n");
        return false;
    }
    if (!createValueNodeTest()) {
        printf("CreateValueNodeTest is failed\n");
        return false;
    }
    if (!createOperationNodeTest()) {
        printf("CreateOperationNodeTest is failed\n");
        return false;
    }
    if (!calculatingTest()) {
        printf("CalculatingTest is failed\n");
        return false;
    }
    printf("All tests passed\n");
    return true;
}

int main(void) {
    if (!tests()) {
        return -1;
    }

    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        return -1;
    }

    Tree* tree = createTree();
    if (!readFromFile(file, &tree)) {
        return -1;
    }

    fclose(file);

    printf("A tree: ");
    printTree(tree);
    printf("\n");

    int result = calculatingTree(tree);
    printf("%d", result);

    freeTree(tree);
    return 0;
}