//2023-07-23 16:30:20
#include "../../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            result.push_back(nums[nums[i]]);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
