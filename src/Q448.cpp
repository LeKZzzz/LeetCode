//2024-03-22 12:46:51
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
/*
 * 方法一：使用额外标志数组
 */
//class Solution {
//public:
//    vector<int> findDisappearedNumbers(vector<int> &nums) {
//        vector<int> result;
//        int n = nums.size();
//        vector<int> flag(n + 1);
//        for (int i = 0; i < n; ++i) {
//            flag[nums[i]] = 1;
//        }
//        for (int i = 1; i <= n; ++i) {
//            if (!flag[i])
//                result.push_back(i);
//        }
//        return result;
//    }
//};
/*
 * 方法二：哈希表
 */
//class Solution {
//public:
//    vector<int> findDisappearedNumbers(vector<int> &nums) {
//        vector<int> result;
//        int n = nums.size();
//        unordered_map<int, int> mp;
//        for (int i = 0; i < n; ++i) {
//            mp[nums[i]] = 1;
//        }
//        for (int i = 1; i <= n; ++i) {
//            if (!mp.count(i))
//                result.push_back(i);
//        }
//        return result;
//    }
//};

/*
 * 方法三：原地修改
 * 利用所有数都在[1, n]中的特性
 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int x = (nums[i] - 1) % n;
            nums[x] += n;
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= n)
                result.push_back(i + 1);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
