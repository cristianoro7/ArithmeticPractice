#include <cstdlib>

/*
 * 题目: 数字在排序的数组中出现的次数.
 *
 * 思路:
 * 1, 顺序扫描
 * 2. 利用二分查找法
 */

int get_first_k(int data[], int start, int end, int k) {
    if (start > end) {
        return -1;
    }

    int mid = (start + end) / 2;

    if (data[mid] == k) {
        if ((data[mid - 1] != k && mid > 0) || mid == 0) {
            return mid;
        } else {
            end = mid - 1;
        }
    } else if (data[mid] > k) {
        end = mid - 1;
    } else {
        start = mid + 1;
    }

    return get_first_k(data, start, end, k);
}

int get_last_k(int data[], int start, int end, int k) {
    if (start > end) {
        return -1;
    }

    int mid = (start + end) / 2;

    if (data[mid] == k) {
        if ((data[mid + 1] != k && mid < end) || mid < end) {
            return mid;
        } else {
            start = mid + 1;
        }
    } else if (data[mid] > k) {
        end = mid - 1;
    } else {
        start = mid + 1;
    }

    return get_last_k(data, start, end, k);
}

int get_num_of_k(int data[], int length, int k) {
    int num = 0;
    if (data != nullptr && length > 0) {
        int first = get_first_k(data, 0, length - 1, k);
        int last = get_last_k(data, 0, length - 1, k);

        if (first > -1 && last > -1) {
            num = last - first + 1;
        }
    }
    return num;
}