#include <stddef.h>
#include "stdio.h"
//
// Created by desperado on 18-1-19.
//
int find(int *ints, int rows, int columns, int des) {

    if (ints != NULL && rows > 0 && columns > 0) {
        int currentRow = 1;
        int currentColumn = columns;

        while (currentRow <= rows && currentColumn >= 0) {
            if (*(ints + currentRow * currentColumn - 1) > des) {
                currentColumn--;
            } else if (*(ints + currentRow * currentColumn - 1) < des) {
                currentRow++;
            } else  {
                return 1;
            }
        }
    }
    return 0;
}

//int main() {
//    int ints[3][4]  = {{1, 2, 4, 5}, {2, 4, 5, 6}, {6, 8, 10, 11}};
//
//    int is_find = find((int *) ints, 3, 4, 1);
//    printf("%d", is_find);
//    return 0;
//}
