//2024-05-04 17:18:37
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.length() - 1, n = num2.length() - 1;
        string res = "";
        int x, y, c = 0, tmp;
        while (m >= 0 || n >= 0 || c) {
            x = m >= 0 ? (num1[m] - '0') : 0;
            y = n >= 0 ? (num2[n] - '0') : 0;
            tmp = x + y + c;
            c = tmp >= 10 ? 1 : 0;
            res.push_back(tmp % 10 + '0');
            m--;
            n--;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
