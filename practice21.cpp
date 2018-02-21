#include <stack>

/**
 * 题目: 输入两个整数序列, 第一个序列表示压栈顺序, 判断第二个序列是否为该栈的弹出顺序.
 *
 * 思路: 利用辅助栈来解决. 如果当前弹出的元素不是栈顶元素的话, 将栈顶的元素加入到辅助栈. 直到弹出的元素是栈顶元素. 然后栈顶元素出栈,
 * 如果全部元素都压入辅助栈后, 当前弹出元素还不是栈顶元素的话, 说明不是弹出顺序.
 */


bool isPopOrder(const int *push, const int *pop, int length) {
    bool isPossible = false;

    if (push != nullptr && pop != nullptr && length > 0) {
        const int *nextPop = pop;
        const int *nextPush = push;
        std::stack<int> stack;

        while (nextPop - pop < length) {

            while (stack.empty() || stack.top() != *nextPop) {
                if (nextPush - push == length) {
                    break;
                }
                stack.push(*nextPush); //入栈
                nextPush++;
            }

            if (stack.top() != *nextPop) {
                break;
            }
            stack.pop();
            nextPop++;
        }

        if (stack.empty() && nextPop - pop == length) {
            isPossible = true;
        }
    }
    return isPossible;
}
