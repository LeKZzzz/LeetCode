//2024-04-19 10:21:16
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    int integerBreak(int n) {
//        if (n <= 3) return n - 1;
//        int res = 1, b = n % 3;
//        for (int i = 0; i < n / 3 - 1; ++i)
//            res *= 3;
//        if (b == 0) res *= 3;
//        else if (b == 1) res *= 4;
//        else res *= 6;
//        return res;
//    }
//};

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        vector<int> dp(n + 1);
        int right, max;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        for (int i = 4; i <= n; ++i) {
            max = 0;
            for (int j = 1; j < i; ++j) {
                right = i - j;
                int tmp = std::max(j * right, j * dp[right]);
                max = max > tmp ? max : tmp;
            }
            dp[i] = max;
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
