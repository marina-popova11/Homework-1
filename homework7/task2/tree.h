#pragma once

typedef struct Node Node;

typedef struct Tree Tree;

// create tree
Tree* createTree(void);

// create a node with a numeric value
Node* createValueNode(int value);

// create a node with an operation
Node* createOperatoinNode(char operation, Node* leftChild, Node* rightChild);

// reading each subtree starting from the root
Node* readSubtree(FILE* file);

// reading from a file starting from the root
bool* readFromFile(FILE* file, Tree** tree);

// calculating the value of an expression in a tree
int calculateTree(Tree* tree);

// output of the expression to the console
void printTree(Tree* tree);

// deleting the tree
bool freeTree(Tree * tree);

// getting node`s value
int getValue(Node* node);

// getting node`s operation
char getOperation(Node* node);