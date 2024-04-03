//2024-04-01 09:19:32
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    vector<int> my_preorder;
    unordered_map<int, int> mp;

    TreeNode *recur(int root, int left, int right) {
        if (left > right) return nullptr;
        TreeNode *node = new TreeNode(my_preorder[root]);
        int idx = mp[my_preorder[root]];
        node->left = recur(root + 1, left, idx - 1);
        node->right = recur(root + (idx - left + 1), idx + 1, right);
        return node;
    }

public:
    TreeNode *deduceTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode *root;
        my_preorder = preorder;
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }
        root = recur(0, 0, preorder.size() - 1);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
