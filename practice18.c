#include <stddef.h>
#include <cursesw.h>

/**
 * 题目: 完成一个函数, 输入一棵二叉树, 该函数输出它的镜像
 */

typedef struct binary_tree_node {
    int value;
    struct binary_tree_node *left;
    struct binary_tree_node *right;
} binary_tree_node;

void mirror_recursively(binary_tree_node *node) {
    if (node == NULL || (node->left == NULL && node->right == NULL)) {
        return;
    }

    binary_tree_node *temp = node->left;
    node->left = node->right;
    node->right = temp;

    if (node->left) {
        mirror_recursively(node->left);
    }

    if (node->right) {
        mirror_recursively(node->right);
    }
}