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

int main(void) {
    if (!testResize()) {
        printf("Test failed!\n");
        return -1;
    }
    Queue* queue = createQueue(8);
    enqueue(queue, 11);
    enqueue(queue, 12);
    enqueue(queue, 13);
    printQueue(queue);
    printf("\n");

    printf("%d", dequeue(queue));
    return 0;
}