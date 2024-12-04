#pragma once

typedef struct Queue Queue;

void enqueue(Queue* queue, int value);

int dequeue(Queue* queue);

Queue* createQueue(void);

