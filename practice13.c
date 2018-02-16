#include <stddef.h>

/**
 * 题目: 输入一个整数数组, 实现一个函数爱调整该数组中数字的顺序, 使得所有奇数位于数组的前半部分,
 * 所有偶数位于数组的后半部分
 *
 * 思路: 将数组分成两部分, 维护两个指针, 分别指向头和尾, 然后一个向后移动, 一个向前移动, 接着交换数字
 */

_Bool is_even(int n) {
    return (n & 1 == 0);
}

void reorder(int *data, unsigned int length, _Bool (*func)(int)) {
    if (data == NULL || length <= 0) {
        return;
    }

    int *begin = data;
    int *end = data + length - 1;

    while (begin < end) {
        while (begin < end && !func(*begin)) {
            begin++;
        }
        while (begin < end && !func(*end)) {
            end++;
        }

        if (begin < end) {
            int t = *begin;
            *begin = *end;
            *end = t;
        }
    }
}

void reorder_odd_even(int *data, unsigned int length) {
    reorder(data, length, is_even);
}