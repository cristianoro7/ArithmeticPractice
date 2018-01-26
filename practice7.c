#include <stdlib.h>

/**
 * 旋转数组的最小数字(考察二分查找法)
 *
 * 问题: 把一个数组开始若干元素搬到数组的末尾, 我们称为数组的旋转. 输入一个递增排序的数组的一个旋转, 输出该数组的最小值.
 *
 * 实现思路: 直接方法: 遍历, 但是时间复杂度为O(n). 利用二分查找法, 时间复杂度为O(logN)
 * 根据题目特征. 旋转后是一个有序数组. 那么旋转之前则可以分为两个有序数组.
 * 使用两个指针, 分别指向数组的头和尾. 第一个元素总是大于或者等于最后一个元素.
 * 接着求这两个指针的中间数.
 * 如果这个中间数大于第一个数的话, 说明中间数目存在第一个有序数组中, 将第一个指针指向中间数. 如果中间数小于第二个数, 说明中间数位于第二个有序数组,
 * 将第二个指针指向中间数.
 *
 * 如此循环, 知道第一个指针指向第一个有序数组的末尾, 第二个指针指向第二个有序数组的开头. 此时找到最小了, 它是第二个指针指向的值.
 *
 * 特殊情况:
 * 1. 搬0个数到数组的末尾, 说明数组本身是有序的. 此时, 直接返回第一个数.
 * 2. 第一个指针指向的数, 第二个指针指向的数, 中间数 这三个数组相等时, 我们只能顺序查找.
 */


/**
 * 顺序查找, 当 index1, index2和mid_index这三个数字相等时, 只能使用顺序查找
 * @param numbers
 * @param start
 * @param end
 * @return
 */
int get_mid_by_order(int *numbers, int start, int end) {
    int r = numbers[start];
    for (int i = start + 1; i <= end; ++i) {
        if (r > numbers[i]) {
            r = numbers[i];
        }
    }
    return r;
}

int mind(int *numbers, int length) {

    if (numbers == 0 || length <= 0) {
        exit(-1);
    }

    int index1 = 0;
    int index2 = length - 1;
    int mid_index = index1;

    while (numbers[index1] >= numbers[index2]) {

        if (index2 - index1 == 1) { //找到最小的数字了
            mid_index = index2; //对应的小标为index2
            break;
        }

        mid_index = (index1 + index2) / 2;

        //顺序查找, 当 index1, index2和mid_index这三个数字相等时, 只能使用顺序查找
        if (numbers[index1] == numbers[index2] && numbers[index2] == numbers[mid_index]) {
            return get_mid_by_order(numbers, index1, index2);
        }

        if (numbers[index1] <= numbers[mid_index]) { //中间数字出现在第一个有序数数组中
            index1 = mid_index;
        } else if (numbers[index2] >= numbers[mid_index]) { //中间数字出现在第二个有序数数组中
            index2 = mid_index;
        }
    }

    return numbers[mid_index];
}