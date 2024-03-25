//2024-03-13 12:24:18
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
/*
 * 方法一
 * 先排序
 * 如果相邻两个数相差2则说明丢失的数在这两个数中间
 * 如果相邻两个数相等则说明这是重复的数
 * 特别的，如果最后一个数不是n则丢失的数是n
 */
//class Solution {
//public:
//    vector<int> findErrorNums(vector<int> &nums) {
//        vector<int> errorNums(2);
//        sort(nums.begin(), nums.end());
//        int pre = 0;
//        int n = nums.size();
//        for (int i = 0; i < n; ++i) {
//            if (nums[i] == pre) {
//                errorNums[0] = pre;
//            } else if (nums[i] - pre > 1)
//                errorNums[1] = pre + 1;
//            pre = nums[i];
//        }
//        if (nums[n - 1] != n)
//            errorNums[1] = n;
//        return errorNums;
//    }
//};

/*
 * 使用哈希表
 */
class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        vector<int> errorNums(2);
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i)
            mp[nums[i]]++;
        for (int i = 1; i <= n; ++i) {
            if (mp[i] == 0)
                errorNums[1] = i;
            else if (mp[i] == 2)
                errorNums[0] = i;
        }
        return errorNums;
    }
};

/*
 *位运算
 */
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }
        for (int i = 1; i <= n; i++) {
            xorSum ^= i;
        }
        int lowbit = xorSum & (-xorSum);
        int num1 = 0, num2 = 0;
        for (int &num : nums) {
            if ((num & lowbit) == 0) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        for (int i = 1; i <= n; i++) {
            if ((i & lowbit) == 0) {
                num1 ^= i;
            } else {
                num2 ^= i;
            }
        }
        for (int num : nums) {
            if (num == num1) {
                return vector<int>{num1, num2};
            }
        }
        return vector<int>{num2, num1};
    }
};

//leetcode submit region end(Prohibit modification and deletion)
