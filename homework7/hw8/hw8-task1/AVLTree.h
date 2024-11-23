#pragma once

#include <stdbool.h>

typedef struct Node Node;

typedef struct Tree Tree;

Tree* createTree(void);

Node* createNode(const char* key, const char* value);

char* searchValue(Tree* tree, const char* key);

Node* getNode(Tree* tree);

Node* checkBalanceAndRotates(int balance, Node* node, Node** root1);

int getHeight(Node* node);

int getBalance(Node* node);

Node* leftLeftRotate(Node* node, Node** root1);

Node* leftRightRotate(Node* node, Node** root1);

Node* rightRightRotate(Node* node, Node** root1);

Node* rightLefttRotate(Node* node, Node** root1);

Node* insertValue(Node* node, const char* key, const char* value, Node** root1);

void insertNode(Tree* tree, const char* key, const char* value, Node** root1);

Node* deleteValue(Node* node, const char* key, Node** root1);

void deleteNode(Tree* tree, const char* key, Node** root1);

bool isValueInList(Tree* tree, const char* key);

bool freeTree(Tree* tree);

void freeNode(Node* node);

bool tests();
