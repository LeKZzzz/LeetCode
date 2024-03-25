//2024-03-25 09:44:33
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
/*
 * 方法一：排序
 */
//class Solution {
//public:
//    int thirdMax(vector<int> &nums) {
//        int count = 0, n = nums.size(), res;
//        sort(nums.begin(), nums.end(), greater<>());
//        for (int i = 0, pre = nums[i] - 1; i < n; ++i) {
//            if (count == 3)
//                break;
//            if (nums[i] != pre) {
//                count++;
//                res = nums[i];
//                pre = nums[i];
//            }
//        }
//        return count == 3 ? res : nums[0];
//    }
//};
/*
 * 方法二：有序集合
 */
//class Solution {
//public:
//    int thirdMax(vector<int> &nums) {
//        set<int> s;
//        for (int num : nums) {
//            s.insert(num);
//            if (s.size() > 3) {
//                s.erase(s.begin());
//            }
//        }
//        return s.size() == 3 ? *s.begin() : *s.rbegin();
//    }
//};
/*
 * 方法三：一次遍历(依赖元素范围)
 */
class Solution {
public:
    int thirdMax(vector<int> &nums) {
        long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
        for (long num : nums) {
            if (num > a) {
                c = b;
                b = a;
                a = num;
            } else if (a > num && num > b) {
                c = b;
                b = num;
            } else if (b > num && num > c) {
                c = num;
            }
        }
        return c == LONG_MIN ? a : c;
    }
};
/*
 * 方法四：一次遍历(不依赖元素范围)
 */
class Solution {
public:
    int thirdMax(vector<int> &nums) {
        int *a = nullptr, *b = nullptr, *c = nullptr;
        for (int &num : nums) {
            if (a == nullptr || num > *a) {
                c = b;
                b = a;
                a = &num;
            } else if (*a > num && (b == nullptr || num > *b)) {
                c = b;
                b = &num;
            } else if (b != nullptr && *b > num && (c == nullptr || num > *c)) {
                c = &num;
            }
        }
        return c == nullptr ? *a : *c;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
