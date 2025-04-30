#pragma once
#include <stdbool.h>

typedef struct CityData CityData;

// create city data
CityData* createCityData();

// reading from a file
CityData* readDataFromFile(FILE* file);

// joins cities to the capital
void conquerCities(CityData* data);

// outputs the matrix to the console
void print(int** matrix, int cities, List** citiesOfCountry);

// getting count of city
int getCity(CityData* data);

// getting count of roads
int getRoad(CityData* data);

// getting count of capitals
int getCapitalsAmount(CityData* data);

// getting matrix
int** getMatrix(CityData* data);

// getting list of cities
List** getCitiesOfCountry(CityData* data);

// deleting struct CityData
void freeMatrix(CityData* data);

// checks if all cities have been conquered
bool allMarked(bool marked[], int length);