//2024-03-28 09:55:25
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool findTargetIn2DPlants(vector<vector<int>> &plants, int target) {
        if (plants.size() == 0)
            return false;
        int i = plants[0].size() - 1, j = 0;    // j行 i列
        while (i >= 0 && j < plants.size()) {
            if (plants[j][i] == target)
                return true;
            if (plants[j][i] < target)
                j++;
            else
                i--;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
