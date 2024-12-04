#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"

bool testResize() {
    Queue* queue = createQueue(8);
    enqueue(queue, 11);
    enqueue(queue, 12);
    enqueue(queue, 13);
    enqueue(queue, 11);
    enqueue(queue, 12);
    enqueue(queue, 13);
    enqueue(queue, 11);
    enqueue(queue, 12);
    enqueue(queue, 13);
    enqueue(queue, 11);
    enqueue(queue, 12);
    enqueue(queue, 13);
    return getSize(queue) == 16; 
}

bool testDequeue() {
    Queue* queue = createQueue(8);
    enqueue(queue, 11);
    enqueue(queue, 12);
    enqueue(queue, 13);
    return dequeue(queue) == 11;
}

int main(void) {
    if (!testResize() || !testDequeue()) {
        printf("Tests failed!\n");
        return -1;
    }
    Queue* queue = createQueue(8);
    enqueue(queue, 11);
    enqueue(queue, 12);
    enqueue(queue, 13);
    enqueue(queue, 15);
    enqueue(queue, 16);
    enqueue(queue, 6);
    printQueue(queue);
    dequeue(queue);
    printf("\n");

    printf("%d", dequeue(queue));
    return 0;
}