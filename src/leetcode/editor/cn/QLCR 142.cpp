//2024-04-20 13:11:44
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
    ListNode* trainningPlan(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* cur = res;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = (l1 != nullptr) ? l1 : l2;
        return res->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
