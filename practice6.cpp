#include <stack>
#include <exception>

/**
 * 利用两个栈实现一个队列
 * 实现思路: 入队时, 直接放进栈1, 出队时, 如果栈2为空的话, 先将栈1的元素全部弹出并压入栈2, 然后弹出栈2的栈顶元素; 如果不为空的话, 直接弹出栈2的栈顶元素
 */

template<typename T>
class CQueue {
public:
    CQueue(void);

    ~CQueue();

    void appendTail(const T &e);

    T deleteHead();

private:
    std::stack<T> stack1;
    std::stack<T> stack2;

};

CQueue::CQueue(void) {

}

CQueue::~CQueue() {

}

template<typename T>
void CQueue<T>::appendTail(const T &e) {
    stack1.push(e);
}

template<typename T>
T CQueue::deleteHead() {
    if (stack2.size() == 0) {
        while (stack1.size() > 0) {
            T &h = stack1.top();
            stack1.pop();
            stack2.push(h);
        }
    }
    if (stack2.size() == 0) {
        return nullptr;
    }
    T h = stack2.top();
    stack2.pop();
    return h;
}
