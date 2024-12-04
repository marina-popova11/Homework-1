#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "tree.h"

typedef struct Node {
    int key;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

Tree* createTree(void) {
    Tree* tree = malloc(sizeof(Tree));
    if (tree == NULL) {
        return NULL;
    }
    tree->root = NULL;
    return tree;
}

Node* createNode(int key) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->key = key;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

bool insertNode(Tree* tree, int key) {
    Node** current = &(tree->root);
    while (*current != NULL) {
        if ((*current)->key > key) {
            current = &((*current)->leftChild);
        }
        else if ((*current)->key < key) {
            current = &((*current)->rightChild);
        }
    }
    *current = createNode(key);
    return true;
}

void freeNode(Node* node) {
    if (node == NULL) {
        return;
    }
    freeNode(node->leftChild);
    freeNode(node->rightChild);

    free(node);
}

bool freeTree(Tree* tree) {
    freeNode(tree->root);
    free(tree);
    return true;
}

void sortingTree(Node* root, int array[], int* index) {
    if (root == NULL) {
        return;
    }
    sortingTree(root->leftChild, array, index);
    array[*index] = root->key;
    ++(*index);
    sortingTree(root->rightChild, array, index);
}

void sortingArray(int array[], int length) {
    Tree* tree = createTree();
    for (int i = 0; i < length; ++i) {
        insertNode(tree, array[i]);
    }
    int index = 0;
    sortingTree(tree->root, array, &index);
    freeTree(tree);
}