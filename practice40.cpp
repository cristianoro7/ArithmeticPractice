/**
 * 题目: 输入一个已经排序递增的数组, 在数组中查找两个数, 题目的和正好是s. 如果有多对数字, 输出一对即可
 *
 * 思路:
 * 1. 顺序扫描比较. 时间复杂度为: O(n2)
 * 2. 利用数组递增的特性, 可以收尾两个指针来进行相加. 时间复杂度为: O(n)
 *
 * 题目二: 输入一个正数S, 打印出所有和为s的连续数字
 */

bool find_num_with_sum(int data[], int length, int sum, int &num1, int &num2) {
    if (data == nullptr || length < 0 || num1 == nullptr || num2 == nullptr) {
        return false;
    }

    int start = 0;
    int end = length - 1;

    while (start < end) {
        if (sum == data[start] + data[end]) {
            num1 = data[start];
            num2 = data[end];
            return true;
        } else if (sum > data[start] + data[end]) {
            start++;
        } else {
            end--;
        }
    }
    return false;
}

void print_num(int small, int big) {
    for (int i = small; i <= big; ++i) {
        printf("%d\t", i);
    }
}

bool find_num_wit_sum(int sum) {
    if (sum < 3) {
        return false;
    }

    int small = 1;
    int big = 2;
    int current_sum = small + big;
    int middle = (1 + sum) / 2;

    while (small < middle) {
        if (current_sum == sum) {
            print_num(small, big);
            return true;
        }

        if (current_sum > sum) {
            while (small < middle) {
                current_sum -= small;
                if (current_sum == sum) {
                    print_num(small, big);
                    return true;
                }
                small++;
            }
        }
        big++;
        current_sum += big;
    }
    return false;
}

