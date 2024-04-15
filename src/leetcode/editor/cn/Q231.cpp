//2024-04-15 20:59:11
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0 || n&(n-1))
            return false;
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
