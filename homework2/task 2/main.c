#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_LENGTH 100000
#define LENGTH 15

void Babble(int* array, int arrayLength);
void Counting(int* array, int arrayLength);
static void print_array(int* A, int N);
static bool testCorrect();

int main() {
	if (!testCorrect()) {
		printf("Tests failed\n");
		return 0;
	}

	srand(time(NULL));

	int* array = malloc(ARRAY_LENGTH * sizeof(int));
	if (array == NULL) {
		printf("Failed to allicated array\n");
		return 1;
	}
	int num;
	for (int i = 0; i < ARRAY_LENGTH; ++i) {
		num = rand() % 50;
		array[i] = num;
	}

	clock_t startTimeCounting;
	startTimeCounting = clock();
	Counting(array, ARRAY_LENGTH);

	double timeCounting = clock() - startTimeCounting;
	printf("Processor time spent on sorting by counting: %f seconds\n", (float)timeCounting / CLOCKS_PER_SEC);

	clock_t startTimeBabble;
	startTimeBabble = clock();
	Babble(array, ARRAY_LENGTH);

	double timeBabble = clock() - startTimeBabble;
	printf("Processor time spent on bubble sorting: %f seconds\n", (float)timeBabble / CLOCKS_PER_SEC);
	free(array);

	return 0;
}

void Babble(int* array, int arrayLength) {
	for (int i = 0; i < arrayLength - 1; ++i) {
		for (int j = 0; j < arrayLength - 1 - i; ++j) {
			if (array[j] > array[j + 1]) {
				int num = array[j];
				array[j] = array[j + 1];
				array[j + 1] = num;
			}

		}

	}
}

void Counting(int* array, int arrayLength) {
	int maxElement = 0;
	for (int i = 0; i < arrayLength; ++i)
		if (array[i] > maxElement)
			maxElement = array[i];

	int* countArray = malloc((maxElement + 1) * sizeof(int));
	if (countArray == NULL) {
		printf("Failed to allicated array\n");
		return 1;
	}
	memset(countArray, 0, (maxElement + 1) * sizeof(int));

	for (int i = 0; i < arrayLength; ++i)
		countArray[array[i]]++;

	int pointer = 0;
	for (int i = 0; i <= maxElement; ++i) {
		for (int j = 0; j < countArray[i]; ++j) {
			array[pointer++] = i;
		}
	}
	free(countArray);
}

static void print_array(int* A, int N) {
	printf("[");
	for (int i = 0; i < N; i++)
		printf(" %d ", A[i]);
	printf("]");
	printf("\n");
}

static bool testCorrect() {
	int array[LENGTH] = { 2, 14, 6, 0, 4, 5, 3, 7, 12, 8, 4, 5, 3, 2, 0 };

	int sortedArray[LENGTH] = { 0, 0, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 8, 12, 14 };

	Counting(array, LENGTH);
	for (int i = 0; i < LENGTH; ++i) {
		if (array[i] != sortedArray[i])
			return false;
	}
	Babble(array, LENGTH);
	for (int i = 0; i < LENGTH; ++i) {
		if (array[i] != sortedArray[i])
			return false;
	}
	return true;
}