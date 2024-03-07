//2024-03-06 09:17:44
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    vector<int> tmp;
//    int n;

    void rotate(vector<int> &nums, int k) {
// 方法一
/*        n = nums.size();
        tmp.resize(n);
        for (int i = 0; i < nums.size(); ++i)
            tmp[(i + k) % n] = nums[i];
        nums.assign(tmp.begin(), tmp.end());*/
// 方法二
      k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
//方法三
/*        int n = nums.size();
        k = k % n;
        int count = gcd(k, n);
        for (int start = 0; start < count; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
            } while (start != current);
        }*/
    }
};
//leetcode submit region end(Prohibit modification and deletion)
