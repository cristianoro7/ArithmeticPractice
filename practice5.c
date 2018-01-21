#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>

/**
 * 重建二叉树: 输入某个二叉树的前序遍历和中序遍历的结果, 请重建二叉树.
 * 例如输入前序遍历{1, 2, 4, 7, 3, 5, 6, 8}和中序遍历{4, 7, 2, 1, 5, 3, 8, 6}
 * 实现思路: 前序遍历中的第一个是根节点, 根据跟根节点找到其在中序遍历中的位置, 其左边为左子树, 右边为右子树.
 */
typedef struct binary_tree_node {
    int value;
    struct binary_tree_node *left_node;
    struct binary_tree_node *right_node;
} node, *binary_tree_node;

binary_tree_node construct_core(int *start_pre_order, int *end_pre_order, int *start_in_order, int *end_in_order) {
    //前序遍历序列的第一个数字是根节点
    int root_value = start_in_order[0];
    binary_tree_node root = malloc(sizeof(node));
    if (root == NULL) {
        exit(0);
    }
    root->value = root_value;
    root->left_node = NULL;
    root->right_node = NULL;

    if (start_pre_order == end_pre_order) {
        if (start_in_order == end_in_order && *start_pre_order == *start_in_order) {
            return root;
        } else {
            exit(0);
        }
    }

    //在中序遍历中找到根节点的值
    int *root_in_order = start_in_order;
    while (root_in_order <= end_in_order && *root_in_order != root_value) {
        ++root_in_order;
    }
    if (root_in_order == end_in_order && *root_in_order != root_value) {
        exit(0);
    }

    int left_length = root_in_order - start_in_order;
    int *left_pre_order_end = start_pre_order + left_length;
    if (left_length > 0) {
        root->left_node = construct_core(start_pre_order + 1, left_pre_order_end, start_in_order, root_in_order - 1);
    }
    if (left_length < end_pre_order - start_pre_order) {
        root->right_node = construct_core(left_pre_order_end + 1, end_pre_order, root_in_order + 1, end_in_order);
    }
    return root;
}

binary_tree_node construct(int *pre_order, int *in_order, int length) {
    if (pre_order == NULL || in_order == NULL || length < 0) {
        return NULL;
    }
    return construct_core(pre_order, pre_order + length - 1, in_order, in_order + length - 1);
}

