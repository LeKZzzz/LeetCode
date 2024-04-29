//2024-04-29 09:49:27
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
public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (!A || !B)
            return false;
        if (A->val != B->val) {
            return isSubStructure(A->left, B) || isSubStructure(A->right, B);
        } else {
            if (preorder(A, B))
                return true;
            else
                return isSubStructure(A->left, B) ||
                       isSubStructure(A->right, B);
        }
    }

private:
    bool preorder(TreeNode *A, TreeNode *B) {
        if (B == NULL)
            return true;
        if (A == NULL || A->val != B->val)
            return false;
        return preorder(A->left, B->left) && preorder(A->right, B->right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
