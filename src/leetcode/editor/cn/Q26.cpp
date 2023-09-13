//2023-07-22 20:24:39
#include "../../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int p = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[p] != nums[i]) p++;
            if (i - p >= 1)
                nums[p] = nums[i];
        }
        return p + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
