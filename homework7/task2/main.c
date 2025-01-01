#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

bool createTreeTest() {
    Tree* tree = createTree();
    if (tree != NULL) {
        freeTree(tree);
        return true;
    }
    freeTree(tree);
    return false;
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
    Node* node = createOperationNode(operation, left, right);
    if (getOperation(node) == '>') {
        freeTree(tree);
        return true;
    }
    freeTree(tree);
    return false;
}

bool calculateTest() {
    FILE* fileTest = fopen("fileTest.txt", "r");
    if (fileTest == NULL) {
        return false;
    }
    Tree* tree = createTree();
    if (!readFromFile(fileTest, &tree)) {
        return false;
    }
    fclose(fileTest);
    if (calculateTree(tree) == 4) {
        freeTree(tree);
        return true;
    }
    freeTree(tree);
    return false;
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
    if (!calculateTest()) {
        printf("CalculateTest is failed\n");
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

    int result = calculateTree(tree);
    printf("%d", result);

    freeTree(tree);
    return 0;
}