#include <cstddef>

/**
 * 题目: 给定一棵二叉搜索树，在二叉搜索树的基础上，将之转换成有序的双向链表。即，不需要额外的辅助空间。
 */

typedef struct binary_tree_node {
    int v;
    binary_tree_node *left;
    binary_tree_node *right;
} binary_tree_node;


void convert_node(binary_tree_node *root, binary_tree_node **last_node) {
    if (root == NULL) {
        return;
    }

    binary_tree_node *current = root;

    if (root->left != NULL) {
        convert_node(root->left, last_node);
    }
    current->left = *last_node;

    if (*last_node != NULL) {
        (*last_node)->right = current;
    }
    *last_node = current;

    if (current->right != NULL) {
        convert_node(root->right, last_node);
    }
}

binary_tree_node *convert(binary_tree_node *root) {
    if (root == NULL) {
        return root;
    }

    binary_tree_node *last_node = NULL;
    convert_node(root, &last_node);

    binary_tree_node *head = last_node;
    while (head != NULL && head->left != NULL) {
        head = head->left;
    }
    return head;
}