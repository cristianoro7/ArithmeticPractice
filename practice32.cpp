#include <zconf.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

/**
 * 题目: 输入一个正整数数组, 把数组里面所有数字拼接起来一个数, 打印能拼接的所有数字最小的一个
 */

const int g_max_number_length = 10;

char *g_string_combine_1 = new char[g_max_number_length * 2 + 1];
char *g_string_combine_2 = new char[g_max_number_length * 2 + 1];

int compare(const void *str1, const void *str2) {
    strcpy(g_string_combine_1, *(const char **) str1);
    strcat(g_string_combine_1, *(const char **) str2);

    strcpy(g_string_combine_2, *(char **) str2);
    strcat(g_string_combine_2, *(char **) str1);

    return strcmp(g_string_combine_1, g_string_combine_2);
}

void print_min_number(int *numbers, int length) {
    if (numbers == nullptr || length <= 0) {
        return;
    }

    char **str_num = (char **) new int[length];
    for (int i = 0; i < length; ++i) {
        str_num[i] = new char[g_max_number_length + 1];
        sprintf(str_num[i], "%d", numbers[i]);
    }
    qsort(str_num, length, sizeof(char *), compare);

    for (int j = 0; j < length; ++j) {
        printf("%s", str_num[j]);
    }

    for (int k = 0; k < length; ++k) {
        delete[]str_num[k];
    }
    delete[]str_num;
}

