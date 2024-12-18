#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

#define MAX_VERTICES 10

bool readFromFile(const char* filename, int graph[MAX_VERTICES][MAX_VERTICES], int* vertices) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return false;
    }

    fscanf(file, "%d", vertices);
    for (int i = 0; i < *vertices; ++i) {
        for (int j = 0; j < *vertices; ++j) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }

    fclose(file);
    return true;
}

void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex) {
    int visited[MAX_VERTICES] = { 0 };
    int queue[MAX_VERTICES];
    int front = -1, back = -1;
    int i = 0;

    queue[++back] = startVertex;
    visited[startVertex] = 1;

    printf("The order of traversal in width: ");

    while (front != back) {
        ++front;
        int currentVertex = queue[front];
        printf("%d ", currentVertex);

        for (i = 0; i < vertices; ++i) {
            if (graph[currentVertex][i] >= 1 && !visited[i]) {
                queue[++back] = i; //adding to the queue
                visited[i] = 1; //we mark it as visited
            }
        }
    }
    printf("\n");
}

//void printBfsResult(int* result, int index) {
//    for (int i = 0; i < index; ++i) {
//        printf("%d ", result[i]);
//    }
//    printf("\n");
//}
