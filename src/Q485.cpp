//2024-03-25 09:05:57
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
/*
 * 遇1则加，遇0重置，比较大小，注意结尾
 */
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int count = 0, n = nums.size(), max = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                count++;
            } else if (nums[i] != 1) {
                max = max > count ? max : count;
                count = 0;
            }
        }
        max = max > count ? max : count;
        return max;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
