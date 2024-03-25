//2024-03-23 10:51:38
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0)
                nums[i] = n + 1;
        }
        for (int i = 0; i < n; ++i) {
            if (abs(nums[i]) <= n) {
                int idx = abs(nums[i]) - 1;
                if (nums[idx] > 0)
                    nums[idx] = -nums[idx];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0)
                return i + 1;
        }
        return n + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
