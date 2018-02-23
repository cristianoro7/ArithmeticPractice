/**
 * 题目: 数组中有一个数字出现的次数超过数组长度的一半, 请找出这个数字.
 *
 * 思路:
 * 1. 利用快速排序法的分区找到数组的中位数, 然后再查看出现的次数. 这种方法需要改变数组的数字
 * 2. 利用一个数字表示数组出现的次数最多的数字, 一个数表示出现最多的数. 然后再查看出现的次数. 这种方法不需要改变数组的数字
 */

//第二种方法
bool more_than_half_num(int *numbers, int length, int &found_number) {
    if (numbers == nullptr || length <= 0) {
        return false;
    }

    int times = 0;
    int result = 0;

    for (int i = 0; i < length; ++i) {
        if (times == 0) {
            result = numbers[i];
            times++;
        } else if (numbers[i] == result) {
            times++;
        } else {
            times--;
        }
    }

    int r_t = 0; //result变量在数组出现次数
    for (int j = 0; j < length; ++j) {
        if (numbers[j] == result) {
            r_t++;
        }
    }
    if (r_t * 2 >= length) {
        found_number = result;
        return true;
    }
    return false;
}

