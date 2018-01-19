#include <malloc.h>
/**
 * Created by desperado on 18-1-17.
 * 实现一个函数, 把字符串中的每个空格替换成"%20". 例如输入 "We are happy.", 则输出 "We%20are%20happy."
 * <p>
 * 前提条件: 由于空格替换成%20, 也就是说替换后字符创的长度会改变, 所以, 先要问清楚是在原来的字符串上修改还是自己新分配空间修改
 * 如果是在原来的字符串上修改的话, 要确保有足够的空间来容纳新增加的字符.
 * <p>
 * 实现思路: 首先计算字符串的实际长度, 和替换后的字符长度.
 * 接着定义两个指针, 一个指向替换前字符串的末尾, 另一个指向替换后的字符串末尾, 这样从后面开始复制
 */

void replaceSpace(char string[], int length) {
    if (string != NULL) {
        int oldLength = 0;
        int newLength = 0;
        int spaceCounts = 0;
        int index = 0;

        //计算原来的字符串长度
        while (string[index] != '\0') {
            oldLength++;
            if (string[index] == ' ') {
                spaceCounts++;
            }
            index++;
        }

        //计算替换后的字符长度
        newLength = oldLength + spaceCounts * 2;
        if (newLength > length) {
            printf("exit");
            return;
        }

        //开始替换
        int replaceIndex = oldLength;
        while (replaceIndex > 0) {
            if (string[oldLength - 1] == ' ') {
                string[newLength - 1] = '0';
                string[newLength - 2] = '2';
                string[newLength - 3] = '%';
                newLength -= 3;
            } else {
                string[newLength - 1] = string[oldLength - 1];
                newLength--;
            }
            replaceIndex--;
            oldLength--;
        }
    }
}

//int main() {
//    char s[30] = {'W', 'e', ' ', 'a', 'r', 'e', ' ', 'h', 'a', 'p', 'p', 'y', '.', '\0'};
//
//    replaceSpace(s, 30);
//    printf("%s", s);
//    return 0;
//}