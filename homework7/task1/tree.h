#pragma once

typedef struct Node Node;

typedef struct Tree Tree;

// create tree
Tree* createTree(void);

// create new tree node 
Node* createNode(int key, const char* value);

// inserting a node
bool insertNode(Tree* tree, int key, const char* value);

// searching for a node by key in a tree
char* searchByKey(Tree* tree, int key);

// checking if there is a node in the tree with such a key
bool isValueInList(Tree* tree, int key);

// deleting a key from the tree
void deleteKey(Tree* tree, int key);

// deleting the tree
void freeTree(Tree* tree);

// getting a root key
int getRootKey(Tree* tree);

// getting node`s value
char* getNodeValue(Node* node);
