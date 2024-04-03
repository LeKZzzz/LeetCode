//2024-03-28 09:41:30
#include "../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findRepeatDocument(vector<int> &documents) {
        int res = 0, n = documents.size();
        for (int i = 0; i < n; ++i) {
            int idx = documents[i] % n;
            documents[idx] += n;
            if (documents[idx] >= (2 * n)) {
                res = idx;
                return res;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
