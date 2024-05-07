//2024-05-01 09:38:16
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralArray(vector<vector<int>> &array) {
        vector<int> res;
        if (array.empty()) return res;
        int left = 0, right = array[0].size() - 1, top = 0, bottom = array.size() - 1;
        while (true) {
            for (int i = left; i <= right; i++) res.push_back(array[top][i]); // left to right
            if (++top > bottom) break;
            for (int i = top; i <= bottom; i++) res.push_back(array[i][right]); // top to bottom
            if (left > --right) break;
            for (int i = right; i >= left; i--) res.push_back(array[bottom][i]); // right to left
            if (top > --bottom) break;
            for (int i = bottom; i >= top; i--) res.push_back(array[i][left]); // bottom to top
            if (++left > right) break;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
