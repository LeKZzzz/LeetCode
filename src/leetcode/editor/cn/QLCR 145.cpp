//2024-04-29 10:01:36
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
private:
    bool recur(TreeNode *leftNode, TreeNode *rightNode) {
        if (leftNode == nullptr && rightNode == nullptr)
            return true;
        if (leftNode == nullptr || rightNode == nullptr ||
            leftNode->val != rightNode->val)
            return false;
        return recur(leftNode->left, rightNode->right) &&
               recur(leftNode->right, rightNode->left);
    }

public:
    bool checkSymmetricTree(TreeNode *root) {
        if (root == nullptr)
            return true;
        else
            return recur(root->left, root->right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
