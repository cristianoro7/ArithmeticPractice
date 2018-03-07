/**
 * 题目: 输入一个英文句子, 翻转句子中的单词顺序, 但单词内的字符顺序不变
 *
 * 题目二: 将字符串的前若干个字符左移到末尾
 */

void reverse(int *begin, int *end) {
    if (begin == nullptr || end == nullptr) {
        return;
    }

    while (begin < end) {
        char t = *begin;
        *begin = *end;
        *end = t;
        begin++;
        end--;
    }
}

char *reverse_sentence(char *data) {
    if (data == nullptr) {
        return nullptr;
    }

    char *begin = data;
    char *end = data;
    while (end != '\0') {
        end++;
    }
    end--;
    reverse(begin, end);

    while (begin != '\0') {
        if (begin == ' ') {
            begin++;
            end++;
        } else if (end == ' ' || end == '\0') {
            end--;
            reverse(begin, end);
            end++;
            begin = end;
        } else {
            end++;
        }
    }
    return data;
}

char *left_reverse(char *data, int n, int length) {
    if (data != nullptr && n < length && n > 0 && length > 0) {
        char *start_1 = data;
        char *end_1 = data + n - 1;
        char *start_2 = data + n;
        char *end_2 = data + length - 1;

        reverse(start_1, end_1);
        reverse(start_2, end_2);
        reverse(start_1, end_2);
    }
    return data;
}