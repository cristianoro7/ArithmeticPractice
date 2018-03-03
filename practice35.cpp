/**
 * 题目: 求数组中的逆序对
 *
 * 思路:
 * 1. 顺序扫描, 然后逐个比较. 时间复杂度为O(n2)
 * 2. 基于归并排序来比较. 时间复杂度为O(nlogn)
 */

int inverse_pairs_core(int data[], int start, int mid, int end, int temp[]) {
    int i = start;
    int j = mid + 1;
    int k = 0;

    int c = 0;

    while (i <= mid && j <= end) {
        if (data[i] > data[j]) {
            temp[k++] = data[j++];
            c += mid - i + 1;
        } else {
            temp[k++] = data[i++];
        }
    }

    while (i <= mid) {
        temp[k++] = data[i++];
    }
    while (j <= end) {
        temp[k++] = data[j++];
    }

    for (int l = 0; l < k; ++l) {
        data[start + l] = temp[l];
    }
    return c;
}

int inverse_pairs(int data[], int start, int end, int temp[]) {
    if (data == nullptr || temp == nullptr) {
        return 0;
    }

    int c = 0;

    while (start < end) {
        int mid = (start + end) / 2;
        c += inverse_pairs(data, start, mid, temp);
        c += inverse_pairs(data, mid + 1, end, temp);
        c += inverse_pairs_core(data, start, mid, end, temp);
    }
    return c;
}

