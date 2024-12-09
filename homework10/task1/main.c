#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "list.h"

void printMatrix(int** matrix, int cities);
bool allMarked(bool conquered[], int length);
void conquer(List* state, int** matrix, bool conquered[], int cities);

bool testMatrix() {
    int cities = 5;
    int roads = 6;
    int** testMatrix = calloc(cities + 1, sizeof(int*));
    for (int i = 1; i <= cities; ++i) {
        testMatrix[i] = calloc(cities + 1, sizeof(int*));
    }
    FILE* file = fopen("testGraph.txt", "r");
    for (int i = 1; i <= cities; ++i) {
        for (int j = 1; j <= cities; ++j) {
            fscanf(file, "%d", &testMatrix[i][j]);
        }
    }
    fclose(file);
    List** capitalsCities = calloc(cities + 1, sizeof(List*));
    bool* testMarked = calloc(cities + 1, sizeof(bool));
    capitalsCities[1] = createList();
    insert(1, capitalsCities[1]);
    testMarked[1] = true;
    capitalsCities[3] = createList();
    insert(3, capitalsCities[3]);
    testMarked[3] = true;
    int i = 1;
    while (!allMarked(testMarked, cities + 1)) {//we check if we have visited all the cities
        if (i >= cities) {
            i = 1;
        }
        while (capitalsCities[i] == NULL) {
            ++i;
            if (i >= cities) {
                i = 1;
            }
        }
        conquer(capitalsCities[i], testMatrix, testMarked, cities);
        ++i;
        if (i >= cities) {
            i = 1;
        }
    }
    free(testMarked);
    free(testMatrix);
    return listLength(capitalsCities[1]) == 2 && listLength(capitalsCities[3]) == 3;
}

int main(void) {
    if (!testMatrix()) {
        printf("Test failed!\n");
        return -1;
    }
    FILE* file = fopen("file.txt", "r");
    int cities = 0;
    fscanf(file, "%d", &cities);
    int roads = 0;
    fscanf(file, "%d", &roads);
    int** matrix = calloc(cities + 1, sizeof(int*));
    for (int i = 1; i <= cities; ++i) {
        matrix[i] = calloc(cities, sizeof(int*));
    }
    for (int i = 0; i < roads; ++i) {
        int row = 0;
        int column = 0;
        int length = 0;
        fscanf(file, "%d", &row);
        fscanf(file, "%d", &column);
        fscanf(file, "%d", &length);
        matrix[row][column] = matrix[column][row] = length;
    }
    int capitalsAmount = 0;
    fscanf(file, "%d", &capitalsAmount);
    List** citiesOfCountry = calloc(cities + 1, sizeof(List*));
    if (citiesOfCountry == NULL) {
        return -1;
    }
    bool* marked = calloc(cities + 1, sizeof(bool));
    for (int i = 0; i < capitalsAmount; i++) {
        int capital = 0;
        fscanf(file, "%d", &capital);
        citiesOfCountry[capital] = createList();
        insert(capital, citiesOfCountry[capital]);
        marked[capital] = true;
    }
    int i = 0;
    while (!allMarked(marked, cities + 1)) {//we check if we have visited all the cities
        if (i >= cities) {
            i = 1;
        }
        while (citiesOfCountry[i + 1] == NULL) {
            ++i;
            if (i >= cities) {
                i = 0;
            }
        }
        conquer(citiesOfCountry[i + 1], matrix, marked, cities);
        ++i;
        if (i >= cities) {
            i = 0;
        }
    }
    printMatrix(matrix, cities);
    for (int i = 1, j = 1; i < cities + 1; ++i) {
        if (citiesOfCountry[i] != NULL) {
            printf("Cities of %d country: ", j);
            printList(citiesOfCountry[i]);
            ++j;
        }
    }
    free(marked);
    free(matrix);
    fclose(file);
    return 0;
}

//outputs the matrix to the console
void printMatrix(int** matrix, int cities) {
    printf(" ");
    for (int i = 1; i < cities + 1; ++i) {
        printf(" %d", i);
    }
    printf("\n");
    for (int i = 1; i < cities + 1; ++i) {
        printf("%d|", i);
        for (int j = 1; j < cities + 1; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//checks if we have visited all the cities
bool allMarked(bool marked[], int length) {
    for (int i = 1; i < length; ++i) {
        if (marked[i] == false) {
            return false;
        }
    }
    return true;
}

//a function that assigns the nearest unvisited city to a list containing the capital
void conquer(List* state, int** matrix, bool marked[], int cities) {
    int nearestDistance = INT_MAX;
    int nearestCity = -1;
    int length = listLength(state);
    for (int i = 0; i < length; ++i) {
        int stateCity = accessElement(i, state);
        for (int j = 1; j <= cities; ++j) {
            int matrixElement = matrix[stateCity][j];
            if (matrixElement != 0 && marked[j] != true) {
                if (nearestDistance > matrix[stateCity][j]) {
                    nearestDistance = matrix[stateCity][j];
                    nearestCity = j;
                }
            }
        }
    }
    if (nearestCity != -1) {
        insert(nearestCity, state);
        marked[nearestCity] = true;
    }
}
