//2024-04-29 09:49:32
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void swap(TreeNode *root) {
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }

public:
    TreeNode *mirrorTree(TreeNode *root) {
        if (root == NULL)
            return NULL;
        swap(root);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
