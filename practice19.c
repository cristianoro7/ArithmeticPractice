#include <stddef.h>
#include <stdio.h>

/**
 * 题目: 输入一个矩阵, 按照从外向里以顺时针的顺序依次打印每一个数字.
 */

void print_matrix_in_circle(int **numbers, int columns, int rows, int start_index) {
    int end_x = columns - 1 - start_index;
    int end_y = rows - 1 - start_index;

    //左->右
    for (int i = start_index; i <= end_x; ++i) {
        printf("%d\t", numbers[start_index][i]);
    }

    //上->下
    if (start_index > end_y) {
        for (int j = start_index + 1; j <= end_y; ++j) {
            printf("%d\t", numbers[j][end_x]);
        }
    }

    //右->左
    if (start_index < end_x && start_index < end_y) {
        for (int i = end_x - 1; i >= start_index; --i) {
            printf("%d\t", numbers[end_y][i]);
        }
    }

    //上->下
    if (start_index < end_x && start_index < end_y - 1) {
        for (int i = end_y - 1; i >= start_index; --i) {
            printf("%d\t", numbers[i][start_index]);
        }
    }
}

void print_matrix_clock_wisely(int **numbers, int columns, int rows) {

    if (numbers == NULL || columns <= 0 || rows <= 0) {
        return;
    }

    int start_index = 0;
    while (columns > start_index * 2 && rows > start_index * 2) {
        print_matrix_in_circle(numbers, columns, rows, start_index);
        start_index++;
    }
}