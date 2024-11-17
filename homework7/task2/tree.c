#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "tree.h"

typedef struct Node {
    int value;
    char operation;
    struct Node* leftChild;
    struct Node* rightChild;
    int isValue; //1 if it a number, 0 if it operation
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

Node* createValueNode(int value) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->isValue = 1;
    node->value = value;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

Node* createOperatoinNode(char operation, Node* leftChild, Node* rightChild) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->isValue = 0;
    node->leftChild = leftChild;
    node->rightChild = rightChild;
    node->operation = operation;
    return node;
}

Node* readSubtree(FILE* file) {
    char symbol;

    while ((symbol = fgetc(file)) == ' ');
    if (symbol == EOF) {
        return NULL;
    }

    if (symbol == '(') {
        char operation = fgetc(file);
        Node* left = readSubtree(file);
        Node* right = readSubtree(file);
        fgetc(file);
        return createOperatoinNode(operation, left, right);
    } else {
        ungetc(symbol, file);
        int value = 0;
        fscanf(file, "%d", &value);
        return createValueNode(value);
    }
    return NULL;
}

bool* readFromFile(FILE* file, Tree** tree) {
    Tree* newTree = createTree();
    newTree->root = readSubtree(file);
    *tree = newTree;
    return true;
}

int calculatingNode(Node* node) {
    if (node == NULL) {
        return -1;
    }

    if (node->isValue) {
        return node->value;
    } else {
        int leftValue = calculatingNode(node->leftChild);
        int rightValue = calculatingNode(node->rightChild);

        switch (node->operation) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            return -1;
        }
    }
    return 0;
}

int calculatingTree(Tree* tree) {
    int result = 0;
    Node* node = tree->root;
    result = calculatingNode(node);
    return result;
}

void printNodeAsTree(Node* node) {
    if (node == NULL) {
        printf("empty tree\n");
        return;
    }

    if (!node->isValue) {
        printf("(");
        printNodeAsTree(node->leftChild);
        printf("%c", node->operation);
        printNodeAsTree(node->rightChild);
        printf(")");
    } else {
        printf("%d", node->value);
    }
}

void printTree(Tree* tree) {
    printNodeAsTree(tree->root);
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

int getValue(Node* node) {
    if (node == NULL) {
        return -1;
    }
    return node->value;
}

char getOperation(Node* node) {
    if (node == NULL) {
        return -1;
    }
    return node->operation;
}
