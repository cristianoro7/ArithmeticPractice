/**
 * 题目: 求二叉树的深度
 *
 * 思路: 如果根节点有左子树而没有右子树的话, 深度为左子树的深度+1. 如果根节点有右子树而没有左子树的话, 深度为右子树的深度+1.
 * 如果既有左子树又有右子树的话, 深度为左子树和右子树的较大值 + 1
 *
 * 题目二: 判断一棵二叉树是否为一棵二叉平衡树
 */

typedef struct binary_tree_node {
    int v;
    binary_tree_node *left;
    binary_tree_node *right;
} binary_tree_node;

int get_tree_depth(binary_tree_node *root) {
    if (root == nullptr) {
        return nullptr;
    }

    int left = get_tree_depth(root->left);
    int right = get_tree_depth(root->right);

    return left > right ? left + 1 : right + 1;
}

bool is_balanced(binary_tree_node *root, int &depth) {
    if (root == nullptr) {
        depth = 0;
        return true;
    }

    int left_depth;
    int right_depth;
    if (is_balanced(root->left, left_depth) && is_balanced(root->right, right_depth)) {
        int diff = left_depth - right_depth;
        if (diff <= 1 && diff >= -1) {
            depth = 1 + (left_depth > right_depth ? left_depth : right_depth);
            return true;
        }
    }
    return false;
}