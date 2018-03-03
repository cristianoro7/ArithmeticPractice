/**
 * 题目: 输入两个链表, 找出他们的第一个公共节点.
 *
 * 思路:
 * 1. 顺序扫描两个链表比较. 时间复杂为O(mn)
 * 2. 利用栈来辅助. 时间复杂度为O(n+m). 空间复杂度为O(n + m)
 * 3. 比较链表的长度, 然后让长的先走几步. 最后逐个比较. 第一个相同时就返回. 时间复杂度为:O(m + n)
 */

typedef struct list_node {
    int v;
    list_node *next;
} list_node;

int get_list_length(list_node *head) {
    if (head == nullptr) {
        return 0;
    }
    int l = 0;
    list_node *p = head;
    while (p != nullptr) {
        l++;
        p = p->next;
    }
    return l;
}

list_node *get_first_common_node(list_node *head1, list_node *head2) {
    if (head1 == nullptr || head2 == nullptr) {
        return nullptr;
    }

    int head_1_length = get_list_length(head1);
    int head_2_length = get_list_length(head2);
    list_node *longer_node = head1;
    list_node *shorter_node = head2;

    int length_diff = head_1_length - head_2_length;
    if (head_1_length < head_2_length) {
        length_diff = head_2_length - head_1_length;
        longer_node = head2;
        shorter_node = head1;
    }

    for (int i = 0; i < length_diff; ++i) {
        longer_node = longer_node->next;
    }

    while (longer_node != nullptr && shorter_node != nullptr) {
        if (longer_node == shorter_node) {
            return longer_node;
        }
        longer_node = longer_node->next;
        shorter_node = shorter_node->next;
    }
    return nullptr;

}