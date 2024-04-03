//2024-04-02 17:07:52
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trainWays(int num) {
        if (num < 2)
            return 1;
        bool flag = true;
        int a = 1, b = 1, sum;
        for (int i = 1; i < num; ++i) {
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
