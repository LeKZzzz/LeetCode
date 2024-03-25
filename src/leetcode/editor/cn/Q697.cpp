//2024-03-22 11:38:07
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
/*
 * 使用哈希表
 */
class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        unordered_map<int, vector<int>> mp;
        int maxNum = 0, minLen = 1;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (mp.count(nums[i])) {
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            } else {
                mp[nums[i]] = {1, i, i};
            }
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second[0] > maxNum) {
                maxNum = it->second[0];
                minLen = it->second[2] - it->second[1] + 1;
            } else if (it->second[0] == maxNum) {
                if (minLen > (it->second[2] - it->second[1] + 1))
                    minLen = it->second[2] - it->second[1] + 1;
            }
        }
        return minLen;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
