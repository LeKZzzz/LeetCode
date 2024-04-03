//2024-04-02 16:15:11
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class CQueue {
private:
    stack<int> master, tmp;
public:
    CQueue() {

    }

    void appendTail(int value) {
        master.push(value);
    }

    int deleteHead() {
        int res;
        if (!tmp.empty()) { // tmp栈为master栈的逆序，实现队列
            res = tmp.top();
            tmp.pop();
            return res;
        }
        if (master.empty()) return -1;  // 如果tmp和master均为空则说明没有可删除的元素
        while (!master.empty()) {   // master不为空则将master中元素放入tmp实现逆序
            tmp.push(master.top());
            master.pop();
        }
        res = tmp.top();
        tmp.pop();
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
//leetcode submit region end(Prohibit modification and deletion)
