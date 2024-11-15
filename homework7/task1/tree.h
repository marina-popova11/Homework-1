#pragma once

typedef struct Node Node;

typedef struct Tree Tree;

Tree* createTree(void);

Node* createNode(int key, const char* value);

bool insertNode(Tree* tree, int key, const char* value);

char* searchByKey(Tree* tree, int key);

bool isValueInList(Tree* tree, int key);

void deleteKey(Tree* tree, int key);

//void printTree(Tree* tree);

bool freeTree(Tree* tree);

int getRootKey(Tree* tree);

char* getNodeValue(Node* node);
