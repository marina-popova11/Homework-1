#pragma once

#include <stdbool.h>
typedef struct Node Node;

typedef struct Tree Tree;

Tree* createTree(void);

Node* createNode(int key);

bool insertNode(Tree* tree, int key);

void freeNode(Node* node);

bool freeTree(Tree* tree);

void sortingTree(Node* root, int array[], int* index);

void sortingArray(int array[], int length);