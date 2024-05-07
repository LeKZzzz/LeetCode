//2024-05-04 11:16:02
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    bool recur(vector<int> &postorder, int begin, int end) {
        if (begin >= end)
            return true;
        int firstMax = end;
        for (int i = begin; i < end; ++i) {
            if (postorder[i] < postorder[end])
                continue;
            firstMax = i;
            break;
        }
        for (int i = firstMax; i < end; ++i) {
            if (postorder[i] > postorder[end])
                continue;
            return false;
        }
        return recur(postorder, begin, firstMax - 1) && recur(postorder, firstMax, end - 1);
    }

public:
    bool verifyTreeOrder(vector<int> &postorder) {
        return recur(postorder, 0, postorder.size() - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
