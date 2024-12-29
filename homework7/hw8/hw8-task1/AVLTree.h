#pragma once

#include <stdbool.h>

typedef struct Node Node;

typedef struct Tree Tree;

// create tree
Tree* createTree(void);

// checking if there is a node in the tree with such a key
char* searchValue(Tree* tree, const char* key);

// getting node from tree
Node* getNode(Tree* tree);

// inserting a node
void insertNode(Tree* tree, const char* key, const char* value, Node** root1);

// deleting a node
void deleteNode(Tree* tree, const char* key, Node** root1);

// checking if there is a node in the tree with such a key
bool isValueInList(Tree* tree, const char* key);

// deleting tree
bool freeTree(Tree* tree);

bool tests();