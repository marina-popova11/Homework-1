#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "matrix.h"

bool testReadDataFromFile() {
    FILE* testFile = fopen("testGraph.txt", "r");
    if (!testFile) {
        printf("Failed to open file!\n");
        return -1;
    }
    CityData* testData = readDataFromFile(testFile);
    fclose(testFile);
    if (testData == NULL) {
        return false;
    }
    if (getCity(testData) != 5 || getRoad(testData) != 6 || getCapitalsAmount(testData) != 2) {
        freeMatrix(testData);
        return false;
    }
    if (getMatrix(testData)[1][2] != 3 || getMatrix(testData)[1][3] != 4) {
        freeMatrix(testData);
        return false;
    }
    freeMatrix(testData);
    return true;
}

bool testAllMarked() {
    bool marked1[] = { false, true, true, true };
    bool marked2[] = { true, true, true };

    bool result1 = !allMarked(marked1, 4);
    bool result2 = allMarked(marked2, 3);

    return !(result1 && result2);
}

bool tests() {
    if (!testReadDataFromFile()) {
        printf("TestReadDataFromFile is failed\n");
        return false;
    }
    if (!testAllMarked()) {
        printf("TestAllMarked is failed\n");
        return false;
    }
    printf("All tests passed\n");
}

int main(void) {
    if (!tests()) {
        printf("Tests failed!\n");
        return -1;
    }

    FILE* file = fopen("file.txt", "r");
    if (!file) {
        printf("Failed to open file!\n");
        return -1;
    }

    CityData* cityData = readDataFromFile(file);
    if (!cityData) {
        printf("Failed to read data from file!\n");
        fclose(file);
        return -1;
    }
    fclose(file);
    conquerCities(cityData);
    print(getMatrix(cityData), getCity(cityData), getCitiesOfCountry(cityData));

    freeMatrix(cityData);
    return 0;
}

