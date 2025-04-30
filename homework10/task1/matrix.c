#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "matrix.h"

typedef struct CityData {
    int cities;
    int roads;
    int** matrix;
    int capitalsAmount;
    List** citiesOfCountry;
} CityData;

CityData* createCityData() {
    return calloc(1, sizeof(CityData));
}

CityData* readDataFromFile(FILE* file) {
    CityData* data = malloc(sizeof(CityData));
    if (!data) {
        return NULL;
    }

    fscanf(file, "%d", &data->cities);
    fscanf(file, "%d", &data->roads);

    data->matrix = calloc(data->cities + 1, sizeof(int*));
    if (data->matrix == NULL) {
        freeMatrix(data);
        return NULL;
    }
    for (int i = 1; i <= data->cities; ++i) {
        data->matrix[i] = calloc(data->cities + 1, sizeof(int));
        if (data->matrix[i] == NULL) {
            freeMatrix(data);
            return NULL;
        }
    }

    for (int i = 0; i < data->roads; ++i) {
        int row = 0;
        int column = 0;
        int length = 0;
        fscanf(file, "%d %d %d", &row, &column, &length);
        data->matrix[row][column] = data->matrix[column][row] = length;
    }

    fscanf(file, "%d", &data->capitalsAmount);
    data->citiesOfCountry = calloc(data->cities + 1, sizeof(List*));
    if (data->citiesOfCountry == NULL) {
        free(data);
        return NULL;
    }

    bool* marked = calloc(data->cities + 1, sizeof(bool));
    for (int i = 0; i < data->capitalsAmount; i++) {
        int capital = 0;
        fscanf(file, "%d", &capital);
        data->citiesOfCountry[capital] = createList();
        insert(capital, data->citiesOfCountry[capital]);
        marked[capital] = true;
    }

    free(marked);

    return data;
}

void conquer(List* state, int** matrix, bool marked[], int cities) {
    int nearestDistance = INT_MAX;
    int nearestCity = -1;
    int length = listLength(state);
    for (int i = 0; i < length; ++i) {
        int stateCity = 0;
        accessElement(i, state, &stateCity);
        for (int j = 1; j <= cities; ++j) {
            int matrixElement = matrix[stateCity][j];
            if (matrixElement != 0 && !marked[j]) {
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

bool allMarked(bool marked[], int length) {
    for (int i = 1; i < length; ++i) {
        if (!marked[i]) {
            return false;
        }
    }
    return true;
}

void conquerCities(CityData* data) {
    bool* marked = calloc(getCity(data) + 1, sizeof(bool));
    int i = 0;

    while (!allMarked(marked, getCity(data) + 1)) {
        if (i >= getCity(data)) {
            i = 1;
        }
        while (getCitiesOfCountry(data)[i] == NULL) {
            ++i;
            if (i >= getCity(data)) {
                i = 0;
            }
        }
        conquer(getCitiesOfCountry(data)[i], getMatrix(data), marked, getCity(data));
        ++i;
        if (i >= getCity(data)) {
            i = 0;
        }
    }
}

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

void print(int** matrix, int cities, List** citiesOfCountry) {
    printMatrix(matrix, cities);
    for (int j = 1; j <= cities; ++j) {
        if (citiesOfCountry[j] != NULL) {
            printf("Cities of %d country: ", j);
            printList(citiesOfCountry[j]);
        }
    }
}

int getCity(CityData* data) {
    if (data == NULL) {
        return 0;
    }
    return data->cities;
}

int getRoad(CityData* data) {
    if (data == NULL) {
        return 0;
    }
    return data->roads;
}

int** getMatrix(CityData* data) {
    if (data == NULL) {
        return 0;
    }
    return data->matrix;
}

int getCapitalsAmount(CityData* data) {
    if (data == NULL) {
        return 0;
    }
    return data->capitalsAmount;
}

List** getCitiesOfCountry(CityData* data) {
    if (data == NULL) {
        return 0;
    }
    return data->citiesOfCountry;
}

void freeMatrix(CityData* data) {
    for (int i = 1; i <= getCity(data); ++i) {
        free(getMatrix(data)[i]);
        freeList(getCitiesOfCountry(data)[i]);
    }
    free(getMatrix(data));
    free(getCitiesOfCountry(data));
    free(data);
}