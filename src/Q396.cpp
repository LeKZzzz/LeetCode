//2024-03-06 12:05:46
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int maxRotateFunction(vector<int> &nums) {
        int n = nums.size();
        int sum = 0, res, tmp = 0;
        for (int i = 0; i < n; ++i)
            sum += nums[i];
        for (int i = 0; i < n; ++i) {
            tmp += i * nums[i];
            res = tmp;
        }
        for (int i = 1; i < n; ++i) {
            tmp = tmp + sum - n * nums[n - i];
            res = max(res, tmp);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
