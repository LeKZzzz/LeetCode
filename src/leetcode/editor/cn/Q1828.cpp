//2023-07-23 16:33:41
#include "../../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries) {
        vector<int> ans;
        float distance;
        for (int i = 0; i < queries.size(); ++i) {
            ans.push_back(0);
            for (int j = 0; j < points.size(); ++j) {
//                if (points[j][0]>queries[i][0]+queries[i][2]||points[j][0]<queries[i][0]-queries[i][2]) continue;
//                if (points[j][1]>queries[i][1]+queries[i][2]||points[j][1]<queries[i][1]-queries[i][2]) continue;

                distance = ::sqrt(::pow(points[j][0] - queries[i][0], 2) + ::pow(points[j][1] - queries[i][1], 2));
                if (distance <= queries[i][2])
                    ans[i]++;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
