//2024-03-25 09:14:10
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
/*
 * 方法一
 */
//class Solution {
//public:
//    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
//        int end = -1, count = 0, n = timeSeries.size();
//        for (int i = 0; i < n; ++i) {
//            int step = timeSeries[i] + duration - 1;
//                if (timeSeries[i] > end)
//                    count += duration;
//                else
//                    count += (step - end);
//                end = step;
//        }
//        return count;
//    }
//};
/*
 * 方法二
 */
class Solution {
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        auto res = 0;
        for (auto i = 1; i < timeSeries.size(); ++i) {
            res += min(timeSeries[i] - timeSeries[i - 1], duration);
        }
        return res + duration;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
