//2023-07-23 16:27:21
#include "header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int result=0;
        for (int i = 0; i < operations.size(); ++i) {
            if(operations[i][0]=='+'||operations[i][2]=='+')    result++;
            if(operations[i][0]=='-'||operations[i][2]=='-')    result--;
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
