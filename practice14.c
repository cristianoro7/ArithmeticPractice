#include <stddef.h>

/**
 *题目: 输入一个链表, 输出该链表中的倒数第K个节点. 本题从1开始计数
 *
 * 思路: 利用两个指针来解决, 特别要主要对参数的合理性判断
 */

typedef struct list_node {
    int v;
    struct list_node *next;
} list_node;

list_node *find_kth_from_tail(list_node *head, unsigned int k) {
    if (head == NULL || k == 0) {
        return NULL;
    }
    list_node *first = head;
    list_node *second = NULL;

    for (int i = 0; i < k - 1; ++i) {
        if (first->next != NULL) {
            first = first->next;
        } else { //如果链表的个数小于k
            return NULL;
        }
    }

    second = head;

    while (first->next != NULL) {
        first = first->next;
        second = second->next;
    }
    return second;
}
