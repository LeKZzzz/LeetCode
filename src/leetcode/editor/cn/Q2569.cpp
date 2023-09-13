//2023-07-26 22:57:18
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
template<typename type>
class Segment_Tree {
public:
    Segment_Tree(type n, type *array, int begin) {
        tree = new int(4 * n + 1);
        this->array = array;
        build_tree(begin, begin, n);
    }

    void add(int k, int l, int r, int key, type value); //对第key个数进行操作
    type calculate(int k, int l, int r, int range_left, int range_right);   //求range_left到range_right范围内的数的和

private:
    type *tree, *array;

    void build_tree(int k, int l, int r);
};

template<typename type>
type Segment_Tree<type>::calculate(int k, int l, int r, int range_left, int range_right) {
    if (l == range_left && r == range_right)
        return tree[k];
    int mid = (range_left + range_right) / 2;
    if (range_right <= mid)
        calculate(2 * k, l, mid, range_left, range_right);
    else if (range_left >= mid + 1)
        calculate(2 * k + 1, mid + 1, r, range_left, range_right);
    else
        return calculate(2 * k, l, mid, range_left, mid) + calculate(2 * k + 1, mid + 1, r, mid + 1, range_right);
}

template<typename type>
void Segment_Tree<type>::add(int k, int l, int r, int key, type value) {
    tree[k] += value;
    if (l == r) return;
    int mid = (l + r) / 2;
    if (key <= mid)
        add(2 * k, l, mid, key, value);
    else
        add(2 * k + 1, mid + 1, r, key, value);
}

template<typename type>
void Segment_Tree<type>::build_tree(int k, int l, int r) {
    if (l == r) {
        tree[k] = array[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(2 * k, l, mid);
    build_tree(2 * k + 1, mid + 1, r);
    tree[k] = tree[2 * k] + tree[2 * k + 1];
}

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)
