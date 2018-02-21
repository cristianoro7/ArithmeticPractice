#include <deque>
#include <cstdio>

/**
 * 题目:按层次遍历打印二叉树.
 *
 * 思路: 利用先进先出的队列作为辅助.
 */


typedef struct binary_tree_node {
    int value;
    binary_tree_node *left;
    binary_tree_node *right;
} binary_tree_node;

void printFromTopToBottom(binary_tree_node *root) {
    if (root == nullptr) {
        return;
    }

    std::deque<binary_tree_node *> deque;

    deque.push_back(root);

    while (deque.size()) {
        binary_tree_node *node = deque.front();
        deque.pop_front();

        printf("%d\t", node->value);

        if (node->left) {
            deque.push_back(node->left);
        }

        if (node->right) {
            deque.push_back(node->right);
        }
    }
}