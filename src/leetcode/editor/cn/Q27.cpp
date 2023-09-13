//2023-07-22 20:23:00
#include "../../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        if (nums.size() == 0) return 0;
        int p = 0, q = nums.size() - 1;
        while (p < q) {
            while (nums[p] != val && p < q) p++;
            while (nums[q] == val && p < q) q--;
            if (p < q) {
                nums[p] = nums[q];
                p++;
                q--;
            }
        }
        if (p == q)
            if (nums[p] == val)
                p--;
        if (p > q)
            p--;
        return p + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
