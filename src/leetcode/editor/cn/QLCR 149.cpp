//2024-05-03 15:27:04
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> decorateRecord(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (!root)
            return res;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            res.push_back(cur->val);
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
            q.pop();
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
