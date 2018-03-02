/**
 * 题目: 在字符串中找到第一个出现的字符
 *
 * 思路:
 * 1: 顺序扫描整个字符串. 低效, 时间复杂度为O(n2)
 * 2: .利用hash表来映射. 时间复杂度为O(n). 但是需要额外的空间
 */

char find_first_appear_char(char *string) {
    if (string == nullptr) {
        return '\0';
    }

    char *hash_table = new char[256];
    for (int i = 0; i < 256; ++i) {
        hash_table[i] = 0;
    }

    char *p = string;
    while (*p != '\0') {
        hash_table[*p]++;
        p++;
    }

    p = string;
    while (*p != '\0') {
        if (hash_table[*p] == 1) {
            return *p;
        }
        p++;
    }
    return '\0';
}
