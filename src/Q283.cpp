//2024-03-06 08:48:29
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int count = 0;
    int left = 0, right;

    void moveZeroes(vector<int> &nums) {
        for (right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                nums[left] = nums[right];
                left++;
            } else
                count++;
        }
        for (int i = nums.size() - count; i < nums.size(); ++i)
            nums[i] = 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
