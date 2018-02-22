#include <vector>
#include <cstdio>

/**
 * 输入二叉树中和为某一值的路径
 *
 * 思路: 利用去前序遍历和辅助栈解决
 */

typedef struct binary_tree_node {
    int v;
    binary_tree_node *left;
    binary_tree_node *right;
} binary_tree_node;


void finPath(binary_tree_node *root, int number, int &current_number, std::vector &stack) {
    current_number += root->v;
    stack.push_back(root->v); //添加进栈

    bool is_leaf = root->left == nullptr && root->right == nullptr;

    if (current_number == number && is_leaf) {
        printf("Find!\n");
        std::vector::iterator iterator = stack.begin();
        for (; iterator != stack.end(); iterator++) {
            printf("%d\t", *iterator);
        }
    }

    if (root->left != nullptr) {
        finPath(root->left, number, current_number, stack); //递归遍历左子树
    }

    if (root->right != nullptr) {
        finPath(root->right, number, current_number, stack); //递归遍历右子树
    }

    //回到父节点, 需要减少当前的值, 并且删除出栈.
    current_number -= root->v;
    stack.pop_back();
}

void findPath(binary_tree_node *root, int number) {
    if (root == nullptr) {
        return;
    }
    int current_number;
    std::vector stack;
    finPath(root, number, current_number, stack);
}

