//2023-07-23 17:02:28
#include "header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int result=0,rmax,cmax,n=grid[0].size();
        vector<int>row;
        vector<int>column;

        for (int i = 0; i < n; ++i) {
            rmax=grid[i][0];
            cmax=grid[0][i];
            for (int j = 0; j < n; ++j) {
                rmax=rmax<grid[i][j]?grid[i][j]:rmax;
                cmax=cmax<grid[j][i]?grid[j][i]:cmax;
            }
            row.push_back(rmax);
            column.push_back(cmax);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result+=(row[i]<=column[j]?row[i]-grid[i][j]:column[j]-grid[i][j]);
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
//
//vector<vector<int>> grid;
//int main(){
//    for (int i = 0; i < 4; ++i) {
//        vector<int> tmp;
//        int val;
//        for (int j = 0; j < 4; ++j) {
//            cin>>val;
//            tmp.push_back(val);
//        }
//        grid.push_back(tmp);
//    }
//    Solution sol;
//    cout<<sol.maxIncreaseKeepingSkyline(grid);
//    return 0;
//}

//class Solution {
//public:
//    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
//        int result = 0, tmp, min, max, n = grid[0].size();
//        for (int i = 0; i < grid.size(); ++i) {
//            for (int j = 0; j < grid.size(); ++j) {
//
//                //向左
//                if (j == 0) max = 101;
//                else max = 0;
//                tmp = j - 1;
//                while (tmp >= 0) {
//                    max = max <= grid[i][tmp] ? grid[i][tmp] : max;
//                    tmp--;
//                }
//                min = max;
//
//                //向上
//                if (i == 0) max = 101;
//                else max = 0;
//                tmp = i - 1;
//                while (tmp >= 0) {
//                    max = max <= grid[tmp][j] ? grid[tmp][j] : max;
//                    tmp--;
//                }
//                min=min <= max ? min : max;
//
//
//                //向右
//                if (j == n - 1) max = 101;
//                else max = 0;
//                tmp = j + 1;
//                while (tmp < n) {
//                    max = max <= grid[i][tmp] ? grid[i][tmp] : max;
//                    tmp++;
//                }
//                min=min <= max ? min : max;
//
//
//                //向下
//                if (i == n - 1) max = 101;
//                else max = 0;
//                tmp = i + 1;
//                while (tmp < n) {
//                    max = max <= grid[tmp][j] ? grid[tmp][j] : max;
//                    tmp++;
//                }
//                min=min <= max ? min : max;
//
//                if (min != 101)
//                    result += (min-grid[i][j]);
//            }
//        }
//
//        return result;
//    }
//};