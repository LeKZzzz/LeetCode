//2024-05-03 12:16:05
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> master, assist;

    MinStack() {
    }

    void push(int x) {
        master.push(x);
        if (assist.empty() || x <= assist.top())
            assist.push(x);
    }

    void pop() {
        int tmp = master.top();
        master.pop();
        if (tmp == assist.top())
            assist.pop();
    }

    int top() {
        return master.top();
    }

    int getMin() {
        return assist.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
//leetcode submit region end(Prohibit modification and deletion)
