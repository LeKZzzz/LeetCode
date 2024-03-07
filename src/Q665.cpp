//2024-03-04 08:59:54
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    bool checkIncremental(vector<int> nums, int beginIndex, int endIndex) {
        int begin = beginIndex < 0 ? 0 : beginIndex;
        int end = endIndex >= nums.size() ? nums.size() : endIndex;
        for (int i = begin + 1; i < end; ++i) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }

    bool checkPossibility(vector<int> &nums) {
        if (nums.size() <= 2)
            return true;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] >= nums[i - 1])
                continue;

            if (!checkIncremental(nums, i,nums.size()))
                return false;
            if ((i + 1) < nums.size()) {
                if ((nums[i + 1] - nums[i - 1]) >= 0)
                    return true;
                if ((i - 2) < 0)
                    return true;
                else if ((nums[i] - nums[i - 2]) >= 0)
                    return true;
                else
                    return false;
            } else
                return true;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
