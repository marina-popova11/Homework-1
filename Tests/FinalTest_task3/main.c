#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

#define MAX_VERTICES 10

int main(void) {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int veritices;
    readFromFile("file.txt", graph, &veritices);

    bfs(graph, veritices, 0);
    return 0;
}

