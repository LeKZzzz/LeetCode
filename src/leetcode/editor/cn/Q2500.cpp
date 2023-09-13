//2023-07-27 21:47:23
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>> &grid) {
        int result = 0, max;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i)
            sort(grid[i].begin(), grid[i].end());
        for (int i = 0; i < n; ++i) {
            max = 0;
            for (int j = 0; j < m; ++j) {
                max = max >= grid[j][i] ? max : grid[j][i];
            }
            result += max;
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
