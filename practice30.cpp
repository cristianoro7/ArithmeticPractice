/**
 * 题目: 输入一个数组, 数组里有正数也有负数. 求所有子数组的和的最大值. 时间复杂福要求为O(n)
 */
bool is_valid = true;

int find_greatest_sum_of_sub_array(int *data, int length) {
    if (data == nullptr || length <= 0) {
        is_valid = false;
        return 0;
    }

    int current_num = 0;
    int greatest_sum = 0;

    for (int i = 0; i < length; ++i) {
        if (current_num <= 0) {
            current_num = data[i];
        } else {
            current_num += data[i];
        }

        if (current_num > greatest_sum) {
            greatest_sum = current_num;
        }
    }
    return greatest_sum;
}