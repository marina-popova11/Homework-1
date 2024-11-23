#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "AVLTree.h"

bool createTreeTest() {
    Tree* tree = createTree();
    return tree != NULL;
}

bool insertNodeAndSearchTest() {
    Tree* tree = createTree();
    Node* root1 = NULL;
    insertNode(tree, "123", "asd", &root1);
    root1 = getNode(tree);
    insertNode(tree, "245", "fgh", &root1);
    insertNode(tree, "114", "tyu", &root1);
    char* result = searchValue(tree, "123");
    return strcmp(result, "asd") == 0;
}

bool deleteNodeFromListTest() {
    Tree* tree = createTree();
    Node* root1 = NULL;
    insertNode(tree, "123", "asd", &root1);
    root1 = getNode(tree);
    insertNode(tree, "245", "fgh", &root1);
    insertNode(tree, "114", "tyu", &root1);
    insertNode(tree, "345", "fre", &root1);
    insertNode(tree, "564", "hhh", &root1);
    insertNode(tree, "987", "mnk", &root1);
    deleteNode(tree, "245", &root1);
    return !isValueInList(tree, "245");
}

bool deleteNodeWithChildTest() {
    Tree* tree = createTree();
    Node* root1 = NULL;
    insertNode(tree, "123", "asd", &root1);
    root1 = getNode(tree);
    insertNode(tree, "245", "fgh", &root1);
    insertNode(tree, "114", "tyu", &root1);
    insertNode(tree, "345", "fre", &root1);
    insertNode(tree, "564", "hhh", &root1);
    insertNode(tree, "987", "mnk", &root1);
    deleteNode(tree, "564", &root1);
    return !isValueInList(tree, "564");
}

bool deleteNodeWithRotatesTest() {
    Tree* tree = createTree();
    Node* root1 = NULL;
    insertNode(tree, "123", "asd", &root1);
    root1 = getNode(tree);
    insertNode(tree, "245", "fgh", &root1);
    insertNode(tree, "114", "tyu", &root1);
    insertNode(tree, "345", "fre", &root1);
    insertNode(tree, "564", "hhh", &root1);
    insertNode(tree, "987", "mnk", &root1);
    insertNode(tree, "10", "ggg", &root1);
    insertNode(tree, "110", "poj", &root1);
    deleteNode(tree, "110", &root1);
    return !isValueInList(tree, "110");
}

bool deleteLeftRightRotate() {
    Tree* tree = createTree();
    Node* root1 = NULL;
    insertNode(tree, "300", "asd", &root1);
    root1 = getNode(tree);
    insertNode(tree, "345", "fre", &root1);
    insertNode(tree, "250", "fgh", &root1);
    insertNode(tree, "245", "tyu", &root1);
    insertNode(tree, "247", "hhh", &root1);
    return isValueInList(tree, "345");
}

bool tests() {
    if (!createTreeTest()) {
        printf("CreateNodeTest is failed\n");
        return false;
    }
    if (!insertNodeAndSearchTest()) {
        printf("InsertNodeAndSearchTest is failed\n");
        return false;
    }
    if (!deleteNodeFromListTest()) {
        printf("DeleteNodeFromListTest is failed\n");
        return false;
    }
    if (!deleteNodeWithChildTest()) {
        printf("DeleteNodeWithChildTest is failed\n");
        return false;
    }
    if (!deleteNodeWithRotatesTest()) {
        printf("DeleteNodeWithRotatesTest is failed\n");
        return false;
    }
    if (!deleteLeftRightRotate()) {
        printf("DeleteLeftRightRotate is failed\n");
        return false;
    }
    printf("All tests passed\n");
    return true;
}