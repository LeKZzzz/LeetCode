//2024-03-04 08:28:21
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int min;
    int minIndex;
    int n;

    int minMoves(vector<int> &nums) {
        int result = 0;
        n = nums.size();
        min = nums[0];
        minIndex = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < min) {
                min = nums[i];
                minIndex = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i != minIndex && nums[i] != min)
                result += (nums[i] - min);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
