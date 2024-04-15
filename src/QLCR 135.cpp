//2024-04-15 21:58:11
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string res;
    char *num;
    int length;
    char chs[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    string countNumbers(int cnt) {
        length = cnt;
        num = new char[cnt];
        dfs(0);
        res=res.substr(0,res.length()-1);
        return res;
    }

    void dfs(int idx) {
        if (idx == length) {
            res = res + num + ',';
            return;
        }
        for (auto ch: chs) {
            num[idx] = ch;
            dfs(idx + 1);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
