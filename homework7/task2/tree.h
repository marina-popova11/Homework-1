#pragma once

typedef struct Node Node;

typedef struct Tree Tree;

Tree* createTree(void);

Node* createValueNode(int value);

Node* createOperatoinNode(char operation, Node* leftChild, Node* rightChild);

Node* readSubtree(FILE* file);

bool* readFromFile(FILE* file, Tree** tree);

int calculatingTree(Tree* tree);

int calculatingNode(Node* node);

void printNodeAsTree(Node* node);

void printTree(Tree* tree);

void freeNode(Node* node);

bool freeTree(Tree * tree);

int getValue(Node* node);

char getOperation(Node* node);