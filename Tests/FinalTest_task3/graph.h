#pragma once
#include <stdbool.h>

#define MAX_VERTICES 10

//reads data from a file
bool readFromFile(const char* filename, int graph[MAX_VERTICES][MAX_VERTICES], int* vertices);

//makes a wide detour
void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex);

////print graph
//void printBfsResult(int* result, int index);