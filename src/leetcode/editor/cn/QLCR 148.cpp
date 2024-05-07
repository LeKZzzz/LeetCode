//2024-05-03 13:37:30
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool validateBookSequences(vector<int>& putIn, vector<int>& takeOut) {
        stack<int> stk;
        int i = 0;
        for(int num : putIn) {
            stk.push(num); // num 入栈
            while(!stk.empty() && stk.top() == takeOut[i]) { // 循环判断与出栈
                stk.pop();
                i++;
            }
        }
        return stk.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
