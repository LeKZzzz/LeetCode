//2024-05-06 16:25:47
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<vector<int>> res;
    vector<int> tmp;
    int cur = 0;

    void recur(TreeNode *root, int target) {
        if (root == nullptr)
            return;
        cur += root->val;
        tmp.push_back(root->val);
        if (cur == target && root->left == nullptr && root->right == nullptr) {
            res.push_back(tmp);
            cur -= root->val;
            tmp.pop_back();
            return;
        }
        recur(root->left, target);
        recur(root->right, target);
        cur -= root->val;
        tmp.pop_back();
    }

public:
    vector<vector<int>> pathTarget(TreeNode *root, int target) {
        recur(root, target);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
