#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "list.h"

bool positionSearchTest();

bool tests() {
    if (!createCircularListTest()) {
        printf("CreateCircularListTest is failed!\n");
        return false;
    }
    if (!deleteElementTest()) {
        printf("DeleteElementTest is failed!\n");
        return false;
    }
    return true;
}
int main(void) {
    if (!tests() || !positionSearchTest()) {
        return -1;
    }

    int n = 0, m = 0;
    printf("Enter the number of warriors:\n");
    scanf("%d", &n);
    printf("Enter the killing step:\n");
    scanf("%d", &m);

    int lastSurvivor = positionSearch(n, m);
    printf("The last surviving warrior is in position: %d", lastSurvivor);
    return 0;
}

int positionSearch(int numberOfWarriors, int killingStep) {
    CircularList* list = createCircularList(numberOfWarriors);
    ListElement* current = getHead(list);
    ListElement* previous = getTail(list);

    while (current != getNext(current)) {
        for (int count = 1; count < killingStep; ++count) {
            previous = current;
            current = getNext(current);
        }
        printf("A warrior in position %d was killed\n", getValue(current));
        deleteElement(list, current, previous);
        current = getNext(previous);
    }
    int lastSurvivor = getValue(current);
    free(current);
    free(list);
    return lastSurvivor;
}

bool positionSearchTest() {
    int number = 22;
    int step = 4;
    return positionSearch(number, step) == 3;
}