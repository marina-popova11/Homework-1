#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "AVLTree.h"

typedef struct Node {
    const char* key;
    const char* value;
    Node* leftChild;
    Node* rightChild;
    int balance;
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

Node* createNode(const char* key, const char* value) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->key = strdup(key);
    node->value = strdup(value);
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->balance = 1;
    return node;
}

char* searchValue(Tree* tree, const char* key) {
    Node* node = tree->root;
    if (node == NULL) {
        return NULL;
    }
    while (node != NULL) {
        if (strcmp(node->key, key) < 0) {
            node = node->rightChild;
        }
        else if (strcmp(node->key, key) > 0) {
            node = node->leftChild;
        }
        else {
            return node->value;
        }
    }
    return NULL;
}

Node* checkBalanceAndRotates(int balance, Node* node, Node** root1) {
    assert(balance <= 2 && balance >= -2);
    if (balance == 2) {
        assert(getBalance(node->leftChild) == 1 || getBalance(node->leftChild) == -1);
        if (getBalance(node->leftChild) == 1) { //LL imBalance
            return leftLeftRotate(node, root1);
        }
        if (getBalance(node->leftChild) == -1) { //LR imBalance
            return leftRightRotate(node, root1);
        }
    }
    if (balance == -2) {
        assert(getBalance(node->rightChild) == 1 || getBalance(node->rightChild) == -1);
        if (getBalance(node->rightChild) == 1) {
            return rightLefttRotate(node, root1);
        }
        if (getBalance(node->rightChild) == -1) {
            return rightRightRotate(node, root1);
        }
    }
}

int getHeight(Node* node) {
    int leftSubTreeHeight = node->leftChild ? node->leftChild->balance : 0;
    int rightSubTreeHeight = node->rightChild ? node->rightChild->balance : 0;
    int result = leftSubTreeHeight > rightSubTreeHeight ? leftSubTreeHeight : rightSubTreeHeight;
    return result + 1;
}

int getBalance(Node* node) {
    int leftSubTreeHeight = node->leftChild ? node->leftChild->balance : 0;
    int rightSubTreeHeight = node->rightChild ? node->rightChild->balance : 0;
    int result = leftSubTreeHeight - rightSubTreeHeight;
    return result;
}

Node* leftLeftRotate(Node* node, Node** root1) {
    Node* left = node->leftChild;
    if (node == *root1) {
        *root1 = left;
    }
    node->leftChild = left->rightChild;
    left->rightChild = node;
    if ((*root1)->leftChild == node) {
        (*root1)->leftChild = left;
    }

    node->balance = getHeight(node);
    left->balance = getHeight(left);
    return left;
}

Node* leftRightRotate(Node* node, Node** root1) {
    Node* left = node->leftChild;
    Node* leftRight = left->rightChild;
    if (node == *root1) {
        *root1 = leftRight;
    }
    node->leftChild = leftRight->rightChild;
    left->rightChild = leftRight->leftChild;
    leftRight->rightChild = node;
    leftRight->leftChild = left;

    left->balance = getHeight(left);
    node->balance = getHeight(node);
    leftRight->balance = getHeight(leftRight);
    return leftRight;
}

Node* rightRightRotate(Node* node, Node** root1) {
    Node* right = node->rightChild;
    if (node == *root1) {
        *root1 = right;
    }
    node->rightChild = right->leftChild;
    right->leftChild = node;
    if ((*root1)->rightChild == node) {
        (*root1)->rightChild = right;
    }
    node->balance = getHeight(node);
    right->balance = getHeight(right);
    return right;
}

Node* rightLefttRotate(Node* node, Node** root1) {
    Node* right = node->rightChild;
    Node* rightLeft = right->leftChild;
    if (node == *root1) {
        *root1 = rightLeft;
    }
    node->rightChild = rightLeft->leftChild;
    right->leftChild = rightLeft->rightChild;
    rightLeft->leftChild = node;
    rightLeft->rightChild = right;

    node->balance = getHeight(node);
    right->balance = getHeight(right);
    rightLeft->balance = getHeight(rightLeft);
    return rightLeft;
}

