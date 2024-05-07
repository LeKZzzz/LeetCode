//2024-05-04 16:46:46
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        int res = 0;
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int tmp = height[stk.top()];
                stk.pop();
                if (stk.empty())
                    break;
                int min = std::min(height[stk.top()], height[i]);
                res += (min - tmp) * (i - stk.top() - 1);
            }
            while (!stk.empty() && height[i] == height[stk.top()])
                stk.pop();
            stk.push(i);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
