//
// Created by LeK on 2024/4/23.
//

#include "header.h"

int main() {
    string str;
    int curmax_x = 1, curmax_len = 1;

    cin >> str;
    int n = str.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = true;
    }
    for (int length = 2; length <= n; length++) {
        for (int i = 1; i <= n; ++i) {
            int right = i + length - 1;
            if (right > n)
                break;
            if (length <= 3) {
                if (str[i - 1] == str[right - 1]) {
                    dp[i][right] = true;
                    if (length >= curmax_len) {
                        curmax_x = i;
                        curmax_len = length;
                    }
                }
                continue;
            }
            if (str[i - 1] == str[right - 1] && dp[i + 1][right - 1]) {
                dp[i][right] = true;
                if (length >= curmax_len) {
                    curmax_x = i;
                    curmax_len = length;
                }
            }
        }
    }
    cout << str.substr(curmax_x - 1, curmax_len) << endl;
    return 0;
}