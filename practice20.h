/**
 * 题目: 定义栈的数据结构, 请在该类型中实现一个能够得到栈的最小元素的min函数, 在该栈中, 调用 push pop, 和min时间复杂度都是O(1)
 * 思路: 利用辅助空间来实现
 */


#ifndef ARITHMETICPRACTICE_PRACTICE20_H
#define ARITHMETICPRACTICE_PRACTICE20_H


#include <stack>

class practice20 {
    template<typename T>
    void push(const T &value);

    template<typename T>
    void pop();

    template<typename T>
    const T &min();

private:
    std::stack data;
    std::stack min_stack;
};

template<typename T>
void practice20::push(const T &value) {
    data.push(value);

    if (min_stack.size() == 0 || value < min_stack.pop()) {
        min_stack.push(value);
    } else {
        min_stack.push(min_stack.pop());
    }
}

template<typename T>
void practice20::pop() {
    data.pop();
    min_stack.pop();
}

template<typename T>
const T &practice20::min() {
    return min_stack.pop();
}


#endif //ARITHMETICPRACTICE_PRACTICE20_H
