#include <stddef.h>

/**
 * 题目: 合并两个有序的链表
 */

typedef struct list_node {
    int v;
    struct list_node *next;
} list_node;

list_node *merge(list_node *head_first, list_node *head_second) {
    if (head_first == NULL) {
        return head_second;
    } else if (head_second == NULL) {
        return head_first;
    }

    list_node *merge_head = NULL;

    if (head_first->v < head_second->v) {
        merge_head = head_first;
        merge_head->next = merge(head_first->next, head_second);
    } else {
        merge_head = head_second;
        merge_head->next = merge(head_first, head_second->next);
    }

    return merge_head;
}

list_node *merge_list(list_node *head_first, list_node *head_second) {
    if (head_first == NULL) {
        return head_second;
    } else if (head_second == NULL) {
        return head_first;
    }

    list_node *new_head = head_first; //以第一个链表为节点
}
