//2024-03-23 10:25:00
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
/*
 * 方法一：哈希表
 */
//class Solution {
//public:
//    vector<int> findDuplicates(vector<int> &nums) {
//        vector<int> result;
//        unordered_map<int, int> mp;
//        for (int i = 0; i < nums.size(); ++i) {
//            if (!mp.count(nums[i]))
//                mp[nums[i]] = 1;
//            else
//                mp[nums[i]]++;
//        }
//        for (auto it = mp.begin(); it != mp.end(); it++) {
//            if (it->second == 2)
//                result.push_back(it->first);
//        }
//        return result;
//    }
//};
/*
 * 方法二：与448相同，加n
 */
//class Solution {
//public:
//    vector<int> findDuplicates(vector<int> &nums) {
//        vector<int> result;
//        int n = nums.size();
//        for (int i = 0; i < n; ++i) {
//            int idx = (nums[i] - 1) % n;
//            nums[idx] += n;
//        }
//        for (int i = 0; i < n; ++i) {
//            if (nums[i] > (2 * n))
//                result.push_back(i + 1);
//        }
//        return result;
//    }
//};
/*
 * 方法三：使用正负号
 */
//class Solution {
//public:
//    vector<int> findDuplicates(vector<int> &nums) {
//        vector<int> result;
//        int n = nums.size();
//        for (int i = 0; i < n; ++i) {
//            int idx = abs(nums[i]) - 1;
//            if (nums[idx] < 0)
//                result.push_back(idx + 1);
//            else
//                nums[idx] = -nums[idx];
//        }
//
//        return result;
//    }
//};
/*
 * 方法四：交换元素
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] - 1 != i) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
