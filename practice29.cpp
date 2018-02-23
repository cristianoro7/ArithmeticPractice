#include <vector>
#include <set>

/**
 * 题目: 输入n个整数, 找出其中最小的k个数.
 *
 * 思路:
 * 1. 将数组排序后, 前面k个数字就是我们要求的. 这种方法的时间复杂度为O(nlogn). 不推荐使用
 * 2. 利用快速排序法. 找到k -1的index. 时间复杂福为O(n). 但是需要修改数组的内容
 * 3. 利用一个容器放k个数字, 然后遍历n. 将每个数字与容器的最大数比较, 如果小于的话, 替换调容器的最大数, 否则不做处理. 时间复杂度为: O(nlogk). 需要选取 删除. 插入. 和查找的
 * 时间复杂度都小于O(logk)的数据结构. 可以选取红黑树, 或者最大堆.
 */

int partition(int *numbers, int start, int end) {
    int p = numbers[start];

    while (start < end) {

        while (start < end && numbers[start] < p) {
            start++;
        }
        while (start < end && numbers[end] > p) {
            end++;
        }
        int temp = numbers[start];
        numbers[start] = numbers[end];
        numbers[end] = temp;
    }

    if (numbers[start] > p) {
        int temp = numbers[start];
        numbers[start] = p;
        p = temp;
    }
    return start;
}

//第二种
void get_least_number(int *input, int n, int *output, int k) {
    if (input == nullptr || n <= 0 || output == nullptr || k > n || k <= 0) {
        return;
    }

    int start = 0;
    int end = n - 1;

    int index = partition(input, start, end);
    while (index != k - 1) {
        if (index > k - 1) {
            end = index - 1;
            index = partition(input, start, end);
        } else {
            start = index + 1;
            index = partition(input, start, end);
        }
    }

    for (int i = 0; i < k; ++i) {
        output[i] = input[i];
    }
}

//第三种
void get_least_numbers(std::vector data, std::multiset<int, std::greater<int> > output, int k) {
    if (data.size() < k || k <= 0) {
        return;
    }

    std::vector::const_iterator iterator = data.begin();
    for (; iterator != data.end(); iterator++) {
        if (output.size() < k) {
            output.insert(*iterator);
        } else {
            std::multiset<int, std::greater<int>>::iterator it = output.begin();
            if (iterator < it) {
                output.erase(it);
                output.insert(iterator);
            }
        }
    }
}