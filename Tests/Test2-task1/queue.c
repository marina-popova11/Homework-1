#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

typedef struct QueueElement {
    int value;
    struct QueueElement* next;
} QueueElement;

typedef struct Queue {
    int size;
    int countOfElement;
    int* array;
    int front;
    int back;
} Queue;

Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }
    queue->size = size;
    queue->countOfElement = 0;
    queue->front = 0;
    queue->back = 0;
    queue->array = malloc(size * sizeof(int));
    return queue;
}

void freeQueue(Queue* queue) {
    if (queue == NULL) {
        return;
    }
    free(queue->array);
    free(queue);
}

bool isFull(Queue* queue) {
    return queue->countOfElement == queue->size;
}

bool resizeQueue(Queue* queue) {
    int newSize = queue->size * 2;
    int* newArray = malloc(newSize * sizeof(int));
    if (newArray == NULL) {
        return false;
    }
    for (int i = 0; i < queue->size; ++i) {
        newArray[i] = queue->array[(queue->front + i)];
    }
    free(queue->array);
    queue->array = newArray;
    queue->size = newSize;
    queue->front = 0;
    queue->back = queue->countOfElement;
    return true;
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        resizeQueue(queue);
    }
    queue->array[queue->back] = value;
    queue->back = (queue->back + 1) % queue->size;
    ++queue->countOfElement;
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return -1;
    }
    int value = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    --queue->countOfElement;
    return value;
}

void printQueue(Queue* queue) {
    for (int i = 0; i < queue->countOfElement; ++i) {
        int index = (queue->front + i) % queue->size;
        printf("%d ", queue->array[index]);
    }
}

int getSize(Queue* queue) {
    return queue->size;
}