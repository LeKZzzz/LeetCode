//2023-07-25 21:14:13
#include "../../../../header.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> box;
        vector<int> result_l(boxes.size(), 0);
        vector<int> result_r(boxes.size(), 0);
        vector<int> count_l(boxes.size(), 0);
        vector<int> count_r(boxes.size(), 0);
        vector<int> result;
        for (int i = 0; i < boxes.size(); ++i)
            box.push_back(boxes[i] - '0');


        for (int i = 1; i < boxes.size(); ++i) {
            if (box[i - 1] == 1)
                count_l[i] = count_l[i - 1] + 1;
            else
                count_l[i] = count_l[i - 1];
            result_l[i] = result_l[i - 1] + count_l[i];
        }

        for (int i = boxes.size() - 2; i >= 0; --i) {
            if (box[i + 1] == 1)
                count_r[i] = count_r[i + 1] + 1;
            else
                count_r[i] = count_r[i + 1];
            result_r[i] = result_r[i + 1] + count_r[i];
        }

        for (int i = 0; i < boxes.size(); ++i)
            result.push_back(result_l[i] + result_r[i]);


        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
