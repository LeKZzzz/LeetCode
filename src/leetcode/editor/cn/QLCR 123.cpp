//2024-03-30 14:07:27
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> reverseBookList(ListNode *head) {
        ListNode *p = head;
        stack<int> stk;
        vector<int> res;
        while (p != nullptr) {
            stk.push(p->val);
            p = p->next;
        }
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
