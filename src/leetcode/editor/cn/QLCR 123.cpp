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
        ListNode *pre = nullptr, *cur = head, *tmp;
        vector<int> res;
        while (cur != nullptr) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        ListNode *p = pre;
        while (p != nullptr) {
            res.push_back(p->val);
            p = p->next;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
