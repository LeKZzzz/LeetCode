//2024-03-28 13:12:44
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string pathEncryption(string path) {
        string res;
        for (auto ch: path) {
            if (ch == '.')
                res += ' ';
            else
                res += ch;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
