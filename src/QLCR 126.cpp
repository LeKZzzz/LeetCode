//2024-04-02 16:45:34
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n;
        bool flag = true;
        int a = 0, b = 1, sum;
        for (int i = 1; i < n; ++i) {
            sum = (a + b) % 1000000007;
            if (flag)
                a = sum;
            else
                b = sum;
            flag = !flag;
        }
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
