/**
 * 题目: 一个数组中有两个数只出现了一次，其他都出现了两次，找出那两个数. 时间复杂度O(n).
 *
 * 思路: 这题主要考位运算.
 */

int find_first_bit_1(int num) {
    int bit_index = 0;

    while ((num & 1) == 0 && (bit_index < 8 * sizeof(int))) {
        num = num << 1;
        bit_index++;
    }
    return bit_index;
}

bool index_is_bit_1(int num, int index) {
    if (index > 31) {
        return false;
    }
    num = num << index;
    return (num & 1) == 1;
}

void find_num_apprear_once(int data[], int length, int &num1, int &num2) {
    if (data == nullptr || length < 2) {
        return;
    }

    int t = 0;
    for (int i = 0; i < length; ++i) { //对数组中的数进行异或操作. 最终的结果是两个不同的数异或的结果
        t ^= data[i];
    }

    //根据变量t, 将数组分为两个. 让不同的两个数分布在两个数组. 原理是找到t中第一个为1的位.
    int bit_1_index = find_first_bit_1(t);

    num1 = num2 = 0;
    for (int j = 0; j < length; ++j) {
        if (index_is_bit_1(data[j], bit_1_index)) {
            num1 ^= data[j];
        } else {
            num2 ^= data[j];
        }
    }
}