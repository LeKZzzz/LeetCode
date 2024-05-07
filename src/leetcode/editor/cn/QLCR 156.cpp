//2024-05-07 19:07:08
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
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> que;
        string res = "";
        if(root==nullptr) return res;
        que.push(root);
        while (!que.empty()) {
            TreeNode* tmp = que.front();
            que.pop();
            if (tmp == nullptr) {
                res += "null,";
                continue;
            }
            que.push(tmp->left);
            que.push(tmp->right);
            res += to_string(tmp->val) + ",";
        }
        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<string> arr;
        string tmp_str;
        while (getline(ss, tmp_str, ','))
            arr.push_back(tmp_str);
        if (arr.size() == 0)
            return nullptr;
        queue<TreeNode*> que;
        TreeNode *node, *tmp;
        int idx = 1;
        TreeNode* root = new TreeNode(stoi(arr[0]));
        que.push(root);
        while (!que.empty()) {
            node = que.front();
            if (arr[idx] != "null") {
                tmp = new TreeNode(stoi(arr[idx++]));
                node->left = tmp;
                que.push(tmp);
            } else {
                node->left = nullptr;
                idx++;
            }
            if (arr[idx] != "null") {
                tmp = new TreeNode(stoi(arr[idx++]));
                node->right = tmp;
                que.push(tmp);
            } else {
                node->right = nullptr;
                idx++;
            }
            que.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)
