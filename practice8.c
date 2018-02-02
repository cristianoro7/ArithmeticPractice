/**
 * 实现斐波那契数列
 *
 * 实现方法:
 * 1: 递归: 效率低, 需要计算很多重复的节点, 时间复杂度以N的指数递增
 * 2:　循环: 时间复杂度为O(n)
 */

int fibonacci(unsigned int n) {
    int r[2] = {0, 1};

    if (n < 2) {
        return r[n];
    }

    int pre = r[0];
    int next = r[1];
    int final_result = 0;
    for (int i = 2; i <= n; ++i) {
        final_result = pre + next;
        pre = next;
        next = final_result;
    }
    return final_result;
}