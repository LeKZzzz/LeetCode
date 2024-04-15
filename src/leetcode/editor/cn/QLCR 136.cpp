//2024-04-15 22:23:24
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode newHead = ListNode(0);
        newHead.next = head;
        ListNode* p = &newHead;
        while (p->next != NULL) {
            if (p->next->val == val) {
                p->next = p->next->next;
                break;
            }
            p = p->next;
        }
        return newHead.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
