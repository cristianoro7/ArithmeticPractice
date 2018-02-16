#include <stddef.h>
#include <malloc.h>

/**
 * 题目: 给定单向链表的头指针和下一个节点的指针, 定义一个函数在O(1)时间删除节点.
 *
 * 思路: 如果要删除的节点不是在尾节点, 可以将删除节点的下一个节点复制给被删除的节点. 这样就相当于删除了一个节点
 */

typedef struct Node {
    int n_value;
    struct Node *p_next;
} Node;

void delete_node(Node **head, Node *delete) {
    if (!head || !delete) {
        return;
    }

    if (delete->p_next == NULL) { //要删除的节点不是尾节点
        Node *next = delete->p_next;
        delete->n_value = next->n_value;
        delete->p_next = next->p_next;

        free(delete);
        delete = NULL;
    } else if (*head == delete) { //链表只有一个节点
        free(delete);
        *head = NULL;
        delete = NULL;
    } else { //删除的是尾节点
        Node *p = *head;
        while (p->p_next != delete) {
            p = p->p_next;
        }
        p->p_next = NULL;
        free(delete);
        delete = NULL;
    }
}