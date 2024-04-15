//2024-04-11 22:28:27
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        vector<int> dp(bamboo_len + 1);
        int max, tmp;
        for (int i = 2; i < bamboo_len + 1; ++i) {
            max = 0;
            for (int j = 1; j < i; ++j) {
                tmp = std::max(j * (i - j), j * dp[i - j]);
                max = max > tmp ? max : tmp;
            }
            dp[i] = max;
        }
        return dp[bamboo_len];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
