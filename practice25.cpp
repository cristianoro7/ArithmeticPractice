#include <cstddef>

/**
 * 题目: 复杂链表的复制
 *
 * 思路:
 * 第一种: 先复制链表, 然后从头遍历复制随机节点. 这种方法的时间复杂度是O(n2)
 * 第二种: 先复制链表, 原来的节点N和复制的节点N`, 放在hash表中, 这样就不需要遍历链表就可以复制随机节点. 这种方法的时间复杂度为O(n), 但是空间复杂度为O(n), 典型的空间交换时间
 * 第三种: 复制的节点. 直接放在节点后面, 这样就可以根据节点原节点的随机节点的下一个节点, 这个节点就是复制后的随机节点. 最后再拆分两个链表
 */

typedef struct complex_list_node {
    int v;
    complex_list_node *next;
    complex_list_node *sibling;
} complex_list_node, *complex_list;

void clone_node(complex_list head) {
    complex_list_node *node = head;

    while (node != NULL) {
        complex_list_node *clone_node = new complex_list_node();
        clone_node->v = node->v;
        clone_node->next = node->next;
        clone_node->sibling = NULL;
        node->next = clone_node;

        node = clone_node->next;
    }
}

void connect_sibling_node(complex_list head) {
    complex_list_node *node = head;
    complex_list_node *clone_node;

    while (node != NULL) {
        clone_node = node->next;

        if (node->sibling != NULL) {
            clone_node->sibling = node->sibling->next;
        }
        node = clone_node->next;
    }
}

complex_list disconnect_list(complex_list head) {
    complex_list_node *node = head;
    complex_list_node *clone_head = NULL;
    complex_list_node *clone_node = NULL;

    if (node != NULL) {
        clone_head = clone_node = node->next;
        node->next = clone_node->next;
        node = node->next;
    }

    while (node != NULL) {
        clone_node->next = node->next;
        clone_node = node->next;

        node->next = clone_node->next;
        node = node->next;
    }
    return clone_head;
}

complex_list clone(complex_list head) {
    if (head == nullptr) {
        return nullptr;
    }
    clone_node(head);
    connect_sibling_node(head);
    return disconnect_list(head);
}