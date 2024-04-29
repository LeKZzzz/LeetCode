//2024-04-20 12:31:07
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
    ListNode* trainingPlan(ListNode* head, int cnt) {
        ListNode *left = head, *right = head;
        for (int i = 0; i < cnt; i++)
            right = right->next;
        while (right != nullptr) {
            left = left->next;
            right = right->next;
        }
        return left;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
