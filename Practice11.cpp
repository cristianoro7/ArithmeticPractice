#include <cstring>
#include <cstdio>

/**
 * 题目: 输入数字n, 按顺序打印出从1到最大的n位十进制.
 *
 * 注意点: 1. 需要考虑到大数的问题. 2. 如何判断是否已经到达最大位数
 *
 * 解决: 1. 使用字符串来解决大数溢出问题. 2. 判断字符串的第一位是否产生进位了, 如果是, 说明已经溢出了
 */


bool increment(char *number) {
    bool is_overflow = false;
    int length = strlen(number);
    int take_over = 0; //进位

    for (int i = length - 1; i >= 0; i--) {
        int sum = number[i] - '0' + take_over;

        if (i == length - 1) {
            sum++;
        }

        if (sum >= 10) { //进位处理
            if (i == 0) { //溢出了
                is_overflow = true;
            } else {
                sum -= 10;
                take_over = 1; //进位
                number[i] = '0' + sum;
            }
        } else {
            number[i] = '0' + sum;
            break;
        }
    }
    return is_overflow;
}

void printf_number(const char *number) {
    bool is_beginning_0 = true;
    int n = strlen(number);

    for (int i = 0; i < n; ++i) {
        if (number[i] != '0' && is_beginning_0) {
            is_beginning_0 = false;
        }
        if (!is_beginning_0) {
            printf("%c", number[i]);
        }
    }
    printf("\n");
}

void printf_max(int n) {
    if (n < 0) {
        return;
    }

    char *number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    while (!increment(number)) {
        printf_number(number);
    }

    delete[]number;
}

int main() {
    printf_max(2);
}

