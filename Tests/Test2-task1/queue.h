#pragma once

typedef struct Queue  Queue;

//Create new queue
Queue* createQueue(int size);

//Delete queue
void freeQueue(Queue* queue);

//�hecking if the queue is full
bool isFull(Queue* queue);

//�hanging the size
bool resizeQueue(Queue* queue);

//�dding an element to an array
void enqueue(Queue* queue, int value);

//�aking an element out of your head
int dequeue(Queue* queue);

void printQueue(Queue* queue);

//Taking a size of queue
int getSize(Queue* queue);
