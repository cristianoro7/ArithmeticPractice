#include <form.h>

/**
 * 题目: 反转链表
 */

typedef struct list_node {
    int v;
    struct list_node *next;
} list_node;

list_node *reverse_list(list_node *head) {
    list_node *r_h = NULL; //翻转链表后的头结点
    list_node *current = head;
    list_node *pre = NULL;

    while (current) {
        list_node *next = current->next;
        if (next == NULL) {
            r_h = next;
        }
        current->next = pre;
        pre = current;
        current = next;
    }
    return r_h;
}

