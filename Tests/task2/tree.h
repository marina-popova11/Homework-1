#pragma once

#include <stdbool.h>
typedef struct Node Node;

typedef struct Tree Tree;

Tree* createTree(void);

Node* createNode(int key);

//Àdding an element
bool insertNode(Tree* tree, int key);

//Delete element
void freeNode(Node* node);

//Delete tree
bool freeTree(Tree* tree);

//From the list to the tree
void sortingTree(Node* root, int array[], int* index);

//Sorting from tree to list
void sortingArray(int array[], int length);