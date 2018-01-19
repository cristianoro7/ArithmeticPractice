#include <cstdio>
#include <cstdlib>

/**
 * 从尾到头打印链表
 *
 * 实现思路, 利用递归或者栈
 */

typedef struct node {
    int value;
    node *next;
} *node_list;

void print_node(node_list head) {

    if (head != nullptr) {
        if (head->next != nullptr) {
            print_node(head->next);
        }
        printf("%d\n", head->value);
    }
}