Node* insertValue(Node* node, const char* key, const char* value, Node** root1) {
    if (node == NULL) {
        return createNode(key, value);
    }
    if (strcmp(node->key, key) < 0) {
        node->rightChild = insertValue(node->rightChild, key, value, root1);
    }
    else if (strcmp(node->key, key) > 0) {
        node->leftChild = insertValue(node->leftChild, key, value, root1);
    }
    else {
        free(node->value);
        node->value = strdup(value);
        return node;
    }

    node->balance = getHeight(node);
    int balance = getBalance(node);

    //checkBalanceAndRotates(balance, node, root1);
    assert(balance <= 2 && balance >= -2);
    if (balance == 2) {
        assert(getBalance(node->leftChild) == 1 || getBalance(node->leftChild) == -1);
        if (getBalance(node->leftChild) == 1) { //LL imBalance
            return leftLeftRotate(node, root1);
        }
        if (getBalance(node->leftChild) == -1) { //LR imBalance
            return leftRightRotate(node, root1);
        }
    }
    if (balance == -2) {
        assert(getBalance(node->rightChild) == 1 || getBalance(node->rightChild) == -1);
        if (getBalance(node->rightChild) == 1) {
            return rightLefttRotate(node, root1);
        }
        if (getBalance(node->rightChild) == -1) {
            return rightRightRotate(node, root1);
        }
    }
    return node;
}

void insertNode(Tree* tree, const char* key, const char* value, Node** root1) {
    tree->root = insertValue(tree->root, key, value, root1);
}

Node* getNode(Tree* tree) {
    return tree->root;
}
Node* deleteValue(Node* node, const char* key, Node** root1) {
    if (node == NULL) {
        return node;
    }
    if (strcmp(node->key, key) < 0) {
        node->rightChild = deleteValue(node->rightChild, key, root1);
    }
    else if (strcmp(node->key, key) > 0) {
        node->leftChild = deleteValue(node->leftChild, key, root1);
    }
    else {
        free(node->value);
        if (node->rightChild == NULL && node->leftChild == NULL) {
            free(node);
            return NULL;
        }
        else if (node->leftChild == NULL || node->rightChild == NULL) {
            Node* tmp = NULL;
            if (node->leftChild != NULL) {
                tmp = node->leftChild;
            }
            else {
                tmp = node->rightChild;
            }
            free(node);
            return tmp;
        }
        else {
            Node* right = node->rightChild;
            Node* leftmost = right;
            while (leftmost != NULL && leftmost->leftChild != NULL) {
                leftmost = leftmost->leftChild;
            }
            node->value = leftmost->value;
            leftmost->value = NULL;
            node->key = strdup(leftmost->key);
            node->rightChild = deleteValue(node->rightChild, node->key, root1);
            return node;
        }
    }
    node->balance = getHeight(node);
    int balance = getBalance(node);

    //checkBalanceAndRotates(balance, node, &root1);
    assert(balance <= 2 && balance >= -2);
    if (balance == 2) {
        assert(getBalance(node->leftChild) <= 1 && getBalance(node->leftChild) >= -1);
        if (getBalance(node->leftChild) == 1 || getBalance(node->leftChild) == 0) { //LL imBalance
            return leftLeftRotate(node, root1);
        }
        if (getBalance(node->leftChild) == -1) { //LR imBalance
            return leftRightRotate(node, root1);
        }
    }
    if (balance == -2) {
        assert(getBalance(node->rightChild) <= 1 && getBalance(node->rightChild) >= -1);
        if (getBalance(node->rightChild) == 1) {
            return rightLefttRotate(node, root1);
        }
        if (getBalance(node->rightChild) == -1 || getBalance(node->rightChild) == 0) {
            return rightRightRotate(node, root1);
        }
    }
    return node;
}

void deleteNode(Tree* tree, const char* key, Node** root1) {
    if (tree == NULL) {
        return;
    }
    if (!deleteValue(tree->root, key, root1)) {
        return;
    }
}

bool isValueInList(Tree* tree, const char* key) {
    Node* current = tree->root;

    while (current != NULL) {
        if (strcmp(current->key, key) > 0) {
            current = current->leftChild;
        }
        else if (strcmp(current->key, key) < 0) {
            current = current->rightChild;
        }
        else {
            return true;
        }
    }
    return false;
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