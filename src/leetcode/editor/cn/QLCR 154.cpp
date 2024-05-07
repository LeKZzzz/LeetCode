//2024-05-06 16:41:26
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* cur = head;
        unordered_map<Node*, Node*> mp;
        // 3. 复制各节点，并建立 “原节点 -> 新节点” 的 mp 映射
        while(cur != nullptr) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        // 4. 构建新链表的 next 和 random 指向
        while(cur != nullptr) {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }
        // 5. 返回新链表的头节点
        return mp[head];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
