//2024-04-17 11:12:24
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        int left, right;
        int maxLen = 0;
        string result;

        for (int length = 2; length <= n; ++length) {
            for (left = 0; left < n; left++) {
                right = left + length - 1;
                if (right >= n) break;
                if (length <= 3) {
                    if (s[left] == s[right])
                        dp[left][right] = true;
                } else {
                    if (s[left] == s[right] && dp[left + 1][right - 1])
                        dp[left][right] = true;
                }

            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] && (j - i + 1) > maxLen) {
                    maxLen = j - i + 1;
                    result = s.substr(i, j - i + 1);
                }
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
