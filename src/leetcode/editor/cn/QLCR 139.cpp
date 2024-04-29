//2024-04-19 11:36:08
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> trainingPlan(vector<int> &actions) {
        int left = 0, right = actions.size() - 1;
        while (left < right) {
            while (left <= right && actions[left] % 2 == 1)
                left++;
            while (left <= right && actions[right] % 2 == 0)
                right--;
            if (left <= right)
                swap(actions[left], actions[right]);
            left++;
            right--;
        }
        return actions;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
