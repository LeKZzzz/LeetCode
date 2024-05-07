//2024-05-03 15:49:23
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
public:
    vector<vector<int>> decorateRecord(TreeNode* root) {
        bool flag = false;
        vector<vector<int>> res;
        queue<TreeNode*> q;
        TreeNode* cur;
        int n;
        if (!root)
            return res;
        q.push(root);
        while (!q.empty()) {
            n = q.size();
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                cur = q.front();
                tmp.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
                q.pop();
            }
            if (flag)
                std::reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
            flag = !flag;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
