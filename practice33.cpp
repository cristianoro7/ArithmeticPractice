/**
 * 题目: 把只包含因子2、3或5的数称为丑数. 求按从小到大的顺序的第1500个丑数.
 *
 * 思路:
 * 1. 循环查找. 低效. 不是丑数的我们都得计算
 * 2. 开辟一个数组, 记录已经出现的丑数. 高效, 但是需要额外的空间
 */

int min(int num1, int num2, int num3) {
    if (num1 < num2) {
        if (num1 < num3) {
            return num1;
        } else {
            return num3;
        }
    } else {
        if (num2 < num3) {
            return num2;
        } else {
            return num3;
        }
    }
}

int get_ugly_number(int index) {
    if (index <= 0) {
        return 0;
    }

    int *ugly_number = new int[index];
    ugly_number[0] = 1;
    int next_ugly_num_index = 1;
    int *muliply_2 = ugly_number;
    int *muliply_3 = ugly_number;
    int *muliply_5 = ugly_number;

    while (next_ugly_num_index < index) {
        int min = min(*muliply_2 * 2, *muliply_3 * 3, *muliply_5 * 5);
        ugly_number[next_ugly_num_index] = min;

        while (*muliply_2 * 2 <= ugly_number[next_ugly_num_index]) {
            muliply_2++;
        }
        while (*muliply_3 * 3 <= ugly_number[next_ugly_num_index]) {
            muliply_3++;
        }
        while (*muliply_5 * 5 <= ugly_number[next_ugly_num_index]) {
            muliply_5++;
        }
        next_ugly_num_index++;
    }
    int ugly = ugly_number[next_ugly_num_index - 1];
    delete[]ugly_number;
    return ugly;
}
