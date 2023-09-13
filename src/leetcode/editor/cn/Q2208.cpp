//2023-07-25 21:11:11

#include <numeric>
#include "queue"
#include "../../../../header.h"


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int halveArray(vector<int> &nums) {
        double result = 0, tmp;
        int ans = 0;
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        priority_queue<double> q(nums.begin(), nums.end());
        while (result < sum / 2) {
            tmp = q.top();
            result += tmp / 2;
            q.pop();
            q.push(tmp / 2);
            ans++;
        }
        return ans;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
