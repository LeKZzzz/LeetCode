//2024-04-18 09:34:37
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isMatch(string s, string p) {
        if (s == "")
            return false;
        if (s == p)
            return true;
        else if (p == ".")
            return true;
        else
            return false;
    }

    bool articleMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                string curs = (i == 0) ? "" : s.substr(i - 1, 1);

                if (p[j - 1] == '*') {
                    if (isMatch(curs, p.substr(j - 2, 1)))
                        dp[i][j] = (dp[i - 1][j] || dp[i][j - 2]);
                    else
                        dp[i][j] = dp[i][j - 2];
                } else {
                    if (isMatch(curs, p.substr(j - 1, 1)))
                        dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
