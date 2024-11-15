#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "tree.h"

typedef struct Node {
    int key;
    char* value;
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

Node* createNode(int key, const char* value) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->value = calloc(256, sizeof(char));
    strcpy(node->value, value);
    node->key = key;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

bool insertNode(Tree* tree, int key, const char* value) {
    Node** current = &(tree->root);
    while (*current != NULL) {
        if ((*current)->key > key) {
            current = &((*current)->leftChild);
        } else if ((*current)->key < key) {
            current = &((*current)->rightChild);
        } else {
            free((*current)->value);
            (*current)->value = calloc(256, sizeof(char));
            strcpy((*current)->value, value);
            return true;
        }
    }
    *current = createNode(key, value);
    return true;
}

char* searchByKey(Tree* tree, int key) {
    Node* current = tree->root;

    while (current != NULL) {
        if (current->key > key) {
            current = current->leftChild;
        } else if (current->key < key) {
            current = current->rightChild;
        } else {
            return current->value;
        }
    }
    return NULL;
}

bool isValueInList(Tree* tree, int key) {
    Node* current = tree->root;

    while (current != NULL) {
        if (current->key > key) {
            current = current->leftChild;
        }
        else if (current->key < key) {
            current = current->rightChild;
        }
        else {
            return true;
        }
    }
    return false;
}

// removes node, returns parent
bool deleteNode(Node* parent, Node* node, int key, Node** newNode, Node** nodeParent) {
    if (node == NULL) {
        return false;
    }
    if (node->key > key) {
        return deleteNode(node, node->leftChild, key, newNode, nodeParent);
    } else if (node->key < key) {
        return deleteNode(node, node->rightChild, key, newNode, nodeParent);
    } else {
        free(node->value);
        if (node->leftChild == NULL && node->rightChild == NULL) {
            free(node);
            *newNode = NULL;
            *nodeParent = parent;
            return true;
        } else if (node->leftChild == NULL || node->rightChild == NULL) {
            if (node->leftChild != NULL) {
                *newNode = node->leftChild;
            }
            if (node->rightChild != NULL) {
                *newNode = node->rightChild;
            }
            free(node);
            *nodeParent = parent;
            return true;
        } else {
            Node* right = node->rightChild;
            Node* leftmost = right;
            while (leftmost != NULL && leftmost->leftChild != NULL) {
                leftmost = leftmost->leftChild;
            }

            leftmost->leftChild = node->leftChild;
            *newNode = right;

            free(node);

            *nodeParent = parent;
            return true;
        }
    }
    return true;
}

void deleteKey(Tree* tree, int key) {
    if (tree == NULL) {
        return;
    }

    Node* newNode = NULL;
    Node* nodeParent = NULL;
    if (!deleteNode(NULL, tree->root, key, &newNode, &nodeParent)) {
        return;
    }

    // if parent is NULL, then its root
    if (nodeParent == NULL) {
        tree->root = newNode;
    } else {
        if (nodeParent->key > key) {
            nodeParent->leftChild = newNode;
        } else {
            nodeParent->rightChild = newNode;
        }
    }
}

void freeNode(Node* node) {
    if (node == NULL) {
        return;
    }
    freeNode(node->leftChild);
    freeNode(node->rightChild);

    free(node->value);
    free(node);
}

bool freeTree(Tree* tree) {
    freeNode(tree->root);
    free(tree);
    return true;
}

int getRootKey(Tree* tree) {
    return tree->root->key;
}

char* getNodeValue(Node* node) {
    return node->value;
}
/*
void printNodeAsTree(Node* node, int depth) {
    if (node == NULL) {
        printf("empty tree\n");
        return;
    }
    if (depth != 0) {
        printf(" |");
    }

    for (int i = 1; i < depth; ++i) {
        printf("  |");
    }

    if (depth != 0) {
        printf(" = ");
    }

    printf("%d : %s\n", node->key, node->value);
    if (node->leftChild != NULL) {
        printNodeAsTree(node->leftChild, depth + 1);
    }
    if (node->rightChild != NULL) {
        printNodeAsTree(node->rightChild, depth + 1);
    }

}

void printTree(Tree* tree) {
    printNodeAsTree(tree->root, 0);
}
*/