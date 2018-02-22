/**
 * 输入一个整数数组, 判断该数组是不是某二叉搜索树的后序遍历的结果
 *
 * 思路: 根据后序遍历的特点, 数组的最后一个是根节点, 数组分为两个部分, 第一部分是左子树. 都小于根节点, 第二部分是右子树, 都大于根节点
 */


bool verifyBinarySearchTree(int *sequence, int length) {
    if (sequence == nullptr || length <= 0) {
        return false;
    }

    int root = sequence[length - 1];

    int i = 0;
    for (; i < length - 1; ++i) {
        if (root < sequence[i]) {
            break;
        }
    }

    int j = i;
    for (; j < length - 1; j++) {
        if (sequence[j] < root) {
            return false;
        }
    }

    bool left = true;
    if (i > 0) {
        left = verifyBinarySearchTree(sequence, i);
    }

    bool right = true;
    if (i < length - 1) {
        right = verifyBinarySearchTree(sequence + i, length - 1 - i);
    }
    return left && right;
}
