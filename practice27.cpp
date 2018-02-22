#include <cstddef>
#include <cstdio>

/**
 * 题目: 求一个字符串的全排列
 */

void permutation(char *string, char *begin) {

    if (*begin == '\0') {
        printf("%s\t", string);
    } else {
        for (char *ch = begin; *ch != '\0'; ch++) {
            char temp = *ch;
            *ch = *begin;
            *begin = temp;

            permutation(string, begin + 1);

            temp = *ch;
            *ch = *begin;
            *begin = temp;
        }
    }
}

void permutation(char *string) {
    if (string == NULL) {
        return;
    }
    permutation(string, string);
}
