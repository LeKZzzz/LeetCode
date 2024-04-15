//2024-04-15 21:07:02
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
// 快速幂
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long a = n;
        if (n < 0) {
            a = -a;
            x = 1 / x;
        }
        for (long i = a; i > 0;) {
            if (i & 1) res = res * x;  // 如果指数是基数，则将多出来的一个x乘入res中
            x = x * x;  // 将底数平方
            i >>= 1; // 指数除以2取整
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
