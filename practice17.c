#include <stddef.h>

/**
 * 题目: 输入两棵二叉树A和B, 判断B是不是A的子结构
 * 思路: 在A中查找跟B的根节点一样的值R. 再判断以R为根节点的子树是否包含和B一样的结构
 */

typedef struct binary_tree_node {
    int value;
    struct binary_tree_node *left;
    struct binary_tree_node *right;
} binary_tree_node;

int does_tree1_has_tree2(binary_tree_node *root1, binary_tree_node *root2) {
    if (root2 == NULL) {
        return 1;
    }
    if (root1 == NULL) {
        return 0;
    }

    if (root1->value != root2->value) {
        return 0;
    }
    return does_tree1_has_tree2(root1->left, root2->left) && does_tree1_has_tree2(root1->right, root2->right);
}

int has_subtree(binary_tree_node *root1, binary_tree_node *root2) {
    int is_has = 0;

    if (root1 != NULL && root2 != NULL) {
        if (root1->value == root2->value) {
            is_has = does_tree1_has_tree2(root1, root2);
        }
        if (!is_has) {
            is_has = has_subtree(root1->left, root2);
        }
        if (!is_has) {
            is_has = has_subtree(root1->right, root2);
        }
    }
    return is_has;
}